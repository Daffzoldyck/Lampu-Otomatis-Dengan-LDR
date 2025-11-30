#define ldrPin 2
#define led 7

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int readFromLdr = digitalRead(ldrPin);
  Serial.println(readFromLdr);
  delay(200);

  if (readFromLdr == LOW) {
    digitalWrite(led, HIGH);
    Serial.println("Kondisi Gelap => LED ON");
  } else {
    digitalWrite(led, LOW);
    Serial.println("Kondisi Terang => LED OFF");
  }
}
