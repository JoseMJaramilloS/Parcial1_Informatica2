int tam=19, n, num[19]={50,127,13,240,49,89,17,127,170,93,27,127,1,2,3,127,1,1,7};
int *bin = new int[8*tam];
int tiempo=50;//variable tiempo que define el periodo del reloj


void setup()
{
  for(int i=4;i<8;i++){
  	pinMode(i, OUTPUT);
  }  
  
  for (int i=0,test=1;i<tam;i++, test++) {
    n=num[i];
    for (int j=7,k=8*test-1;j>-1;j--) {
      if (n%2==0) {
        bin[k]=0; //se empieza a llenar desde la posicion final de la particion de 8 bits
      }
      else{
        bin[k]=1;
      }
      n/=2;
      k--;
    }
  }
  delay(100); //Delay que corrige el atraso generado por la inicializacion del LCD
}

void loop()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  
  
  for(int i=0;i<8*tam;i++){//debe recorrer todo el arreglo
    digitalWrite(5, LOW);
    if(bin[i]==1) digitalWrite(6, HIGH);
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
  
  delete[] bin;
}