const int pinON = 6;

const int pinLeftForward = 11;
const int pinLeftBackward = 12;
const int pinLeftPWM = 10;

const int pinRightForward = 7;
const int pinRightBackward = 8;
const int pinRightPWM = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(pinON,INPUT_PULLUP);
  pinMode(13,OUTPUT);
/*-----------------------------------------------------*/  
  pinMode(pinRightPWM,OUTPUT);
  
  pinMode(pinRightForward,OUTPUT);
  pinMode(pinRightBackward,OUTPUT);
  
  analogWrite(pinRightPWM,5*51);
  digitalWrite(pinRightForward,LOW);
  digitalWrite(pinRightBackward,LOW);
/*-----------------------------------------------------*/ 
  pinMode(pinLeftPWM,OUTPUT);
  analogWrite(pinLeftPWM,5*51);
  digitalWrite(pinLeftForward,LOW);
  digitalWrite(pinLeftBackward,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_BUILTIN,HIGH);
  do{}while(digitalRead(pinON) == HIGH);
  digitalWrite(LED_BUILTIN,LOW);        
  delay(1000);
  Rotate1(pinRightForward,pinLeftBackward);
  delay(1000);
  Rotate1(pinLeftForward,pinRightBackward);
}
void Rotate1(int forward,int backward){
  digitalWrite(forward,HIGH);
  digitalWrite(backward,HIGH);
  delay(1700);
  digitalWrite(forward,LOW);
  digitalWrite(backward,LOW);
  }
