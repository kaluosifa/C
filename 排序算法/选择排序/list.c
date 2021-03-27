#include "list.h"

void ExchangeElementData(pNode node1, pNode node2)
{
    ElementType tmp = node1->data;
    node1->data = node2->data;
    node2->data = tmp;
    return;
}

int InitList(List *head)
{
    *head = (List)malloc(sizeof(Node));
    if (NULL == (*head)) {
        return ERROR;
    }
    (*head)->next = NULL;

    return OK;
}

int InsertNode(pNode *node, ElementType data)
{
    pNode p = (pNode)malloc(sizeof(Node));
    if (NULL == p) {
        return ERROR;
    }
    p->data = data;
    p->next = (*node)->next;
    (*node)->next = p;
    *node = p;

    return OK;
}

void FreeList(List *head)
{
    if (NULL != (*head)->next) {
        FreeList(&((*head)->next));
    }
    free(*head);
    *head = NULL;

    return;
}