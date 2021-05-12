#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);
int pir = 6;
int led_kirmizi = 5;
int led_yesil = 4;
int buzz = 3;
int tmp36 = A0;

int hareket;
double sicaklik;
int sensor;

void setup()
{
  pinMode(pir,INPUT);
  pinMode(led_kirmizi,OUTPUT);
  pinMode(led_yesil,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(tmp36,INPUT);

  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  
  hareket = digitalRead(pir);
  sensor = analogRead(tmp36);
  
  sicaklik = (double)sensor/ 1024;       
  sicaklik = sicaklik * 5;                 
  sicaklik = sicaklik - 0.5;               
  sicaklik = sicaklik * 100;
  
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.setCursor(0, 1);
  lcd.print("Sicaklik: ");
  lcd.print(sicaklik);
  lcd.print("c"); 
  if (hareket == HIGH){
    digitalWrite(led_yesil,LOW);
    digitalWrite(led_kirmizi,HIGH);
    digitalWrite(buzz,HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("HAREKET VAR ");
    
   
  }
  else if(hareket == LOW){
    digitalWrite(led_kirmizi,LOW);
    digitalWrite(led_yesil,HIGH);
    digitalWrite(buzz,LOW);
    lcd.setCursor(0, 0);
    lcd.print("HAREKET YOK ");}
  delay(1000);
}