#include "push_swap.h"

int is_num(char **s);
int is_valid(char **list);
int has_duplicates(char **nums);

int is_num(char **s)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
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
    return (1);
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
            return (0);
        i++;   
    }
  return (1);
}

int has_duplicates(char **nums)
{
    int i;
    int j;
    long a;
    long b;

    i = 0;
    while (nums[i])
    {
        a = ft_atol(nums[i]);
        j = i + 1;
        while (nums[j])
        {
            b = ft_atol(nums[j]);
            if (a == b)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

