#include "data.h"

void CreateData(long size)
{
    FILE *fp = fopen("data.txt", "a");
    if (NULL == fp) {
        exit(-1);
    }
    srand(time(NULL));

    long i = 0;
    while (i < size) {
        fprintf(fp, "%ld ", rand() % size);
        i++;
    }

    fclose(fp);
    return;
}

void GetData(long arr[], long size)
{
    FILE *fp = fopen("data.txt", "r");
    if (NULL == fp) {
        exit(-1);
    }

    long i = 0;
    while (i < size) {
        fscanf(fp, "%ld ", &(arr[i]));
        i++;
    }

    fclose(fp);
    return;
}