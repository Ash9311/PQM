const int voltage_pin=A0;
const int current_pin=A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float vrms=0;
  float irms=0;
  float power=0;
  float V=0,I=0;
  vrms=analogRead(voltage_pin);
  irms=analogRead(current_pin);
  V=(55.5*vrms)+31.83;
  I=(0.5797*irms)+0.155;
  power=V*I;
  Serial.print("Vrms = ");
  Serial.print(V);
  Serial.print("%\n\n");
  Serial.print("Irms = ");
  Serial.print(I);
  Serial.print("%\n\n");
  Serial.print("Power = ");
  Serial.print(power);
}
