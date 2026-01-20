#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void copy_list(int *origin, int *copy, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        copy[i] = origin[i];
        i++;
    }
}



int is_num(char **s)
{
    int i = 0;
    int j = 0;
    
    while (s[i])
    {
      if (!s[i][j] || !s[i][0])
        return (0);
      if (s[i][j] == '+' || s[i][j] == '-')
        j++;
      if (!s[i][j])
        return (0);
      while (s[i][j])
      {
        if (s[i][j] < '0' || s[i][j] > '9')
            return (0);
        j++;
      }
      j = 0;
      i++;
    }
    return (i);
}

int is_valid(char **list, int *lista_nbr)
{
  int i = 0;
  long result;
  
  while (list[i])
    {
        result = atol(list[i]);
        if (result < INT_MIN || result > INT_MAX)
        {
            printf("%s não é um número no intervalo de int\n", list[i]);
            return (0);
        }
        lista_nbr[i] = (int)result;
        i++;
    }
  return (1);
}

int main(void)
{
    int i;
    char *list[] = {"+42","-9","65","5","659","12", NULL};
    int *lista_nbr;
    int *lista_nbr_copy;
    
    i = is_num(list);
    if (!i)
    {
      printf("valor invalido\n");
      return (0);
    }
    lista_nbr = malloc(sizeof(int) * i);
    if (!lista_nbr)
        return (0);  
    if (!is_valid(list,lista_nbr))
    {
      free(lista_nbr);
      return (0);
    } 
    printf("lista OK\n");
    lista_nbr_copy = malloc(sizeof(int) * i);
    copy_list(lista_nbr, lista_nbr_copy, i);
    return (0);
}
