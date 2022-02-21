// C++ code
//
void setup()
{
  for(int i=4;i<8;i++){
  	pinMode(i, OUTPUT);
  }  
}
int binario[4]={0,0,0,1};
void loop()
{
  digitalWrite(4, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  for(int i=0;i<4;i++){
    
    digitalWrite(5, LOW);
    if(binario[i]==1) digitalWrite(6, HIGH);
    else digitalWrite(6, LOW);
    delay(50);
    digitalWrite(7, HIGH);
    if(i==3) digitalWrite(5, HIGH);
    
    delay(450);
    digitalWrite(7, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(500); 
    
  }
  
}