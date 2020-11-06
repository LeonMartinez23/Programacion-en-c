#include <cs50.h>
#include <stdio.h>
int main(void){

printf("Me llamo %s \n",get_string("¿Cual es tu nombre?:\n"));
printf("Tengo %i segundos de edad.\n",get_int("¿Cual es tu edad?:\n")*31536000);

	char c = get_char("¿Cual es tu sexo?\n");

	if (c == 'H' || c == 'h')
	{
		printf("Soy hombre\n");
	}else if (c == 'M' || c == 'm')
	{
		printf("Soy mujer\n");
	}
	float numero = get_float("Escribe un numero:\n"); //Pregunta el precio al cual se le va sacar el IVA
	printf("El numero elevado al cuadrado es: %.2f.\n", numero * numero);//Imprime en pantalla el IVA
}
