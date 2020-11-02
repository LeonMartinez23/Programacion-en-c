//Encriptcion por el metodo Cesar
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){

    const int k = atoi(argv[1]);    ///Aqui podemos el argumento, es decir la llave de encriptacion

    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(s); i < n; i++){

        if (s[i] >= 'a'&& s[i] <= 'z'){

            printf("%c", s[i] + k);///Aqui es donde dependiendo de la llave que se eliguio como argumento, encripta las palabras
            }
            else
            {
            printf("%c", s[i]);
            }
                }
            printf("\n");
}
