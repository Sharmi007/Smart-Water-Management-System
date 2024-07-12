#define BLYNK_TEMPLATE_ID "TMPL3frpF1Z2L"
#define BLYNK_TEMPLATE_NAME "water level ultrasonic"
#define BLYNK_AUTH_TOKEN "VLIfTHWO2bUOtvbYRYFXKfMVguHWQDqu"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define trig D0 // Trig pin
#define echo D1 
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "GNIT-CA";
char pass[] = "ca@12345";
//int depth =20;

//BlynkTimer timer;
 

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //timer.setInterval(10L, waterlevel);
  pinMode(D2,OUTPUT);
  
}
void loop()
{
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  Blynk.virtualWrite(V0,cm);

  if(cm>10){
  digitalWrite(D2,HIGH);

  }
  else{
  digitalWrite(D2,LOW);
  }
  delay(2000);
  
}