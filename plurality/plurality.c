#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// numero maximo de candidatos
#define MAX 9

// la estructura candidatos tiene nombre (name) y cuenta de votos (votes)
typedef struct
{
    string name;
    int votes;
}
candidate;

// Arreglo de candidatos
candidate candidates[MAX];

// Numero de candidatos
int candidate_count;

// Funcion prototipos
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Checa validez de uso
    if (argc < 2)
    {
        printf("Uso: plurality candidato1 candidato2 ...\n");
        return 1;
    }

    // Llena el arreglo de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Numero maximo de candidatos es %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Numero de votos: ");

    // Loop sobre todos votos
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Voto: ");

        // Checa validez de los votos
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Muestra ganador de la eleccion
    print_winner();
}
// Actualiza los votos totales dado un nuevo voto
bool vote(string name)
{

   for (int i = 0; i < candidate_count; i++)
    {
        if(strcmp( candidates[i].name,name)==0){ ///Compara que uno de los canditatos exista, cuando votamos
                    candidates[i].votes++;
                    return true;
        }

    }return false;

}
/////////////////////////////////////////////////////////////////////////
// Imprime el ganador (o ganadores) de la eleccion
void print_winner(void)
{
   int Nvotos = 0;//Numero de votos iniciando en 0

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > Nvotos)//Evalua el numero de votos
        {
            Nvotos = candidates[i].votes;
        }
    }
    for (int n = 0; n < candidate_count; n++)
    {
        if (candidates[n].votes == Nvotos)//Compara los votos para ver quien coincide con los votos totales
        {
            printf("%s\n", candidates[n].name);
        }
    }
    return;
}
