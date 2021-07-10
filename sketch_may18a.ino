#include<NewPing.h>
#include <Keypad.h>  /*键盘函数库*/  
 #include<Servo.h>/*舵机函数库*/
 #include"LiquidCrystal_I2C.h"
 LiquidCrystal_I2C lcd(0x27,16,2);
 const byte ROWS=4;                                               
 const byte COLS=4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},                                                     
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
byte colPins[COLS] = {8, 7, 6, 5};    
byte rowPins[ROWS] = {12, 10, 11, 9}; 
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins,ROWS,COLS );

int i,n=0,m;
const int TrigPin=2;
const int EchoPin=3;
Servo s4;
 float dis;
char a[4]={'1','1','1','1'},b[4]={'2','3','4','5'};
void setup() {
  Serial.begin(9600);
 s4.attach(4);
 pinMode(TrigPin,OUTPUT);
 pinMode(EchoPin,INPUT);
  pinMode(A0,OUTPUT);
  pinMode(13,OUTPUT);
 
}

void loop() {
  i=0;
   digitalWrite(13,LOW);
   digitalWrite(A0,LOW);
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW); 
  dis=pulseIn(EchoPin,HIGH)/58.00;
  
  if(0<dis<30)  
    
    {digitalWrite(A0,HIGH);
     digitalWrite(13,HIGH);
      lcd.init();
  lcd.backlight();
   lcd.setCursor(0,0);
   delay(100);
  }
  

   lcd.clear();
 
   
}
