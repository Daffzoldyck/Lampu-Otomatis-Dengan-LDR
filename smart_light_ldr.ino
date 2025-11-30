#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "Smart Light"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

#define LDRPIN 34
#define LEDPIN 2

bool manualOverride = false;
int ledState = LOW;

BLYNK_WRITE(V1)
{
  manualOverride = true;
  ledState = param.asInt();
  digitalWrite(LEDPIN, ledState);
}

void setup()
{
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LDRPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  if (manualOverride == false) {
    int ldrValue = analogRead(LDRPIN);
    if (ldrValue < 1500) {
      digitalWrite(LEDPIN, HIGH);
    } else {
      digitalWrite(LEDPIN, LOW);
    }
  }
  Blynk.run();
}