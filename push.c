#include "push_swap.h"
int *parse_args(int len,char **lista);


int *parse_args(int len,char **lista)
{
    char **nuns;
    int   is_split;
   
    is_split = 0;
    if (len == 2)
    {
        nuns = ft_split(lista[1], ' ');
        is_split = 1;
        if (!nuns || !nuns[0])
            management_error(1, nuns);
    }
    else
        nuns = lista + 1;    
    if (!is_num(nuns))
        management_error(is_split, nuns);
    if (!is_valid(nuns))
        management_error(is_split, nuns);
    if (!has_duplicates(nuns))
        management_error(is_split, nuns);
    return (nrb_array(is_split,nuns));                
}



int main(int arvc, char** argv)
{
    int *array_nbr;
    if (arvc < 2)
        return (0);
         
    array_nbr = parse_args(arvc,argv);
    printf("aqui"); 
    
}
