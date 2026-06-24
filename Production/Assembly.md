# Assembly + Set Up guide

So you want to make this super cool music player? You're in luck! (When adding each electrical component, ensure you have wired it properly according to the wiring schematic. Moreover, it is advised to wire directly before attaching the specific piece for ease.) 

1. The Arduino
The arduino UNO R3 should sit on the left side of the container. It does not need to be attached to anything as this build does not move around. If you feel inclined to, feel free to use your own methods, but it is not required for this.

<img width="406" height="679" alt="Screenshot 2026-06-20 at 12 28 49 AM" src="https://github.com/user-attachments/assets/690526a7-68c4-43a9-b690-7aa9f8f2fd4d" />


2. MFRC522
This attaches with 4 screws, you will need to attached this "backwards". Don't worry it still works! this just makes it so it is a cleaner design.

<img width="1057" height="592" alt="Screenshot 2026-06-20 at 12 29 16 AM" src="https://github.com/user-attachments/assets/2ad3af67-265a-4d50-96d0-572d8e5e71e2" />

3. DFPlayer
Similar to the arduino, the DFPlayer does not need to be attached to anything except a mini breadboard. Breadboards typically come with adhesive on the back for you to stick it to things. Feel free to sick it to the bottom although that is not needed as stated earlier this build does not move!

<img width="899" height="482" alt="Screenshot 2026-06-20 at 12 29 30 AM" src="https://github.com/user-attachments/assets/dc1a8acf-cb9f-4b08-a7d4-123d2b8d065c" />

Additionally the battery pack can be placed in this spot ontop of the 9V battery if you move the DFPlayer to sit ontop of the arduino. It is reccomended you add this last though! 

<img width="306" height="408" alt="Screenshot 2026-06-20 at 8 27 19 PM" src="https://github.com/user-attachments/assets/c972c105-4692-4d13-8d72-4225065afa5b" />

<img width="286" height="387" alt="Screenshot 2026-06-20 at 7 49 34 PM" src="https://github.com/user-attachments/assets/409f18f1-08e6-4b25-8759-5b888c34a487" />

4. The LCD
It is better to attach the LCD first before attaching the speakers as they may get in the way. Similar to the MFRC522, the LCD also attaches via 4 screws.

<img width="642" height="457" alt="Screenshot 2026-06-20 at 12 31 00 AM" src="https://github.com/user-attachments/assets/ec5019b7-b748-41a5-aaf6-dc8fa899a52b" />

Screw from the outside, for reference on what the outside is, it is pictured below. 

<img width="531" height="244" alt="Screenshot 2026-06-20 at 12 38 22 AM" src="https://github.com/user-attachments/assets/eb9d5306-415c-48cf-8ac1-48faa721d9bf" />

5. The speakers
There are 2 speakers, each with 2 screws to attach. Whether you would like the wired side to face up or down is up to you!

<img width="598" height="339" alt="Screenshot 2026-06-20 at 12 29 55 AM" src="https://github.com/user-attachments/assets/57922907-0694-49a0-864e-d3ee4a6922df" />

<img width="414" height="631" alt="Screenshot 2026-06-20 at 12 30 05 AM" src="https://github.com/user-attachments/assets/708593ec-b2c2-45bb-b260-574b55b83c2e" />

6. The RFID cards and SD card
You may have noticed this build uses RFID! There are 3 openings at the back for you to store those cards. Feel free to decorate the cards if you'd like to match whatever music you want to listen to. (More information on SD card set up below)

<img width="1119" height="679" alt="Screenshot 2026-06-20 at 12 30 26 AM" src="https://github.com/user-attachments/assets/ace1790d-627e-49bf-92fb-c07192927aad" />


7. Buttons
Almost done now! The buttons can be placed into the holes at the front

<img width="1049" height="471" alt="Screenshot 2026-06-20 at 12 31 31 AM" src="https://github.com/user-attachments/assets/353218c1-c2fb-4a74-9b6b-fdbcd89625cf" />

<img width="1092" height="532" alt="Screenshot 2026-06-20 at 12 31 35 AM" src="https://github.com/user-attachments/assets/b4bf188b-c010-4547-8307-707f54afda33" />

after placing them in, place the button covers on top to know which each button does! 

<img width="1183" height="567" alt="Screenshot 2026-06-20 at 12 31 41 AM" src="https://github.com/user-attachments/assets/09db9f7a-3335-47f2-8611-e8c4248fc946" />

The covers should sit snug on the button, NOT touching the 4 smaller circles on each button. To check, press down on each of them gently. 

<img width="391" height="309" alt="Screenshot 2026-06-20 at 12 48 39 AM" src="https://github.com/user-attachments/assets/8d7be062-0862-4797-8b36-ad1efd7616fe" />

8. The lid
This one is self explanatory! Just place the lid on top, the eyes of the creature should look forward!
<img width="788" height="559" alt="Screenshot 2026-06-20 at 12 32 02 AM" src="https://github.com/user-attachments/assets/5dc68001-ebec-45b8-b488-956572ada504" />

Yay! Now you have a music player. 

# SD CARD SET UP

The SD card can be placed directly into the DFPlayer. Ensure you have songs on your SD card formatted properly with 4 digit numbers at the begining and the files be mp3. ie. "0001_Attention" note that this is only if you plan on NOT having multiple playlists. 

If you plan on having up to 3 playlists, put your songs in different files (one file for each playlist) and rename the file "01", "02".. you get the point. The songs should start with a THREE digit number instead of a four digit number. This is because you have placed it in a folder. (There is a file in production that already has a bunch of NewJeans songs downloaded in that MP3 format if you want something to reference off of/are confused!)

Additionally, to customize further if you'd like to have the LCD display the proper titles for your songs, go into the firmware code and look at the 3 playlists. The name of the playlist shouldn't be changed! But the names in the list can be, and feel free to add more as the code will adjust to the amount you add! (But i do reccomend listening to some NewJeans :D) 

Below is what your SD card should look like!

<img width="370" height="140" alt="Screenshot 2026-06-24 at 9 35 53 AM" src="https://github.com/user-attachments/assets/a318102c-50da-4406-91bf-1b142738e669" />

<img width="693" height="171" alt="Screenshot 2026-06-24 at 9 36 10 AM" src="https://github.com/user-attachments/assets/91749881-7d2a-468c-a0d1-c481890b30bc" />

