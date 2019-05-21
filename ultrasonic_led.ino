

const int trigPin = 4;
const int echoPin = 5;

long duration;
int distance;

void setup() {
  
pinMode(2,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034/2;
  Serial.print("Distance:");
  Serial.println(distance);
if(distance<20)
{
  digitalWrite(2,HIGH);
}
else if(distance > 40&& distance<60)
{
  digitalWrite(9,HIGH);
}
else if(distance > 60&& distance<100)
{
  digitalWrite(10,HIGH);
}
else 
{
  digitalWrite(11,HIGH);
}

}
