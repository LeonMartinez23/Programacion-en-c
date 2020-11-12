//Imprime serie de Finonacci
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

    const int n = atoi(argv[1]);    ///Aqui podemos el argumento, es decir asta donde se va imprimir la susecion

    int i,x=0,y=1,z=1; //Declaro las demas variables que se usaran

    printf("1, ");

    for(i=1;i<n;i++){//este ciclo representa la sucesion
        z=x+y;      //Donde se empieza por "la suma de los dos numeros anteriores", asta que el resultado sea menor al argumento.
        x=y;
        y=z;

        printf("%i, ",z);

    } printf("\n");

}
