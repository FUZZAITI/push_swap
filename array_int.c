#include "push_swap.h"

int *copy_array(int *arr, int size);
void sort_array(int *arr, int size);
void index_array(int *ori, int *sorted, int size);


int *copy_array(int *arr, int size)
{
    int *copy;
    int i;

    copy = malloc(sizeof(int) * size);
    if (!copy)
        return (NULL);
    i = 0;
    while (i < size)
    {
        copy[i] = arr[i];
        i++;
    }
    return (copy);
}

void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}


void index_array(int *ori, int *sorted, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size && ori[i] != sorted[j])
            j++;

        if (j < size)
            ori[i] = j;

        i++;
    }
}
