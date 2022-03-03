#include <iostream>

using namespace std;

//Programa que convierte un arreglo de enteros a un arreglo binario
int main()
{

    //CODIGO DEL TRANSMISOR
    int tam=19, n, num[19]={50,127,13,240,49,89,17,127,170,93,27,127,1,2,3,127,1,1,3};
    int *bin = new int[8*tam];

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

    for (int i=0;i<tam*8;i++) {//Imprime el arreglo (CONTROL)
        cout<<*(bin+i);
        if((i+1)%8==0) cout<<"|";//Separador de bits
    }
    cout<<endl;


    //CODIGO DEL RECEPTOR
    //En el Arduino se debe inicializar un arreglo de la misma longitud tam que se ira llenando de
    //los enteros ya convertidos

    int num_recuperado[19]={0}, potencia=128, test, count=0, sum=0,mean=0; //n
    n=0;
    bool flag=false;

    for (int i=0,j=0;i<tam*8;i++) { //Este ciclo recorre el arreglo binario, simulando la entrada de los datos via serial (se quita en tinkercad)
        test=bin[i]; //control
        n +=bin[i]*potencia;//Los bits entran desde el mas hasta el menos significativo,
        potencia/=2;        //por lo que se multitplican por un numero multiplo de 2 (de acuerdo al numero total de bits, 2^7)
                            //que se dividide en cada iteracion

        if ((i+1)%8==0) { //Cada 8 bits se verifica si el numero convertido es la bandera
            if (flag == true) {
                sum+=n; //Se suman los datos
                //num_recuperado[j]=n;
                //j++;
                count++;
                if (count == 3) {

                    //Para calcular la media y redondear
                    if (10*(sum%3)/3 >= 5) {
                        mean = sum/3+1;
                    }
                    else {
                        mean = sum/3;
                    }

                    num_recuperado[j]=mean;
                    j++;
                    mean=0;
                    sum=0;
                    count=0;
                    flag = false;
                }
            }

            if(n==127){ //Esto simula la salida del circuito de logica combinacional
                flag = true; //Activa una bandera booleana que estara activa 3 bytes
            }

            //Se reinician las variables y se aumenta el contador
            n=0;
            potencia=128;

        }

    }

    for (int i=0;i<tam;i++) {//Imprime el arreglo (CONTROL)
        cout<<num_recuperado[i];
        cout<<"|";//Separador de bits
    }
    cout<<endl;

    delete[] bin;


    return 0;
}
