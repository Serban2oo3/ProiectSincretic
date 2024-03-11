#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

const int temperaturaPin = A0; 
Adafruit_LiquidCrystal lcd(0);
const int ledPin = 13;

void setup() {
  pinMode(temperaturaPin, INPUT);  
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);  
  lcd.begin(16, 2);
}

void loop() {
  int temperaturaRaw = analogRead(temperaturaPin);  
  
  
  float temperaturaCelsius = temperaturaRaw * 0.489 - 50; 
  
 
  lcd.setCursor(0, 0); 
  lcd.print("Temp: "); 
  lcd.print(temperaturaCelsius);
  lcd.print(" C");


  if (Serial.available() > 0) {
    char command = Serial.read();
    
    
    if (command == 'A') {
      digitalWrite(ledPin, HIGH);
    } else if (command == 'S') {
      digitalWrite(ledPin, LOW);  
    }
  }
  
  delay(1000);
}
