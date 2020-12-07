#include <E:/VS Code-projects/C/Data_Struct/list/linked_list/linked_list.h>
#include <stddef.h>
#include <stdlib.h>

void InitList(LinkedList *L)
{
	*L = (Node *)malloc(sizeof(Node));
	(*L)->next = NULL;

	return;
}

int ListLength(LinkedList L)
{
	Node *p = L->next;
	int j = 0;

	while (p != NULL) {
		p = p->next;
		j++;
	}

	return j;
}

int CreateFromHead(LinkedList L)
{
	Node *s;
	char c;
	int flag = 1;
	int count = 0;

	while (flag) {
		c = getchar();

		if (c != '$') {
			s = (Node *)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;

			count++;
		} else {
			flag = 0;
		}
	}

	return count;
}

int CreateFromTail(LinkedList L)
{
	Node *r = L;		// r 始终指向 L 尾结点
	Node *s;

	char c;
	int flag = 1;

	int count = 0;

	while (r->next != NULL) {
		r = r->next;
	}

	while (flag) {
		c = getchar();

		if (c != '$') {
			s = (Node *)malloc(sizeof(Node));
			s->data = c;
			s->next = NULL;
			r->next = s;
			r = s;

			count++;
		} else {
			flag = 0;
		}
	}

	return count;
}

Node * GetNodeByOrder(LinkedList L, int n)
{
	int count = 0;
	Node *p = L;

	if (n < 1)
		return NULL;
	
	p = L;
	while (p->next != NULL && count < n) {
		p = p->next;
		count++;
	}

	if (count == n)
		return p;
	else
		return NULL;
}

Node * GetNodeByValue(LinkedList L, Elem key)
{
	Node *p = L->next;

	/**
	 * 1. p == NULL 跳出循环
	 * 2. p->data == key 跳出循环
	 */
	while (p != NULL) {
		if (p->data != key)
			p = p->next;
		else
			break;
	}

	return p;
}

int InsList(LinkedList L, int i, Elem e)
{
	if (i < 1)
		return ERROR;

	Node *p = GetNodeByOrder(L, i-1);		// p 指向 第 i 位置结点的前驱

	if (p == NULL)
		return ERROR;
	else {
		Node *s = (Node *)malloc(sizeof(Node));
		s->data = e;
		
		// 挂链
		s->next = p->next;
		p->next = s;
	}

	return OK;
}

int DelList(LinkedList L, int i, Elem *e)
{
	if (i < 1)
		return ERROR;

	Node *pre = GetNodeByOrder(L, i-1);		// p 指向 第 i 位置结点的前驱

	if (pre == NULL || pre->next == NULL)
		return ERROR;
	else {
		Node *r = pre->next;
		pre->next = r->next;
		*e = r->data;
		free(r);
	}

	return OK;
}

LinkedList Difference_of_a_minus_b(LinkedList LA, LinkedList LB)
{
	LinkedList L = (LinkedList)malloc(sizeof(Node));
	L->next = NULL;

	Node *pre = LA, *p = LA->next;
	Node *q;
	Node *r = NULL;

	while (p != NULL) {
		q = GetNodeByValue(LB, p->data);
		if (q == NULL) {
			r = (Node *)malloc(sizeof(Node));
			r->data = p->data;
			r->next = L->next;
			L->next = r;
		} else {
			pre = p;
			p = pre->next;
		}
	}

	return L;
}

