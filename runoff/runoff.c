#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maximo de votantes y candidatos
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// arreglo de preferencias[i][j] es la preferencia "j" para el votante "i"
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidatos tienen nombre (name), conteo de votos (votes) y estatus de eliminacion (eliminated)
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Arreglo de candidatos
candidate candidates[MAX_CANDIDATES];

// Numero de votantes y candidatos
int voter_count;
int candidate_count;

// Funciones prototipos
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Checa validez de uso
    if (argc < 2)
    {
        printf("Uso: runoff candidate1 candidate2 ...\n");
        return 1;
    }

    // Llenar arreglo de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("El maximo numero de candidatos es %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Numero de votantes: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("El numero maximo de votantes es %i\n", MAX_VOTERS);
        return 3;
    }

    // Continua preguntando por votos
    for (int i = 0; i < voter_count; i++)
    {

        // Pregunta por cada ranking
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Preferencia %i: ", j + 1);

            // Registra voto, excepto cuando es invalido
            if (!vote(i, j, name))
            {
                printf("Voto invalido.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Continua teniendo segundas vueltas hasta que haya ganador
    while (true)
    {
        // Calcular votos para los candidatos que todavia estan en al contienda
        tabulate();

        // Checar si la eleccion ha sido ganada por alguien
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminar al candidato en ultimo lugar
        int min = find_min();
        bool tie = is_tie(min);

        // Si hay empate, todos ganan!
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Elimina a quien tenga menos votos
        eliminate(min);

        // hace un "reset" y regresa el conteo de votos a cero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// registra preferencia si el voto es valido
bool vote(int voter, int rank, string name)
{


   for (int i = 0; i < candidate_count; i++)//Verifica que el candidato exista
    {

        if(strcmp( candidates[i].name,name)==0){
                    preferences[voter][rank] = i;
        return true;
        }

    }return false;


}

// Tabular los votos para los candidatos que no han sido eliminados
void tabulate(void)
{


  for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes += 1;
                break;
            }
        }

    }

    return;
}

// Imprimir al ganador de la eleccion, en caso de que haya uno
bool print_winner(void)
{

    for (int i = 0; i < candidate_count; i++)
    {
        string most = candidates[i].name;
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", most);
            return true;
        }
    }

    return false;
}

// Regresa el minimo numero de votos que cada candidato que queda tiene
int find_min(void)
{
    int minvotes = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < minvotes)
        {
            minvotes = candidates[i].votes;
        }
    }
    return minvotes;
    return 0;
}

// Regresa verdadero (true) si un candidato esta empatado con todos los demas, o falso de lo contrario.
bool is_tie(int min)
{


    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;

}

// Elimina al candidato o candidatos en ultimo lugar
void eliminate(int min)
{

        for (int i = 0; i < candidate_count; i++)
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }

    return;
}