const int pinON = 6;

const int pinLeftForward = 11;
const int pinLeftBackward = 12;
const int pinLeftPWM = 10;

const int pinRightForward = 7;
const int pinRightBackward = 8;
const int pinRightPWM = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(pinRightPWM,OUTPUT);
pinMode(pinLeftPWM,OUTPUT);
analogWrite(pinRightPWM,3*51);
analogWrite(pinLeftPWM,3*51);
pinMode(pinON,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
do{}while(digitalRead(pinON) == HIGH);   
digitalWrite(pinRightBackward,HIGH);
digitalWrite(pinLeftBackward,HIGH);

}
