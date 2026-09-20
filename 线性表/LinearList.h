/*
 * 线性表.h —— 顺序表（数组实现）的头文件
 *
 * 头文件只放三样东西：
 *   1. 头文件保护（防止同一个头文件被 #include 多次导致重复定义）
 *   2. 类型定义：宏、typedef、结构体
 *   3. 函数声明：只有函数原型，以分号结尾，没有函数体
 * 具体的函数实现写在 线性表.c 里。
 */

#ifndef LINEAR_LIST_H      /* 如果没有定义过这个宏 */
#define LINEAR_LIST_H      /* 就定义它，下面的内容才参与编译 */

#include <stdio.h>
#include <stdlib.h>

/* ---------- 1. 常量 ---------- */
#define MAXSIZE 100        /* 顺序表的最大容量 */
#define OK      1          /* 函数执行成功的返回值 */
#define ERROR   0          /* 失败 */
#define TRUE    1
#define FALSE   0

/* ---------- 2. 类型 ---------- */
typedef int ElemType;      /* 表中元素的类型，以后想存字符/结构体，只改这一行 */
typedef int Status;        /* 函数返回状态，用 OK / ERROR */

/* 顺序表结构体：一块连续的内存 + 一个记录长度的计数器 */
typedef struct {
    ElemType data[MAXSIZE];  /* 存放元素的数组 */
    int      length;         /* 当前实际元素个数（不是 MAXSIZE） */
} SqList;

/* ---------- 3. 基本操作声明 ---------- */
/* 注意：凡是会“改变”表的操作（增、删、初始化），参数都要传 SqList *（指针），
   否则改的是副本，外面的表不会变。只读操作传 SqList 即可。        */

Status InitList(SqList *L);                              /* 初始化：建空表      */
Status DestroyList(SqList *L);                           /* 销毁表              */
Status ClearList(SqList *L);                             /* 清空（length = 0）  */
int    ListEmpty(SqList L);                              /* 判空：空返回 1      */
int    ListLength(SqList L);                             /* 返回元素个数        */
Status GetElem(SqList L, int i, ElemType *e);            /* 取第 i 个元素给 *e  */
int    LocateElem(SqList L, ElemType e);                 /* 查找 e，返回位序（0 表示没找到）*/
Status PriorElem(SqList L, ElemType cur, ElemType *pre); /* 求前驱              */
Status NextElem(SqList L, ElemType cur, ElemType *next); /* 求后继              */
Status ListInsert(SqList *L, int i, ElemType e);         /* 在第 i 个位置插入 e */
Status ListDelete(SqList *L, int i, ElemType *e);        /* 删除第 i 个元素，值给 *e */
void   PrintList(SqList L);                              /* 打印表中所有元素    */

#endif /* LINEAR_LIST_H */