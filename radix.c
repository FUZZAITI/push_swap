#include "push_swap.h"

int max_bits(int size);
void radix_sort(t_stack **a, t_stack **b, int size);


int max_bits(int size)
{
    int bits;

    bits = 0;
    size--; 
    while ((size >> bits) != 0)
        bits++;
    return (bits);
}

void radix_sort(t_stack **a, t_stack **b, int size)
{
    int j;
    int bit;
    int value;

    bit = 0;
    while (bit < max_bits(size))
    {
        j = 0;
        while (j < size)
        {
            value = (*a)->value;
            if (((value >> bit) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        while (*b)
            pa(a, b);
        bit++;
    }
}