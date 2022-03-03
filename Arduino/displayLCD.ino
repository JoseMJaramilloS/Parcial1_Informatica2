/*
  LiquidCrystal Library
  Se usa una pantalla LCD de 16x2: La libreria LiquidCrystal
  para mostrar en ella un arreglo de numeros enteros despues
  de haberlos pasado por un proceso de desencriptacion.

  El circuito:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 8
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 6
 * LCD R/W pin to GND
 * LCD VSS pin to GND
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and GND
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis

 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)

 example added 9 Jul 2009
 by Tom Igoe

 modified 22 Nov 2010
 by Tom Igoe

 modified 7 Nov 2016
 by Arturo Guadalupi
 
 modified 2 Mar 2022
 by Sebastian Garcia

 Este codigo fue tomado y despues modificado de.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld
*/


// include the library code:
#include <LiquidCrystal.h>


// se inicializa la libreria asociada al LCD
// con el pin asociado al arduino y el arreglo a imprimir

int arr[]={11,23,25,14,127,25,23,0,12,13,14,0,0,5,12,0};

const int rs = 12, en = 11, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Se inicia el LCD con el numero de columnas y filas:
  lcd.begin(16, 2);
}

void loop() {
  // Se enciende el scroll automatico
   lcd.autoscroll();
  
  // se posiciona el cursor en (0,0):
  lcd.setCursor(0, 0);
  
  // Imprme un mensaje en el LCD.
  lcd.print("Numeros desencriptados");
  
  // se posiciona el cursor en (0,1):
  lcd.setCursor(0, 1);
  
  // imprime los elementos de la lista separados con espacio:
  for (int i = 0; i < sizeof(arr);i++){
    lcd.print(arr[i]);
    lcd.print(' ');
    delay(200);
  }
  
  // Se apaga el scroll automatico
  lcd.noAutoscroll();
  
  // Se limpia el lcd para el siguiente ciclo
  lcd.clear();

}