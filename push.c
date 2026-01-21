#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

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


void sort_list(int *list, int size)
{
  int i;
  int change;
  int temp;

  change = 1;
  while(change)
  {
    i = 0;
    change = 0;
    while(i < size - 1)
    {
      if (list[i] > list[i +1])
      {
        temp = list[i];
        list[i] = list[i + 1];
        list[i + 1] = temp;
        change = 1;
      }
      i++;
    }
  }
}

int is_num(char **s)
{
    int i = 1;
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
  int i = 1;
  long result;
  int j = 0;
  
  while (list[i])
    {
        result = atol(list[i]);
        if (result < INT_MIN || result > INT_MAX)
        {
            printf("%s não é um número no intervalo de int\n", list[i]);
            return (0);
        }
        lista_nbr[j] = (int)result;
        i++;
        j++;
    }
  return (1);
}

int check_for_duplicates(int *list, int size)
{
  int i; 
  
  i = 0;
  while (i < size - 1)
  {
    if (list[i] == list[i + 1])
    {
      write(2, "duplicidade\n", 12);
      return 0;
    }
    i++;  
  }
  return 1;
}



int main(int argc, char **argv)
{
    int i;
    int *lista_nbr;
    int *lista_nbr_copy;
    
    i = is_num(argv);
    if (!i)
    {
      write(1,"valor invalido\n",15);
      return (0);
    }
    i -= 1;
    lista_nbr = malloc(sizeof(int) * i);
    if (!lista_nbr)
        return (0);  
    if (!is_valid(argv,lista_nbr))
    {
      free(lista_nbr);
      return (0);
    }
    printf("lista OK\n");
    lista_nbr_copy = malloc(sizeof(int) * i);
    copy_list(lista_nbr, lista_nbr_copy, i);
    sort_list(lista_nbr_copy, i);
    check_for_duplicates(lista_nbr_copy, i);
    return (0);
}
