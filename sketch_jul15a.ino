#include <LiquidCrystal.h>

#include <Wire.h>
LiquidCrystal lcd(0x27, 16, 2);
void setup(){
  lcd.begin();
  lcd.backlight();
  lcd.print("MPCA");
}

void loop(){
  
}