#include "push_swap.h"
int *parse_args(int len,char **lista, int *size);


int *parse_args(int len,char **lista, int *size)
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
    *size = count_nums(nuns);     
    return (nrb_array(nuns,is_split));                
}

int *copy(int *array, int size)
{
    int *copy_nbr;
    copy_nbr = copy_array(array,size);
    if (!copy_nbr)
        error_exit();
    sort_array(copy_nbr,size);
    return (copy_nbr);
}

int main(int argc, char** argv)
{
    int *array_nbr;
    int *sorted;
    int  size;
    
    if (argc < 2)
        return (0);   
    array_nbr = parse_args(argc,argv,&size);
    sorted = copy(array_nbr,size);
    index_array(array_nbr,sorted,size);
    free(sorted);
    

}


