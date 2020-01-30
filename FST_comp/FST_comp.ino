int ENA =10;
int ENB = 11;
int IN4 = 5;
int IN3 = 4;
int IN2 = 3;
int IN1 = 2;
int RT = 7;
int LT = 8;
int hrt=6;
int hlt=9;
int val1,val2,val11,val22;
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(RT, INPUT);
  pinMode(LT, INPUT);
  pinMode(hrt, INPUT);
  pinMode(hlt, INPUT);
  analogWrite(ENA,70);
  analogWrite(ENB,70);
  Serial.write("Starting!");
}

void loop() {
   val1 = digitalRead(RT); //put the value of right tracker in val1
   val2 = digitalRead(LT); //put the value of left tracker in val2
   val11 = digitalRead(hrt); //put the value of right tracker in val1
   val22 = digitalRead(hlt); //put the value of left tracker in val2


    if((val1==val2))
      Fwd(); 
    if((val1==0)&&(val2==1))
      Left();
    if((val1==1)&&(val2==0))
      Right();
    if((val11==0)&&(val22==1))
      Hard_Left();
    if((val11==1)&&(val22==0))
      Hard_Right();   

}
void Fwd(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Left(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void Hard_Right(){
  Fwd();
delay(80);
Right();
delay(800);
Stop (); 
delay (50);
}
void Hard_Left(){
  Fwd();
delay(80);
Left();
delay(800);
Stop (); 
delay (50);
}
