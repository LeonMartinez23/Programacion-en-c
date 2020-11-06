//Suma de binarios de maximo 9 digitos y te devuelve el resulatado en decimal
#include <stdio.h>
#include <stdlib.h>

int main(){

    //Todas las varibles
    int numero,digito,posicion=0,resultado=0;
    int numero2,digito2,posicion2=0,resultado2;
    int vector[]={1,2,4,8,16,32,64,128,256}; //Cantidad maxima de digitos permitidos para el primer binario(9)
    int vector2[]={1,2,4,8,16,32,64,128,256};//Cantidad maxima para el segundo

    printf("Ingrese el primer numero binario: \n");
    scanf("%i",&numero);

    while(numero>0){    //Algoritmo que hace la conversion binaria a decimal del primer binario
        digito=numero%10;
        if(digito==1){
            resultado=resultado+vector[posicion];
        }
        posicion++;
        numero=(numero)/10;
    }
    /////////////-------------Convierte el segundo numero binario a decimal
    printf("Ingrese el segundo numero binario: \n");
    scanf("%i",&numero2);

    while(numero2>0){
        digito2=numero2%10;
        if(digito2==1){
            resultado2=resultado2+vector2[posicion2];
        }
        posicion2++;
        numero2=numero2/10;
    }

    int suma=(resultado)+(resultado2); //Suma el resultado de los 2 binarios para obtener la respuesta en decimal.

    printf("La suma de los binarios en decimal es %i\n",suma);

    return 0;
}
