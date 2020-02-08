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
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm;
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
  analogWrite(ENA,80);
  analogWrite(ENB,80);
 
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
   val1 = digitalRead(RT); 
   val2 = digitalRead(LT); 
   val11 = digitalRead(hrt); 
   val22 = digitalRead(hlt); 
  //Serial.print(val2);
   Serial.print(val1);
   Fwd(); 
   /* digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
    cm = (duration/2) / 29.1;     
  //  Serial.println(cm);
   //  if(cm > 26){ 
   if(val1==0 && val2==0&& val11==0 && val22==0)
      Fwd(); 
    if(((val22==1)&&(val2==0)&& val11==0 )|| ( val22==0 && val2==0 && val11==1 && val1==0 ))
      Left();
    if((val1==0 &&  val11==1 && val22==1)||( val22==0 && val2==1 && val11==0 && val1==0))
      Right();*/
    // }
     /*else if(cm<26){
   if(val1==1 && val2==1 && val11==0 && val22==0)
      Fwd(); 
    if(((val22==1)&&(val2==1)&& val11==0 )|| ( val22==0 && val2==1 && val11==0 && val1==0 ))
      Left();
    if((val1==1 &&  val11==1 && val22==0)||( val22==0 && val2==0 && val11==0 && val1==1))
      Right();
    }
*/
   
  
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
