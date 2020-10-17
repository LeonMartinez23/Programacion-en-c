//#include <cs50.h>
#include <stdio.h>
#include<stdlib.h>

int main(void){

    char name [20]; //Varibles que se ocuparan
    float age;
    char s;
    int n;

    //Preguntas que se le haran al usuario
    printf("¿Cual es tu Nombre?: \n");
    scanf("%s",name);
    printf("¿Cual es tu edad?: \n");
    scanf("%f",&age);
    printf("¿Cual es tu Sexo?: \n");
    scanf("%s",&s);
    printf("Escriba un numero que se elevara al cuadrado: \n");
    scanf("%i",&n);

    int n2=n*n; //Esto hace que un numero se eleve al cuadrado

    //Imprime en pantalla las respuestas del usuario
    printf("Me llamo: %s\n",name);
    printf("Tengo %0.f",age*31536000);printf(" segundos de vida.\n");

     if(s == 'm' || s == 'M')
    {
        fflush(stdin);
        printf("Soy Mujer\n");
    }else if (s == 'h' || s == 'H')
    {
        printf("Soy Hombre\n");
    }
    printf("El numero al cuadrado es: %i\n",n2);

    return 0;

}