#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include  <stdio.h>



int         main(int arvc, char** argv);
char      **ft_split(const char *s,char c);
size_t      ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	    ft_strlen(const char *s);
long        ft_atol(const char *str);
int         is_num(char **s);
int         is_valid(char **list);
void        error_exit(void);
void        management_error(int i, char **s);
void        free_list(char **lista);
int         has_duplicates(char **nums);
int        *parse_args(int len,char **lista, int *size);
int        *nrb_array(char **list, int is_split);
int        *copy_array(int *arr, int size);
int         count_nums(char **nums);
void        sort_array(int *arr, int size);
void        index_array(int *ori, int *sorted, int size);
int         max_bits(int size);





#endif
