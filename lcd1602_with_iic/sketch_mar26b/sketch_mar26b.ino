//NOTE: Tested on Arduino Uno whose I2C pins are A4==SDA, A5==SCL

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Time.h>

#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  Serial.begin(9600);
 lcd.begin (16,2); //  <<----- My LCD was 16x2

 
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);

  lcd.setCursor(4, 1); 
  lcd.print(timeString());
}

void loop()
{
time_t t = now(); 

  lcd.setCursor(4, 1); 
  lcd.print(timeString());
  
}

String timeString() {
  return printDigits(hour()) + ":" + printDigits(minute()) + ":" + printDigits(second());
}

String printDigits(int digits){
    return digits < 10 ?  "0" + String(digits): String(digits);
}
