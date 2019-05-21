void setup() {
  Serial.begin(115200);
  pinMode(5,OUTPUT);
  pinMode(36,INPUT);

}

void loop() {
  int t;
  int a = analogRead(36);
  t = a - 273;
  Serial.println(t);
  if(t>=30)
  {
    digitalWrite(5,HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(5,LOW);
    delay(500);  
  }
}
