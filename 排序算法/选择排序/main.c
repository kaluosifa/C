#include "list.h"
#include "print_list.h"
#include "print_array.h"
#include "selection_sort_list.h"
#include "selection_sort_array.h"
#include "data.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	system("chcp 65001");	// 设置控制台编码为UTF-8

    long size = 0, times = 0;
    printf("请输入数据量和测试次数:\n");
    scanf(" %ld %ld", &size, &times);

    // 创建数据
    system("del data.txt");
    CreateData(size);
    // 获取数据和初始化数组
    ElementType *arr = (ElementType *)malloc(sizeof(ElementType)*size);
    GetData(arr, size);

    // 初始化链表
    List head = NULL;
    InitList(&head);

    pNode p = head;
    long i = 0;
    for (; i < size; i++) {
        InsertNode(&p, arr[i]);
    }

    // 开始测试
    time_t t1, t2; 
    double lTimeSum = 0.0, aTimeSum = 0.0;
    for (i = 0; i < times; i++) {
        printf("第%ld次测试：", i+1);
        // 测试链表
        t1 = time(NULL);
        SelectionSortList(head);
        t2 = time(NULL);
        printf("%lfs（链表）\t", difftime(t2, t1));
        lTimeSum += difftime(t2, t1);

        // 测试数组
        t1 = time(NULL);
        SelectionSortArray(arr, size);
        t2 = time(NULL);
        printf("%lfs（数组）\n", difftime(t2, t1));
        aTimeSum += difftime(t2, t1);
    }
    printf("平均耗时：%lfs（链表）\t%lfs（数组）\n", lTimeSum/(double)i, aTimeSum/(double)i);
    system("pause");

    free(arr);
    FreeList(&head);
    return 0;
}