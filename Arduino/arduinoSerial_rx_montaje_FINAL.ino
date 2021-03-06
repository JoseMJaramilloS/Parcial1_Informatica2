#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int tam=19,num_recuperado[19]={0},potencia=128,count=0,sum=0,mean=0,n=0,bin;
int i=0,j=0,k=0,nFlag=0;
bool flag=false;
bool dato=LOW,datoAnterior=LOW;

void setup()
{
  for(int i=2;i<=4;i++){
  	pinMode(i, INPUT);
  } 
  Serial.begin(9600);
  // Se inicia el LCD con el numero de columnas y filas:
  lcd.begin(16, 2);
}


void loop()
{
  dato=digitalRead(2);
  if(dato==HIGH && datoAnterior==LOW){ //detector de flancos
    
    //Serial.println("reloj");
    if(digitalRead(3)==HIGH){
      Serial.print(1);
      bin=1;
    }
    else if(digitalRead(3)==LOW){
      Serial.print(0);
      bin=0;
    }
    
    n +=bin*potencia;//Los bits entran desde el mas hasta el menos significativo,
    potencia/=2;
    
    if ((i+1)%8==0) { //Cada 8 bits se verifica si el numero convertido es la bandera
        if (flag == true) {
          sum+=n; //Se suman los datos
          count++;
          if (count == 3) {

            //Para calcular la media y redondear
            if (10*(sum%3)/3 >= 5) {
              mean = sum/3+1;
            }
            else {
              mean = sum/3;
            }
            Serial.println(" ");
			Serial.print("Media= "); Serial.print(mean);
            num_recuperado[j]=mean;
            j++;
            mean=0;
            sum=0;
            count=0;
            flag = false;
            
          }
        }

          if(digitalRead(4)==HIGH){ //Bandera de la logica combinacional
            flag = true; //Activa una bandera booleana que estara activa 3 bytes
            nFlag++; //variable que cuenta el numero de banderas true

          }

        //Se reinician las variables y se aumenta el contador
        n=0;
        potencia=128;
      	Serial.println(" ");

      }
  i++;
  }
  
  
  if(i>=tam*8){
    int *arreglo_final = new int[nFlag];//Este sera el arreglo final
    
    for (int j=0;j<nFlag;j++) {//Imprime el arreglo (CONTROL)
      arreglo_final[j]=num_recuperado[j];
      Serial.print(arreglo_final[j]);
      Serial.print(",");//Separador de bits
    }
    
    
    //Codigo del LCD
    // Se enciende el scroll automatico
    //lcd.autoscroll();

    // se posiciona el cursor en (0,0):
    lcd.setCursor(0, 0);

    // Imprme un mensaje en el LCD.
    lcd.print("# desencriptados");

    // se posiciona el cursor en (0,1):
    lcd.setCursor(0, 1);

    // imprime los elementos de la lista separados con espacio:
    
    lcd.print(arreglo_final[k]);
    lcd.print(' ');
    delay(500);
    k++;
    if(k==nFlag){
    	k=0;
    }


    // Se apaga el scroll automatico
    //lcd.noAutoscroll();

    // Se limpia el lcd para el siguiente ciclo
    //lcd.clear();
    
    //i=0;
    
    Serial.println(" ");
    delete[] arreglo_final;
  }
  
  
  datoAnterior==dato;
}