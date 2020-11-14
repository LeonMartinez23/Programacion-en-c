//Calcular la distancia entre dos puntos con la condicion de que esten dentro del plano cartesiano
#include <stdio.h>
#include <cs50.h>
#include <math.h>

struct coord{
    float xp;
    float xn;;

};

float area(float,float,float,float,float,float);

int main(){

    float x1 = get_float("Punto en x1: ");
    float x2 = get_float("Punto en x2: ");
    float x3 = get_float("Punto en x3: ");

    float y1 = get_float("Punto en y1: ");
    float y2 = get_float("Punto en y2: ");
    float y3 = get_float("Punto en y3: ");

    struct coord n;//declaro las coordenadas limitantes
    n.xp=100;
    n.xn=-100;

    if(n.xp>=x1 & x1>=n.xn & n.xp>=x2 & x2>=n.xn & n.xp>=x3 & x3>=n.xn & n.xp>=y1 & y1>=n.xn & n.xp>=y2 & y2>=n.xn & n.xp>=y3 & y3>=n.xn){//Comparo si "a","b" y "c" estan dentro de los limites

    double res = area(x1,x2,x3,y1,y2,y3);//Llamo hablar la funcion

    printf("El area es: %.2f unidades cuadradas\n",res);//Imprimp el resultado

    }else{
        printf("Las coordenadas estan fuera del plano cartesiano\n");
    }
}

float area(float x1,float x2, float x3,float y1,float y2,float y3)
{

return (((x1*y2)+(x2*y3)+(x3*y1)) - ((x1*y3)+(x3*y2)+(x2*y1)))/2; ///Formula empleada para el calculo

}