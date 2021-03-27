#include "selection_sort_array.h"

void SelectionSortArray(long *arr, long len)
{
    long min = 0;    // 存放最小值的位置序号
    long i, j;   // 计数器
    long tmp;   // 用于交换的临时变量

    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }

        // 将无序数组中的最小值交换到有序数组的末尾
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }

    return;
}