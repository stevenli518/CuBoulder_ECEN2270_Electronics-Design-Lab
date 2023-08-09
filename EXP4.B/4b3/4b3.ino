volatile bool var = LOW;
const int pinLeftForward = 11;
const int pinLeftBackward = 12;
const int pinLeftPWM = 10;
const int pinON = 6;
const int pinRightForward = 7;
const int pinRightBackward = 8;
const int pinRightPWM = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinRightPWM,OUTPUT);
  pinMode(pinLeftPWM,OUTPUT);
  analogWrite(pinRightPWM,5*51);
  analogWrite(pinLeftPWM,5*51);
  digitalWrite(pinRightForward,LOW);
  digitalWrite(pinRightBackward,LOW);
  digitalWrite(pinLeftForward,LOW);
  digitalWrite(pinLeftBackward,LOW);
  pinMode(pinON,INPUT_PULLUP);
  pinMode(4,INPUT);
  attachInterrupt(digitalPinToInterrupt(4),isr,RISING);
  pinMode(13,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  
digitalWrite(pinRightForward,HIGH);
digitalWrite(pinLeftForward,HIGH);
digitalWrite(13,var);
}
void isr(){
  var =!var;
  }
