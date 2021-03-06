#include <E:/VS Code-projects/C/Data_Struct/list/sequence_list/Sequence_list.h>

void InitList(pList L)
{
    L->last = -1;
}

int ListLength(pList L)
{
    return L->last+1;
}

int GetData(pList L, int i)
{
    if (i >= 1 && i <= L->last+1) {
        return L->elem[i-1];
    } else {
        return -1;
    }
}

int InsList(pList L, int i, Elem e)
{
    if (!FullList(L))
        return -1;
    if (!EmptyList(L)) {
        if (i-1 == L->last+1) {
            L->elem[L->last+1] = e;
            L->last++;
        } else {
            return -2;
        }
    } else {
        int x;
        for (x = L->last; x >= i-1; x--) {
            L->elem[x+1] = L->elem[x];
        }
        L->elem[i-1] = e;
        L->last++;
    }

    return 0;
}

int DelList(pList L, int i, Elem *e)
{
    if (!EmptyList(L))
        return -1;
    if (i < 1 || i > L->last+1)
        return -2;
    
    *e = L->elem[i-1];

    int x;
    for (x = i; x <= L->last; x++) {
        L->elem[x-1] = L->elem[x];
    }

    return 0;
}

int Locate(pList L, Elem e)
{
    if (!EmptyList(L))
        return -1;

    int i;
    for (i = 0; i <= L->last; i++) {
        if (L->elem[i] == e)    
            break;
    }

    if (i > L->last)
        return -2;
    else
        return i+1;
}

void DestroyList(pList L)
{
    free(L);
    L = NULL;
}

void ClearList(pList L)
{
    L->last = -1;
}

int EmptyList(pList L)
{
    if (L->last == -1)
        return 0;
    else
        return -1;
}

int FullList(pList L)
{
    if (L->last == MAX-1)
        return 0;
    else
        return -1;
}