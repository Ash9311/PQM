#include<LiquidCrystal.h>
#define RS 2
#define EN 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7 
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7); //Let the librarey know how we have connected the LCD

void setup()//method used to run the code for once 
{
  lcd.begin(16, 2);//LCD order
}
  void loop() {

delay(2000);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Vrms: ");
lcd.print(Vrms);
lcd.print("V");

lcd.setCursor(0,1);
lcd.print("Irms: ");
lcd.print(Irms);
lcd.print("A");

delay(2000);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Power: ");
lcd.print(Power);
lcd.print("W");

lcd.setCursor(0,1);
lcd.print("Apparent Power: ");
lcd.print(ApparentPower);
lcd.print("W");

delay(2000);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Real Power: ");
lcd.print(RealPower);
lcd.print("W");

lcd.setCursor(0,1);
lcd.print("Reactive Power: ");
lcd.print(ReactivePower);
lcd.print("W");

delay(2000);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Power Factor: ");
lcd.print(PowerFactor);
lcd.print("");

lcd.setCursor(0,1);
lcd.print("Phase Angle: ");
lcd.print(PhaseAngle);
lcd.print("");

delay(2000);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Total Harmonic Distortion: ");
lcd.print(TotalHarmonicDistortion);
lcd.print("");

  }
