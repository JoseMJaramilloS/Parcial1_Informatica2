void setup()
{
  for(int i=2;i<4;i++){
  	pinMode(i, INPUT);
  } 
  Serial.begin(9600);
}
bool dato=LOW,datoAnterior=LOW;
void loop()
{
  dato=digitalRead(2);
  if(dato==HIGH && datoAnterior==LOW){ //detector de flancos
    //Serial.println("reloj");
  	if(digitalRead(3)==HIGH) Serial.println(1);
    else if(digitalRead(3)==LOW) Serial.println(0);
  }
  datoAnterior==dato;
  //if(digitalRead(3)==HIGH) Serial.println(1);
}