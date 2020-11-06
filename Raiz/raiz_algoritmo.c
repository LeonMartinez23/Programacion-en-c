//Sacar Raiz cuadrada si usar la funcion "sqrt"
#include<stdio.h>
#include <cs50.h>
int main(void)
{
	double B2;
	double B=0;
	int A = get_int("Numero que le quiere sacar raiz: "); //Pide el numero
	do
	{
		B = B + 0.00001;
		B2= B*B;/*La respuesta tiene que ser un numero que se iguale a A
				(el numero que le pide al usuario), porque sabiendo que la raiz
				tiene que ser un numero que elevado al cuadrado sea
				igual (o menor) para este caso a "A".
				Entonces eso quiere decir que por cada vez que compare A con un numero elevado al cuadrado,
				lo va imprimir en pantalla la respuesta, PORQUE esto lo que hace es
				usar "B" que empieza en "0", y al sumarse poco a poco (por eso esta el +0.00001)
				en un momento dado va encontrar un numero "B" que multiplicado por si mismo (osea al cuadrado)
				sea igual o menor a "A" que es la raiz.*/
	}while (A>=B2);/*Aqui lo que hace el while es hacer
					la comparacion explicada anteriormente, y al se un bucle, estara
					haciendo repetidas veces la suma de "B" mas 0.00001, asta encontrar
					una B que multiplicada por si misma sea aproximada al valor pedido (A)
					por el usuario.*/

	printf ("La raíz cuadrada es %.2f\n",B);/*Ya cuando encuentre un numero "B"
											que multiplicado por si mismo sea equivalente a la raiz,
											simplemente imprime en patanlla la respuesta :v */

}