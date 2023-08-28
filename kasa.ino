#include <Wire.h> 
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
                                        //SCL A5 & SDA A4
int trigPin = 3;                        //ultra sonic trig 3
int echoPin = 2;                        //ultra echo trig 2
LiquidCrystal_I2C lcd(0x27, 16, 2);     //VCC(5v) and GND common
int irSen = 12;                         //ir sensor pin 12
Servo myservo;                          //servo VCC 3.3v

void setup()
{
  Serial.begin(9600);
  myservo.attach(7);                    //servo attached at pin 7
  pinMode(irSen, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop()
{ 
  usSen();
	int val = digitalRead(irSen);
  LCD_DISPLAY(val);
  //Serial.println(val);
  //delay(10);
}

void usSen(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration*0.0342/2;
  if(distance < 60){
    lidOpen();
  }
  else{
    lidClose();
  }


}

void lidClose(){
    //Serial.println("close");
    myservo.write(0);
}
void lidOpen(){
    //Serial.println("open");
    myservo.write(120);
  // delay(1000);
}

void LCD_DISPLAY(int val){
  	lcd.begin();
  	lcd.backlight();
    lcd.clear();
    if (val == 0){
      lcd.print("Trash is Full!");
      Serial.println("Trash is Full!");
    }
    else{
      lcd.print("Trash Empty!");
      Serial.println("Trash is Empty!");
    }
    
}
