#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
int melody1[] = {
  NOTE_D3, NOTE_A3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_C3, NOTE_A3, NOTE_D3, NOTE_C3,
  NOTE_D3, NOTE_F3, NOTE_C3, NOTE_A3, NOTE_E3, NOTE_F3,NOTE_G3,NOTE_F3};
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 4, 4, 4, 1
};

#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#define pin 3
#define count 14
Adafruit_NeoPixel strip(count, pin, NEO_GRB + NEO_KHZ800);
Servo servo1;
Servo servo2;
int pot;
int potPos;
int tonez;
int force1;
int force2;
int forceAngle;
int forceKick;
int i;
int butVal;
int freq = 0;// initializing all variables, servos, and neopixel strips.
void setup() {
 Serial.begin(9600);
 strip.begin();
 strip.show();
 servo1.attach(9);
 servo2.attach(10);
 

}

void loop() {
butVal = analogRead(A5);
pot = analogRead(A4);
force1 = analogRead(A0);
force2 = analogRead(A2);
 forceAngle = map(force1,0,1023,0,60);
 forceKick = map(force2, 0, 1023, 0, 45);
 potPos = map(pot,0,1023,0,8);
  Serial.println(potPos);


  servo1.write(forceAngle);
  servo2.write(forceKick);
 
 
  if (potPos == 0) {
  strip.setPixelColor(0,0,0,0);
  strip.setPixelColor(1,0,0,0);
  strip.setPixelColor(2,0,0,0);
  strip.setPixelColor(3,0,0,0);
  strip.setPixelColor(4,0,0,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,0,0,0);
  strip.show();
 }
 if (potPos == 1) {
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,0,0);
  strip.setPixelColor(2,0,0,0);
  strip.setPixelColor(3,0,0,0);
  strip.setPixelColor(4,0,0,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,0,0,0);
  strip.show();
 }
  if (potPos == 2) {
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,0,0,0);
  strip.setPixelColor(3,0,0,0);
  strip.setPixelColor(4,0,0,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,0,0,0);
  strip.show();
 }
  if (potPos == 3) {
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,200,255,0);
  strip.setPixelColor(3,0,0,0);
  strip.setPixelColor(4,0,0,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,0,0,0);
  strip.show();
 }
  if (potPos == 4) {
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,200,255,0);
  strip.setPixelColor(3,200,255,0);
  strip.setPixelColor(4,0,0,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,0,0,0);
  strip.show();
 }
  if (potPos == 5) {
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,200,255,0);
  strip.setPixelColor(3,200,255,0);
  strip.setPixelColor(4,255,255,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,0,0,0);
  strip.show();
 }
  if (forceKick > 10) {
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,200,255,0);
  strip.setPixelColor(3,200,255,0);
  strip.setPixelColor(4,255,255,0);
  strip.setPixelColor(5,255,255,0);
  strip.setPixelColor(6,0,0,0);
  strip.show();
 }
  if (potPos == 7) {
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,200,255,0);
  strip.setPixelColor(3,200,255,0);
  strip.setPixelColor(4,255,255,0);
  strip.setPixelColor(5,255,255,0);
  strip.setPixelColor(6,255,0,0);
  strip.show();
 }
 if (butVal == 1023){

   for (int thisNote = 1; thisNote < 2; thisNote++) {
    servo1.write(forceAngle);

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(6, melody1[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(6);
  }
 } 
 else if( butVal >=990 && butVal <= 1010) {
   for (int thisNote = 3; thisNote < 4; thisNote++) {
    servo1.write(forceAngle);

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(6, melody1[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(6);
   }
 }
 else if( butVal >=505 && butVal <= 515){
     for (int thisNote = 4; thisNote < 5; thisNote++) {
    servo1.write(forceAngle);

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(6, melody1[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(6);

}
 }

noTone(6);
}
