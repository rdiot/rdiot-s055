/* Mini Infrared PIR Motion Sensor (HC-SR505) [S055] : http://rdiot.tistory.com/81 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int pin = 2;
int count = 0;
int led = 13;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(pin,INPUT);
  pinMode(led,OUTPUT);
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S055:mini PIR");
 
  int val = digitalRead(pin);
 
  lcd.setCursor(0,1);
  lcd.print("val=" + (String)val + "  ");
 
 
  lcd.setCursor(0,2);
  lcd.print("count=" + (String)count + " sec  ");
  
  if(val == 1)
  {
    digitalWrite(led, HIGH);
    count++;
  }
  else
  {
    digitalWrite(led, LOW);
    count = 0;  
  }
  delay(1000);
}
