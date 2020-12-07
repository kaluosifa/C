/**
 * @file linked_list.h
 * @author kaluosifa
 * @brief 单链表
 * @version 0.1
 * @date 2020-12-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define ERROR -1
#define OK 0

/**
 * @brief 存储数据的类型
 * 
 */
typedef char Elem;
typedef struct node {
	Elem data;
	struct node *next;
}Node, *LinkedList;

/**
 * @brief 初始化为空链表
 * 
 * @param L LinkedList
 */
void InitList(LinkedList *L);

/**
 * @brief 求带头结点链表的长度
 * 
 * @param L LinkedList
 * @return int 
 */
int ListLength(LinkedList L);

/**
 * @brief 头插法建表。输入 '$'，停止插入并返回插入的节点个数。
 * 
 * @param L LinkedList
 * @return int 
 */
int CreateFromHead(LinkedList L);

/**
 * @brief 尾插法建表。输入 '$'，停止插入并返回插入的节点个数。
 * 
 * @param L LinkedList
 * @return int 
 */
int CreateFromTail(LinkedList L);

/**
 * @brief 按序号查找结点。找到返回结点，没找到返回NULL。
 * 
 * @param L LinkedList
 * @param n int
 * @return Node* 
 */
Node * GetNodeByOrder(LinkedList L, int n);

/**
 * @brief 按值查找。找到返回结点，没找到返回NULL。
 * 
 * @param L LinkedList
 * @param key Elem
 * @return Node* 
 */
Node * GetNodeByValue(LinkedList L, Elem key);

/**
 * @brief 在第 i 个位置插入数据为 e 的结点。成功返回OK，失败返回ERROR。
 * 
 * @param L LinkedList
 * @param i int
 * @param e Elem
 */
int InsList(LinkedList L, int i, Elem e);

/**
 * @brief 删除第 i 位置结点，并返回其数据。成功返回OK，失败返回ERROR。
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return int 
 */
int DelList(LinkedList L, int i, Elem *e);

/**
 * @brief 求两个集合的差，并返回差的链表。
 * 
 * @param LA LinkedList
 * @param LB LinkedList
 * @return LinkedList 
 */
LinkedList Difference_of_a_minus_b(LinkedList LA, LinkedList LB);
