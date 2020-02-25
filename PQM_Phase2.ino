 #include<LiquidCrystal.h>
#define RS PB11
#define EN PB10
#define D4 PA4
#define D5 PA3
#define D6 PA2
#define D7 PA1
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
const int vSensorPin = PA6;
const int cSensorPin = PA7;

const int numberOfSamples =4096;

float sampleV, sampleC;
float voltageV, voltageC;
float instVoltage, instCurrent;

float sumI, sumV, sumP;

float realPower , apparentPower, reactivePower,  powerP ;
float powerFactor, voltageRMS, currentRMS ;

void setup() {
 lcd.begin(16, 2);//LCD order
  Serial.begin(9600);
}

float realpower ;

 

void loop(){
    for(int i=0; i<numberOfSamples; i++)
      {
   sampleV = analogRead(vSensorPin);
      sampleC = analogRead(cSensorPin);

    voltageC = sampleC*3.3/4095.0;
     voltageV = sampleV*3.3/4095.0;

      instCurrent = (voltageC*0.2778)+0.225;
     instVoltage = (77.67*voltageV)+24.1745;
   
     sumV += instVoltage * instVoltage;
      sumI += instCurrent * instCurrent;
     

      sumP += (instVoltage * instCurrent);
      }

      voltageRMS = sqrt(sumV / numberOfSamples);
     currentRMS = sqrt(sumI / numberOfSamples);
       realPower = sumP / numberOfSamples;
       
       powerP = (realPower-00);
   
     apparentPower = (voltageRMS * currentRMS)-7;
           powerFactor =   powerP/apparentPower ;
          reactivePower = sqrt(apparentPower * apparentPower - realPower * realPower);
     /*     if(voltageRMS<30)
          {
            voltageRMS=0;
            currentRMS =0;
            powerP=0;
          }*/

    Serial.println("currentRMS =");
        Serial.println(currentRMS,3); 
     
     Serial.println("voltageRMS =");
         Serial.println(voltageRMS,3);
         
// Serial.println( "ActivePower =");
// Serial.println(  powerP,3);
// 
Serial.println("Power=" );
 Serial.println(apparentPower,3 );
 //delay(5000);
// 
// Serial.println("powerFactor=");
//Serial.println(powerFactor,3);
//delay(1000);
//
// Serial.println("reactivePower=");
//Serial.println(reactivePower);
    sumV = 0;
      sumI = 0;
     sumP = 0;

 //Let the library know how we have connected the LCD


 

delay(2000);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Vrms: ");
lcd.print(voltageRMS);
lcd.print("V");

lcd.setCursor(0,1);
lcd.print("Irms: ");
lcd.print(currentRMS);
lcd.print("A");

delay(2000);
lcd.clear();


lcd.setCursor(1,0);
lcd.print("Power: ");
lcd.print(powerP);
lcd.print("W");

delay(2000);
lcd.clear();

  }
