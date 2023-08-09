volatile bool var = LOW;
const int pinLeftForward = 11;
const int pinLeftBackward = 12;
const int pinLeftPWM = 10;
const int pinON = 6;
const int pinRightForward = 7;
const int pinRightBackward = 8;
const int pinRightPWM = 9;

volatile int enc_count_L=0;
volatile int enc_count_R=0;

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
  Serial.begin(9600);
  pinMode(pinON,INPUT_PULLUP);
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),isr1,RISING);
   pinMode(4,INPUT);
  attachInterrupt(digitalPinToInterrupt(4),isr2,RISING);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

enc_count_L=0;
enc_count_R=0;
do{}while(digitalRead(pinON) == HIGH); 
start_up(pinLeftPWM,pinRightPWM);
while(enc_count_L<=2000&&enc_count_R<=1900){
  Rotate180(pinRightForward,pinLeftBackward);
 }
//slow_down(pinLeftPWM,pinRightPWM);
digitalWrite(pinRightForward,LOW);
 digitalWrite(pinLeftBackward,LOW);
 Serial.println(enc_count_L,DEC);
Serial.println(enc_count_R,DEC);
 delay(1000);
enc_count_L=0;
enc_count_R=0;
while(enc_count_L<=1800&&enc_count_R<=1900){
  Rotate180(pinLeftForward,pinRightBackward);
 }
digitalWrite(pinLeftForward,LOW);
digitalWrite(pinRightBackward,LOW);
Serial.println(enc_count_L,DEC);
Serial.println(enc_count_R,DEC);
enc_count_L=0;
enc_count_R=0;

}

void isr1(){
  enc_count_L++;
  }
void isr2(){
  enc_count_R++;
  }
void forward(int LF,int RF){
  digitalWrite(LF,HIGH);
  digitalWrite(RF,HIGH);
}
void start_up(int LPWM,int RPWM){
  analogWrite(RPWM,1*51);
  analogWrite(LPWM,1*51);
  delay(100);
  analogWrite(RPWM,3*51);
  analogWrite(LPWM,3*51);
  delay(100);
  analogWrite(RPWM,5*51);
  analogWrite(LPWM,5*51);
 }
void slow_down(int LPWM,int RPWM){
  analogWrite(RPWM,5*51);
  analogWrite(LPWM,5*51);
  delay(100);
  analogWrite(RPWM,3*51);
  analogWrite(LPWM,3*51);
  delay(100);
  analogWrite(RPWM,1*51);
  analogWrite(LPWM,1*51);
 }
 void Rotate180(int forward,int backward){
  digitalWrite(forward,HIGH);
  digitalWrite(backward,HIGH);
  
  
  }
