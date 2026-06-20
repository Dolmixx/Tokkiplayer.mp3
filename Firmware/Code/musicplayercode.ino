// libraries
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include <SPI.h>

// LCD
LiquidCrystal lcd(4, 5, 6, 7, 8, A1);

// MFRC522
#define RST 9
#define SDA 10
MFRC522 mfrc522(RST, SDA);

// buttons
#define PAUSE A0
#define PREV A2
#define NEXT A3
#define UP A4
#define DOWN A5

// DFPlayer
#define RX 2
#define TX 3
SoftwareSerial softwareSerial(RX, TX);
DFRobotDFPlayerMini DFPlayer;

// playlists
const String GetUp_playlist[] = {
  "New Jeans", "Super Shy", "ETA", "Cool With You", "Get Up", "ASAP"
};

const String New_Jeans_playlist[] = {
  "Attention", "Hype Boy", "Cookie", "Hurt"
};

const String Singles_playlist[] = {
  "Ditto", "OMG", "Zero", "How Sweet", "Bubble Gum", "Supernatural", "Right Now", "GODS"
};

// RFID storage
byte card1[4];
byte card2[4];
byte card3[4];
bool card1_info = false;
bool card2_info = false;
bool card3_info = false;
bool start = false;

// vars
int playlists = 1;
int tracknum = 1;
int volume = 15;
bool paused = false;
int total = sizeof(GetUp_playlist) / sizeof(GetUp_playlist[0]);

unsigned long debounce = 0;
unsigned long debouncedelay = 50;
unsigned long pauseclick = 0;
bool pausepending = false;
const int doubleclick = 500;

// helper
void playTrack() {
  DFPlayer.playFolder(playlists, tracknum);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Playing: ");
  printname();
}

void printname() {
  lcd.setCursor(0, 1);
  if (playlists == 1) {
    lcd.print(GetUp_playlist[tracknum - 1]);
  } else if (playlists == 2) {
    lcd.print(New_Jeans_playlist[tracknum - 1]);
  } else if (playlists == 3) {
    lcd.print(Singles_playlist[tracknum - 1]);
  }
}

bool uidcheck(byte scanned[], byte saved[]) {
  for (byte i = 0; i < 4; i++) {
    if (scanned[i] != saved[i]) {
      return false;
    }
  }
  return true;
}
// main
void setup() {
  Serial.begin(9600);
  softwareSerial.begin(9600);

  SPI.begin();
  mfrc522.PCD_Init();
  randomSeed(analogRead(A6));

  lcd.begin(16, 2);
  lcd.print("Scan a card!");
  lcd.setCursor(0, 1);

  pinMode(PAUSE, INPUT_PULLUP);
  pinMode(PREV, INPUT_PULLUP);
  pinMode(NEXT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);

  if (DFPlayer.begin(softwareSerial)) {
    DFPlayer.volume(volume);
  }
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() &&
      mfrc522.PICC_ReadCardSerial()) {
    if (!card1_info) {
      memcpy(card1, mfrc522.uid.uidByte, 4);
      card1_info = true;
      lcd.clear();
      lcd.print("Card 1 Saved");
    }
    else if (!card2_info) {
      memcpy(card2, mfrc522.uid.uidByte, 4);
      card2_info = true;
      lcd.clear();
      lcd.print("Card 2 Saved");
    }
    else if (!card3_info) {
      memcpy(card3, mfrc522.uid.uidByte, 4);
      card3_info = true;
      lcd.clear();
      lcd.print("Card 3 Saved");

      start = true;

      delay(1000);
      lcd.clear();
      lcd.print("Ready!");
    }

    else if (start) {
      if (uidcheck(mfrc522.uid.uidByte, card1)) {
        playlists = 1;
        total = sizeof(GetUp_playlist) / sizeof(GetUp_playlist[0]);
        lcd.clear();
        lcd.print("Get Up EP");
      } 
      else if (uidcheck(mfrc522.uid.uidByte, card2)) {
        playlists = 2;
        total = sizeof(New_Jeans_playlist) / sizeof(New_Jeans_playlist[0]);
        lcd.clear();
        lcd.print("New Jeans EP");
      } 
      else if (uidcheck(mfrc522.uid.uidByte, card3)) {
        playlists = 3;
        total = sizeof(Singles_playlist) / sizeof(Singles_playlist[0]);
        lcd.clear();
        lcd.print("Singles");
      }
      tracknum = 1;
      paused = false;
      delay(500);
      playTrack();
    }
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }

  if ((millis() - debounce) > debouncedelay) {
    if (digitalRead(PAUSE) == LOW) {
      if (pausepending && (millis() - pauseclick < doubleclick)) {
        tracknum = random(1, total + 1);
        lcd.clear();
        lcd.print("Shuffling...");
        delay(500);
        playTrack();
        pausepending = false;

      } else {
        pausepending = true;
        pauseclick = millis();
      }
      debounce = millis();
    }

    if (digitalRead(NEXT) == LOW) {
      tracknum ++;
      if (tracknum > total)
        tracknum = 1;
      playTrack();
      debounce = millis();
    }

    if (digitalRead(PREV) == LOW) {
      tracknum --;
      if (tracknum < 1)
        tracknum = total;
      playTrack();

      debounce = millis();
    }

    if (digitalRead(UP) == LOW) {
      if (volume < 30) {
        volume++;
        DFPlayer.volume(volume);
      }
      lcd.clear();
      lcd.print("Volume: ");
      lcd.print(volume);

      debounce = millis();
    }

    if (digitalRead(DOWN) == LOW) {
      if (volume > 0) {
        volume--;
        DFPlayer.volume(volume);
      }
      lcd.clear();
      lcd.print("Volume: ");
      lcd.print(volume);

      debounce = millis();
    }

    if (pausepending &&
        (millis() - pauseclick >= doubleclick)) {
      if (paused) {
        DFPlayer.start();
        paused = false;
        lcd.clear();
        lcd.print("Playing");
      } else {
        DFPlayer.pause();
        paused = true;
        lcd.clear();
        lcd.print("Paused");
      }
      printname();
      pausepending = false;
    }
  }
}