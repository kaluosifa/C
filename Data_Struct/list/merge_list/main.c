#include <stdio.h>
#include <E:/VS Code-projects/C/Data_Struct/list/merge_list/Sequence_list.h>

void Init(pList L);
void MergeList(pList L_1, pList L_2, pList L);
void PrintList(pList L);


int main()
{
	List L_1, L_2, L;
	pList l_1 = &L_1, l_2 = &L_2, l = &L;
	
	Init(l_1);
	Init(l_2);
	InitList(l);

	printf("初始化后 l_1 表：\n");
	PrintList(l_1);
	printf("初始化后 l_2 表：\n");
	PrintList(l_2);
	printf("初始化后 l 表：\n");
	PrintList(l);
	
	MergeList(l_1, l_2, l);

	printf("把 l_1 和 l_2 合并到表 l 后：\n");
	PrintList(l);

	DestroyList(l_1);
	DestroyList(l_2);
	return 0;
}

/**
 * @brief 初始化 L，并赋予简单的元素
 * 
 * @param L pList
 */
void Init(pList L)
{
	InitList(L);

	int i, error;

	for (i = 1; i < 5; i++) {
		error = InsList(L, i, i+1);
		if (error == -1) {
			printf("表满了！\n");
			break;
		} else if (error == -2) {
			printf("位置错误！\n");
			break;
		} else {
			printf("成功在第 %d 位置插入 %d\n", i, i+1);
		}
	}

	return;
}

/**
 * @brief 将 L_1 和 L_2 按从小到大顺序合并到表 L
 * 
 * @param L_1 pLsit
 * @param L_2 pList
 * @param L pList
 * @return int 
 */
void MergeList(pList L_1, pList L_2, pList L)
{
	int i, j;
	i = j = 0;

	while (i <= L_1->last && j <= L_2->last) {
		if (L_1->elem[i] <= L_2->elem[j]) {
			L->elem[++L->last] = L_1->elem[i++];
		} else {
			L->elem[++L->last] = L_2->elem[j++];
		}
	}

	while (i <= L_1->last) {
		L->elem[++L->last] = L_1->elem[i++];
	}

	while (i <= L_2->last) {
		L->elem[++L->last] = L_2->elem[j++];
	}

	return;
}

/**
 * @brief 打印顺序表
 * 
 * @param L pList
 */
void PrintList(pList L)
{
	if (!EmptyList(L)) {
		printf("\n");
		return;
	}

	int i = 0;
	for (i = 0; i < L->last; i++) {
		printf("%d, ", L->elem[i]);
	}
	printf("%d\n", L->elem[i]);
}