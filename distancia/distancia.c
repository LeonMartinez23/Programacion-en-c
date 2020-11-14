//Calcular la distancia entre dos puntos con la condicion de que esten dentro del plano cartesiano
#include <stdio.h>
#include <cs50.h>
#include <math.h>

struct coord{
    float xp;
    float xn;;

};

int main(){

    float x1 = get_float("X1: ");
    float x2 = get_float("x2: ");
    float y1 = get_float("y1: ");
    float y2 = get_float("y2: ");

    struct coord n;//declaro las coordenadas limitantes
    n.xp=100;
    n.xn=-100;

    if(n.xp>=x1 & x1>=n.xn & n.xp>=x2 & x2>=n.xn & n.xp>=y1 & y1>=n.xn & n.xp>=y2 & y2>=n.xn){//Comparo si "x" y "y" estan dentro de los limites

        float xr,yr,xc,yc,s,res;//Declaro las variables para calcular la distancia entre dos puntos
        xr=x2-x1;//**Se puso de esta manera para evitar errores de calculo
        yr=y2-y1;
        xc=xr*xr;
        yc=yr*yr;
        s=xc+yc;
        res=sqrt(s);

        printf("La distancia entre los dos puntos es: %.2f\n",res);//Imprime la respuesta

    }else{
        printf("Las coordenadas estan fuera del plano cartesiano\n");
    }
}