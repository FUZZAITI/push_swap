#include "push_swap.h"

size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
long ft_atol(const char *str);

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
