#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int temperature_pin = 0;
int relay_pin = 8;
int ledout_pin = 9;

void setup(){
  pinMode(temperature_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  pinMode(ledout_pin, OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Temperature:");
  lcd.setCursor(0,1); 
}

void loop(){
  int rawvoltage = analogRead(temperature_pin);
  
  float millivolts = (rawvoltage/1024.0) * 5000;
  float celsius = millivolts/10;
  
  lcd.setCursor(0,1); 
  lcd.print(celsius);
  
  if(celsius >= 30.){
    digitalWrite(ledout_pin, HIGH); 
    digitalWrite(relay_pin, HIGH); 
  }else{
    digitalWrite(ledout_pin, LOW);
    digitalWrite(relay_pin, LOW); 
  }
  
  Serial.print(celsius);
  Serial.println(" degrees Celsius");

  //Serial.print((celsius * 9)/5 + 32);
  //Serial.println(" degrees Fahrenheit");
  delay(100);
}
