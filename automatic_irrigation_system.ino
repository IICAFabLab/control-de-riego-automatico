#include <Wire.h>
float Ttotal = 1.0;
long long horas = 0.0;
void setup()
{
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(7, OUTPUT);
}
void loop()
{
unsigned long inicio = millis();
if( horas < Ttotal ){
unsigned int riego = analogRead(A0);
float Triego = (float(riego) * 10/1023) * 1000*60;
unsigned int reposo = analogRead(A1);
float Treposo = (float(reposo) * 60/1023) * 1000*60;
unsigned int total = analogRead(A2);
Ttotal = (float(total) * 12/1023) * 1000*3600;
//Activación de la válvula
digitalWrite(7, HIGH);
delay(Triego);
//Desactivación de la válvula
digitalWrite(7, LOW);
delay(Treposo);
}
long long diaCompleto = 86400000UL; // Cálculo de las 24 horas del día (1000*60*60*24)
if( horas > diaCompleto ){
horas = 0;
}
delay(1000);
unsigned long final = millis();
horas = horas + (final-inicio);
}
