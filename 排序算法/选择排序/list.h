#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define OK 0
#define ERROR 1

typedef long ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
}Node, *pNode, *List;

/*
 * 功能：交换两个结点的数据域
 */
void ExchangeElementData(pNode node1, pNode node2);

/*
 * 功能：初始化链表指针为带头结点的头指针
 */
int InitList(List *head);

/*
 * 功能：在结点node后插入数据域为data的结点，并让p指向新插入的结点
 */
int InsertNode(pNode *node, ElementType data);

/*
 * 功能：释放链表指针*head所占用的内存
 */
void FreeList(List *head);

#endif