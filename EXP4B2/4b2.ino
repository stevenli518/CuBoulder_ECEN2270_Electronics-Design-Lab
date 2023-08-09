volatile bool var = LOW;
void setup() {
  // put your setup code here, to run once:
pinMode(5,INPUT);
attachInterrupt(digitalPinToInterrupt(5),isr,RISING);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,var);
}
void isr(){
  var =!var;
  }
