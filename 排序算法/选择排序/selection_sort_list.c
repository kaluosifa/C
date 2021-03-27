#include "selection_sort_list.h"

void SelectionSortList(List head)
{
    pNode pMinNode = NULL;
    pNode pDisorderFirstNode = head->next;
    pNode p = NULL; // 用于遍历的临时指针

    while (NULL != pDisorderFirstNode->next) {
        pMinNode = pDisorderFirstNode;
        p = pDisorderFirstNode->next;
        while (NULL != p) {
            if (p->data < pMinNode->data) {
                pMinNode = p;
            }
            p = p->next;
        }
        ExchangeElementData(pDisorderFirstNode, pMinNode);
        pDisorderFirstNode = pDisorderFirstNode->next;
    }

    return;
}