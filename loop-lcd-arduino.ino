// C++ code
// Made by Vander :D
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

char * LargeText = "Hello World     ";

int iLineNumber = 1;
int iCursor = 0; 

void setup()
{
lcd.begin(16,2);
lcd.setCursor(1, 0);
lcd.print("Vander Project:");
}

void loop() 
{
  UpdateLCDDisplay();
  delay(200);
}

void UpdateLCDDisplay()
{
  int iLenofLargeText = strlen(LargeText);
  if (iCursor==(iLenofLargeText - 1))
  {
    iCursor = 0;
  }
  lcd.setCursor(0, iLineNumber);
  if (iCursor < iLenofLargeText - 16)
  {
    for (int iChar = iCursor; iChar < iCursor + 16; iChar++)
    {
      lcd.print(LargeText[iChar]);
    }
  }
  else 
  {
  	for (int iChar = iCursor; iChar < (iLenofLargeText - 1); iChar++)
    {
      lcd.print(LargeText[iChar]);
    }
    
    for (int iChar = 0; iChar <= 16 - (iLenofLargeText - iCursor); iChar++)
    {
      lcd.print(LargeText[iChar]);
    }
  }
  
  iCursor++;
}