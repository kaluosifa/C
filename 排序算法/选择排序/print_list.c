#include "print_list.h"

void PrintList(List head)
{
    head = head->next;
    while (NULL != head) {
        printf("%ld ", head->data);
        head = head->next;
    }
    printf("\n");

    return;
}