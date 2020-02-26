void setup() {
  pinMode(A0, INPUT); //analog input potentiometer
  pinMode(A2, INPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}



void loop() {
int potent = analogRead(A0);//read potentiometer
delay(5);
int theForce= analogRead(A2); //read force
delay(5);


//Map potentiometer values
//int newVal = map(potent, potentiometerLow, potentiometerHigh, newLow, newHigh);
int led1Set= map(potent, 0, 1023, 0, 255); 
int led2Set = map(theForce, 300, 1023, 0, 255);
Serial.println(led2Set);
analogWrite(5, led1Set);
if(led2Set > 0) {
analogWrite(9, led2Set);
}
else {
 analogWrite(9, 0);
}

}
