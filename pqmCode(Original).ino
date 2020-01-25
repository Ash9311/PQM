const int vSensorPin = A3;
const int cSensorPin = A0;

const int numberOfSamples =5600;

float sampleV, sampleC;
float voltageV, voltageC;
float instVoltage, instCurrent;

float sumI, sumV, sumP;

float    realPower , apparentPower, reactivePower,  powerP ;
float powerFactor, voltageRMS, currentRMS ;

void setup() {

  Serial.begin(9600);
}

float realpower ;

 

void loop(){
    for(int i=0; i<numberOfSamples; i++)
      {
   sampleV = analogRead(vSensorPin);
      sampleC = analogRead(cSensorPin);

    voltageC = sampleC*5.0/1023.0;
     voltageV = sampleV*5.0/1023.0;

      instCurrent = (voltageC-2.001)/0.1230;
     instVoltage = (voltageV-2.4870)*120.72;
   
     sumV += instVoltage * instVoltage;
      sumI += instCurrent * instCurrent;
     

      sumP += (instVoltage * instCurrent);
      }

      voltageRMS = sqrt(sumV / numberOfSamples);
     currentRMS = sqrt(sumI / numberOfSamples);
       realPower = sumP / numberOfSamples;
       
       powerP = (realPower-00);
   
     apparentPower = voltageRMS * currentRMS;
           powerFactor =   powerP/apparentPower ;
           reactivePower = sqrt(apparentPower * apparentPower - realPower * realPower);

     Serial.println("currentRMS =");
         Serial.println(currentRMS,3); 
     
       Serial.println("voltageRMS =");
          Serial.println(voltageRMS,3);
 Serial.println( "ActivePower =");
 Serial.println(  powerP,3);
 
 Serial.println("apparentPower=" );
 Serial.println( apparentPower,3 );
 
 Serial.println("powerFactor=");
Serial.println(powerFactor,3);
delay(1000);

 Serial.println("reactivePower=");
Serial.println(reactivePower);
    sumV = 0;
      sumI = 0;
     sumP = 0;

 }
