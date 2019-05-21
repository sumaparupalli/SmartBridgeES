
#define LED  5
#define BUTTON 4



void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
}

void loop() {
  int BUTTONSTATE = digitalRead(BUTTON);
  Serial.println(BUTTONSTATE);
  if(BUTTONSTATE == HIGH)
  {
    Serial.println("led off");
    digitalWrite(LED,LOW);
  
}
else
{
  Serial.println("led on");
  digitalWrite(LED,HIGH);
  delay(1000);
}
}
