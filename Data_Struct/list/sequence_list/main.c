#include <stdio.h>
#include <E:/VS Code-projects/C/Data_Struct/list/sequence_list/Sequence_list.h>

int main()
{
    List L;
    pList l = &L;
    InitList(l);

    int i;
    for (i = 1; i < 5; i++) {
        if (InsList(l, i, i+1) == -1) {
            printf("表满了！\n");
            break;
        } else if (InsList(l, i, i+1) == -2) {
            printf("位置错误！\n");
            break;
        } else {
            continue;
        }
    }

    int x;
    Elem e;
    printf("请输入需要删除的元素位置 [1~%d]：", l->last+1);
    scanf("%d", &x);

    if (DelList(l, x, &e) == -1) {
        printf("表空！\n");
    } else if (DelList(l, x, &e) == -2) {
        printf("输入位置错误！\n");
    } else {
        printf("成功删除 %d \n", e);
    }

    printf("请输入需要查找的元素：");
    scanf("%d", &e);

    if (Locate(l, e) == -1) {
        printf("表空！\n");
    } else if (Locate(l, e) == -2) {
        printf("没有元素 %d！\n", e);
    } else {
        printf("成功删除 %d \n", e);
    }

    DestroyList(l);
    return 0;
}