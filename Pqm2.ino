const int Sensor_Pin = A0;
unsigned int Sensitivity = 185;   // 185mV/A for 5A, 100 mV/A for 20A and 66mV/A for 30A Module
float Vpp = 0; // peak-peak voltage 
float Vrms = 0; // rms voltage
float Irms = 0; // rms current
float Supply_Voltage = 233.0;           // reading from DMM
float Vcc = 5.0;         // ADC reference voltage // voltage at 5V pin 
float power = 0;         // power in watt              
float Wh =0 ; // Energy in kWh
float Total Harmonic Distribution = 0;
float Vmax=0;
float Imax=0;
float Power Factor = 0;
float Apparent power = 0;
float Real power = 0;
float phase angle = 0;
unsigned long last_time =0;
unsigned long current_time =0;
unsigned long interval = 100;
unsigned int calibration = 100;  // V2 slider calibrates this
unsigned int pF = 85;           // Power Factor default 95
unsigned int v1=10;
float bill_amount = 0;   // 30 day cost as present energy usage incl approx PF 
unsigned int energyTariff = 8.0; // Energy cost in INR per unit (kWh)

void getACS712() {  // for AC
  Vpp = getVPP();
  Vrms = (Vpp/2.0) *0.707; 
  Vrms = Vrms - (calibration / 10000.0);     // calibtrate to zero with slider
  Vmax = (1.4142)*Vrms;
  Irms = (Vrms * 1000)/Sensitivity ;
  if((Irms > -0.015) && (Irms < 0.008)){  // remove low end chatter
    Irms = 0.0;
  }
  Imax=(1.4142)*Irms;
  power= (Supply_Voltage * Irms) * (pF / 100.0); 
  Apparent Power = (Vrms*Irms);
  Real power =
  Total Harmonic Distortion = [[[sqrt((Vrms-Vrms)(v1*v1))]/(v1)]*100];
  Power Factor = (Real Power)/(Apparent Power);
  Phase Angle = acos(Power Factor);
  last_time = current_time;
  current_time = millis();    
  Wh = Wh+  power *(( current_time -last_time) /3600000.0) ; // calculating energy in Watt-Hour
  bill_amount = Wh * (energyTariff/1000);
  Serial.print("Irms:  "); 
  Serial.print(String(Irms, 3));
  Serial.println(" A");
  Serial.print("Power: ");   
  Serial.print(String(power, 3)); 
  Serial.println(" W"); 
  Serial.print("  Bill Amount: INR"); 
  Serial.println(String(bill_amount, 2));
  Serial.println("Vmax  : ");
  Serial.print(String(  (     ));
  Serial.println("Imax  : ");
  Serial.print(String(  (     ));
  Serial.println("Total Harmonic Distortion  : ");
  Serial.print(String(  (     ));
  Serial.println("Real Power  : ");
  Serial.print(String(  (     ));
  Serial.println("Apparent Power  : ");
  Serial.print(String(  (     ));
  Serial.println("Power Factor  : ");
  Serial.print(String(  (     ));
   Serial.println("Phase Angle  : ");
  Serial.print(String(  (     ));
     
}

float getVPP()
{
  float result; 
  int readValue;                
  int maxValue = 0;             
  int minValue = 1024;          
  uint32_t start_time = millis();
  while((millis()-start_time) < 950) //read every 0.95 Sec
  {
     readValue = analogRead(Sensor_Pin);    
     if (readValue > maxValue) 
     {         
         maxValue = readValue; 
     }
     if (readValue < minValue) 
     {          
         minValue = readValue;
     }
  } 
   result = ((maxValue - minValue) * Vcc) / 1024.0;  
   return result;
 }
 
