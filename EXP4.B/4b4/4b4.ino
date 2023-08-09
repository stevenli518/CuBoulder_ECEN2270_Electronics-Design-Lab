volatile bool var = LOW;
const int pinLeftForward = 11;
const int pinLeftBackward = 12;
const int pinLeftPWM = 10;
const int pinON = 6;
const int pinRightForward = 7;
const int pinRightBackward = 8;
const int pinRightPWM = 9;

volatile int enc_count_L = 0;
volatile int enc_count_R = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinRightPWM, OUTPUT);
  pinMode(pinLeftPWM, OUTPUT);
  analogWrite(pinRightPWM, 5 * 51);
  analogWrite(pinLeftPWM, 5 * 51);
  digitalWrite(pinRightForward, LOW);
  digitalWrite(pinRightBackward, LOW);
  digitalWrite(pinLeftForward, LOW);
  digitalWrite(pinLeftBackward, LOW);

  Serial.begin(9600);
  pinMode(pinON, INPUT_PULLUP);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), isr1, RISING);
  pinMode(4, INPUT);
  attachInterrupt(digitalPinToInterrupt(4), isr2, RISING);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  do {} while (digitalRead(pinON) == HIGH);
  enc_count_L = 0;
  enc_count_R = 0;
  //MoveForward(pinRightForward, pinLeftForward);//enc_L=2710 enc_R=2780 
  Rotate1(pinRightForward, pinLeftBackward);//enc_L = 1435 enc_R = 1490 CW
  //Rotate1(pinLeftForward, pinRightBackward);//enc_l=1495 enc_R = 1517 CC
  
}
void isr1() {
  enc_count_L++;

}
void isr2() {

  enc_count_R++;
}
void MoveForward(int pinLeft, int pinRight) {
  digitalWrite(pinLeft, HIGH);
  digitalWrite(pinRight, HIGH);
  delay(1900);
  digitalWrite(pinLeft, LOW);
  digitalWrite(pinRight, LOW);
}
void Rotate1(int forward, int backward) {
  digitalWrite(forward, HIGH);
  digitalWrite(backward, HIGH);
  delay(1100);
  Serial.println(enc_count_L, DEC);
  Serial.println(enc_count_R, DEC);
  digitalWrite(forward, LOW);
  digitalWrite(backward, LOW);
}
