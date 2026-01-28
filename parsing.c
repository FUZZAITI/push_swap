#include "push_swap.h"

int is_num(char **s);
int is_valid(char **list);
void error_exit(void);

int is_num(char **s)
{
    int i = 1;
    int j = 0;
    
    while (s[i])
    {
      if (!s[i][j] || !s[i][0])
        error_exit();
      if (s[i][j] == '+' || s[i][j] == '-')
        j++;
      if (!s[i][j])
        error_exit();
      while (s[i][j])
      {
        if (s[i][j] < '0' || s[i][j] > '9')
            error_exit();
        j++;
      }
      j = 0;
      i++;
    }
    return (i);
}

int is_valid(char **list)
{
  int i;
  long result;

  i = 0;
  while (list[i])
    {
        result = ft_atol(list[i]);
        if (result < INT_MIN || result > INT_MAX)
            error_exit();
        i++;   
    }
  return (1);
}

void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
