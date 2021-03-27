#include "print_array.h"

void PrintArray(long *arr, long len)
{
    long i = 0;

    while (i < len) {
        if (i < len - 1) {
            printf("%ld ", arr[i++]);
        } else {
            printf("%ld\n", arr[i++]);
        }
    }

    return;
}