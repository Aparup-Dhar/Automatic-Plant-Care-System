#include <LiquidCrystal.h>

const int RS = 3, EN = 4, D4 = 8, D5 = 7, D6 = 6, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
  lcd.begin(16, 2);
  pinMode(12,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
    digitalWrite(12,HIGH);

}

void loop()
{

  int w_sen = analogRead(A1);
  int w_val = map(w_sen, 0, 1023, 0, 116);
  
  int m_sen = analogRead(A0);
  int m_val = map(m_sen, 0, 1023, 116, 0);

  if(m_val<25){
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MST lvl: ");
  lcd.setCursor(10,0);
  lcd.print(m_val);
  lcd.setCursor(13,0);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("WTR lvl: ");
  lcd.setCursor(10,1);
  lcd.print(w_val);
  lcd.setCursor(13,1);
  lcd.print("%");

  digitalWrite(12,LOW);
  delay(2000);
  digitalWrite(12,HIGH);
  delay(10000);
  
  }
  else{
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MST lvl: ");
  lcd.setCursor(10,0);
  lcd.print(m_val);
  lcd.setCursor(13,0);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("WTR lvl: ");
  lcd.setCursor(10,1);
  lcd.print(w_val);
  lcd.setCursor(13,1);
  lcd.print("%");
  
  }
   digitalWrite(10,LOW);
  delay(1000);
  digitalWrite(10,HIGH);
  delay(1000);
}