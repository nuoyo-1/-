#include <stdio.h>
#define MAXSIZE 20 //初始空间分配量
#define OK 1
#define ERROR 0

typedef int Status; //Status是函数的类型,其值是函数结果状态代码，如OK等

typedef int ElemType; //定义元素类型elemtype作用与int相同 作用：后续想改变表里存储数据的类型比如float或者char等，只需要修改这里的定义即可



typedef struct
{
ElemType data[MAXSIZE]; //顺序表存储空间定义了一个数组
int length; //顺序表当前长度
}SqList; //顺序表类型定义可以像上面的typedef int ElemType一样像平时定义一个类型一样，定义一个顺序表类型SqList L




void InitList(SqList *L) //构造一个空的顺序表L（初始化顺序表L）
{
    L->length = 0;
}




Status ListInsert(SqList *L, int i, ElemType e)// 插入数据    i是第几个元素转换为下标要减去1，e是要插入的元素
{

if(L->length == MAXSIZE) //顺序表已满，不能插入
{
    return ERROR;
}
if(i < 1 || i > L->length + 1) //i值不合法
{
    return ERROR;
}
if(i<= L->length) //若插入数据位置不在表尾，则将插入位置之后的元素后移
{
    for(int j = L->length - 1; j >= i - 1; j--)//负责将插入位置之后的元素后移length-1是因为数组下标从0开始，减去1之后就是下标数，i-1是因为插入位置是第i个元素，数组下标是i-1
    {
        L->data[j + 1] = L->data[j];

    }
}
L->data[i - 1] = e; //将新元素插入
L->length++; //表长增1
return OK;

}






Status ListDelete(SqList *L, int i, ElemType *e) //删除数据
{

    if(L->length == 0) //顺序表为空，不能删除
    {
        return ERROR;
    }
    if(i < 1 || i > L->length) //i值不合法
    {
        return ERROR;
    }
    *e=L->data[i - 1]; //将被删除的元素赋值给e(要知道删除的元素是什么)
    if(i < L->length) //若删除数据位置不在表尾，则将删除位置之后的元素前移
    {
        for(int j = i; j < L->length; j++)//负责将删除位置之后的元素前移
        {
            L->data[j - 1] = L->data[j];//直接前移覆盖掉要删除的元素
        }

    }
    L->length--; //表长减1
    return OK;

}





void ListTraverse(SqList L) //遍历顺序表
{
    for(int i = 0; i < L.length; i++)
    {
        printf("%d %d ",i+1, L.data[i]);
         printf("\n");
    }
   
}






void Continuous_insertion(SqList *L, int n, ElemType e)//连续插入n个元素e
{
for(int i = 0; i < n; i++)
{
    ListInsert(L, L->length + 1, e);
}
}






ElemType GetElem(SqList *L, int i)//获取第i个元素的值
{
    if(i < 1 || i > L->length) //i值不合法
    {
        return ERROR;
    }
    return L->data[i - 1]; //返回第i个元素的值
}




int main()
{
SqList L;//创建一个顺序表L
InitList(&L);//初始化顺序表L

//每次插入的位置都是 length+1，也就是依次追加到表尾
Continuous_insertion(&L, 10, 91 ); //连续插入10个元素91
Continuous_insertion(&L, 10, 78 ); //连续插入10个元素78
printf("插入的位置是否合法：%d\n", ListInsert(&L, 21, 100)); //验证插入位置不合法，返回0")
printf("第五个元素的值是：%d\n", GetElem(&L, 5)); //获取第5个元素的值
ListTraverse(L);//遍历顺序表L

return 0;

}
