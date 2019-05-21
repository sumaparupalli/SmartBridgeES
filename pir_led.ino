void setup() {
  Serial.begin(115200);
  pinMode(5,OUTPUT);
  pinMode(4,INPUT);
}

void loop() {
  int PIR = digitalRead(4);
  Serial.println(PIR);
  if(PIR >= 1)
  {
    Serial.println("detected");
    digitalWrite(5,HIGH);
    delay(50);
  
}
else
{
  Serial.println("not detected");
  digitalWrite(5,LOW);
  delay(50);
}
}
