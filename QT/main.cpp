#include <iostream>

using namespace std;

//Programa que convierte un arreglo de enteros a un arreglo binario
int main()
{

    int tam=11, n, num[11]={49,67,13,240,50,89,17,93,170,127,28};
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
    delete[] bin;


    return 0;
}
