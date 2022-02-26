
void setup()
{
  for(int i=4;i<8;i++){
  	pinMode(i, OUTPUT);
  }  
}
int binario[8]={0,0,0,1,0,1,1,0};
void loop()
{
  digitalWrite(4, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  for(int i=0;i<8;i++){//debe recorrer todo el arreglo
    
    digitalWrite(5, LOW);
    if(binario[i]==1) digitalWrite(6, HIGH);
    else digitalWrite(6, LOW);
    delay(50);
    digitalWrite(7, HIGH);
    if((i+1)%4==0) digitalWrite(5, HIGH);//debe ser multiplo de la particion
    
    delay(0.5); //un tiempo muy bajo de reloj, garantiza que solo se tome un dato en el otro arduino
    digitalWrite(7, LOW);
    delay(449.5);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(500); 
    
  }
  
}