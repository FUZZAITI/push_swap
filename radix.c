#include "push_swap.h"

int max_bits(int size);


int max_bits(int size)
{
    int bits;

    bits = 0;
    size--; 
    while ((size >> bits) != 0)
        bits++;
    return (bits);
}