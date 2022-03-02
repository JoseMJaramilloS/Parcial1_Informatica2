void setup()
{
  for(int i=4;i<8;i++){
  	pinMode(i, OUTPUT);
  }  
}
int binario[24]={0,1,0,1,1,1,1,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1};
int tiempo=500;//variable tiempo que define el periodo del reloj
void loop()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  
  
  for(int i=0;i<24;i++){//debe recorrer todo el arreglo
    digitalWrite(5, LOW);
    if(binario[i]==1) digitalWrite(6, HIGH);
    else digitalWrite(6, LOW);
    delay(tiempo/20);//50
    digitalWrite(7, HIGH);
    if((i+1)%8==0) digitalWrite(5, HIGH);//debe ser multiplo de la particion
    
    delay(0.5); //un tiempo muy bajo de reloj, garantiza que solo se tome un dato en el otro arduino
    digitalWrite(7, LOW);
    delay(tiempo-tiempo/2-tiempo/20-0.5);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(tiempo/2); 
    
    
  }
  
}