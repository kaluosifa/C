#include <stdlib.h>

#define MAX 10         // 顺序表大小
typedef int Elem;       // 元素类型
typedef struct {
    Elem elem[MAX];
    int last;
}List, *pList;


/**
 * @brief 将顺序表初始化为空表
 * 
 * @param L 
 */
void InitList(pList L);

/**
 * @brief 获取顺序表长度
 * 
 * @param L 
 * @return int 
 */
int ListLength(pList L);

/**
 * @brief 获取表中第 i 个位置的元素，失败返回 -1。
 * 
 * @param L 
 * @param i 
 * @return int 
 */
int GetData(pList L, int i);

/**
 * @brief 在第 i 个位置插入 e；成功返回 0 ，表满返回 -1，位置错误返回 -2。
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return int 
 */
int InsList(pList L, int i, Elem e);

/**
 * @brief 删除第 i 位置元素，并通过 e 返回，成功返回 0，表空返回 -1，位置错误返回 -2。
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return int 
 */
int DelList(pList L, int i, Elem *e);

/**
 * @brief 在表中查找 e，找到返回位置序号，空表返回 -1，查找失败返回 -2。
 * 
 * @param L 
 * @param e 
 * @return int 
 */
int Locate(pList L, Elem e);

/**
 * @brief 销毁表 L 。
 * 
 * @param L 
 * @return int 
 */
void DestroyList(pList L);

/**
 * @brief 将表 L 置空，成功返回 0，失败返回 -1。
 * 
 * @param L 
 * @return int 
 */
void ClearList(pList L);

/**
 * @brief 判断 L 是否为空表，是返回 0，否返回 -1。
 * 
 * @param L 
 * @return int 
 */
int EmptyList(pList L);

/**
 * @brief 判断表满没满，满了返回 0， 没满返回 -1。
 * 
 * @param L 
 * @return int 
 */
int FullList(pList L);