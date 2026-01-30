#include "push_swap.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
long    ft_atol(const char *str);
int     count_nums(char **nums);
int    *nrb_array(char **list, int is_split);

int count_nums(char **nums)
{
    int i;

    i = 0;
    while (nums[i])
        i++;
    return (i);
}

size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t            i;

    i = 0;
    if (dstsize == 0)
        return (ft_strlen(src));
    while (i < dstsize -1 && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

long ft_atol(const char *str)
{
    long res = 0;
    int sign = 1;

    if (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -1;
    while (*str)
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}

int *nrb_array(char **list, int is_split)
{
    int *list_nbr;
    int len;
    int i;

    len = count_nums(list);
    list_nbr = malloc(sizeof(int) * len);
    if (!list_nbr)
    {
        if (is_split)
            free_list(list);
        error_exit();
    }
    i = 0;
    while (i < len)
    {
        list_nbr[i] = (int)ft_atol(list[i]);
        i++;
    }
    if (is_split)
        free_list(list);
    return (list_nbr);
}
