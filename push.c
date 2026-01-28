#include "push_swap.h"

void  parse_args(char **lista)
{
    int i;
    int *lista_nbr;

    i = is_num(lista);
    printf("lista só com numeros e %d\n",i);
    is_valid(lista);
    printf("numeros entre os inteiros\n");
}



int main(int arvc, char** argv)
{
    char **nuns;
    if (arvc < 2)
        error_exit(); 
    if (arvc == 2)
    {
        nuns = ft_split(argv[1], ' ');
        if (!nuns || !nuns[0])
           error_exit();
    }
    else
        nuns = argv + 1;
    parse_args(nuns);
}
