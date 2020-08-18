#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
int i = 0,ranm,x;
int j;
String number,n1,n2,n3,n4;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {10, 11, 12, 13}; 
byte colPins[COLS] = {6, 7, 8, 9}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter OTP:");
   for (int j = 0; j <= 200; j++) {
  ranm = random(1111,9999);
  }
  delay(20000);
  Serial.println(ranm);
} 
void loop() {
  if(i < 4)
  {
  char customKey = customKeypad.getKey();
  if (customKey){
 // Serial.println(customKey);
  lcd.setCursor(i, 1); 
  lcd.print(customKey);
  if(i == 0)
  {
    n1 = customKey;
  }
  if(i == 1)
  {
    n2 = customKey;
  }
   if(i == 2)
  {
    n3 = customKey;
  }
   if(i == 3)
  {
    n4 = customKey;
  }
  
  i= i + 1;
  }
  if (i >= 4)
  {
    number = n1+n2+n3+n4;
    x = number.toInt();
  //  Serial.println(x);
  }
}
if ((x == 1234)||(x == ranm))
{ 
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Password OK");
  lcd.setCursor(2, 1);
  lcd.print("Please Open");
 digitalWrite(5,LOW);
 delay(20000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Enter OTP:");
  digitalWrite(5,HIGH);
  delay(1000);
 x = 0;
 i = 0;
 ranm = random(1111,9999);
 Serial.println(ranm);
}
if ((i == 4)&&((x != 1234)||(x != ranm)))
{ 
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Password Wrong");
 delay(10000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Enter OTP:");
 i = 0;
}
}
