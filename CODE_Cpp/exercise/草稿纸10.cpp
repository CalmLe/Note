#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bookInfo
{
    char name[20]; //书名
	char category[20];//专业领域
	char publish[20];//出版社
    char author[20]; //作者
    double price; //价格
    int num;  //数量
	int existnum; //没有被借走的数量
};

struct Node_bookInfo
{
    struct bookInfo data;
    struct Node_bookInfo* next;
};

struct Node_bookInfo* bookInfo_list = NULL;


 //程序用什么东西处理数据---->容器--->链表
 //数据的结构 ---->图书信息


//创建表头：表头就是一个结构体变量
struct Node_bookInfo* createHead()
{
    //动态申请内存
    struct Node_bookInfo* headNode = (struct Node_bookInfo*)malloc(sizeof(struct Node_bookInfo));
    //变量的基本规则，使用前必须初始化
    headNode->next = NULL;
    return headNode;
}

//创建节点：为插入做准备
//把用户的数据变为结构体变量
struct Node_bookInfo* createNode(struct bookInfo data)
{
    struct Node_bookInfo* newNode = (struct Node_bookInfo*)malloc(sizeof(struct Node_bookInfo));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//插入:头插法
void insertNodeByHead_bookInfo(struct Node_bookInfo* headNode, struct bookInfo data)
{
    struct Node_bookInfo* newNode = createNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

//void insertNodeByTail(struct Node_bookInfo* headNode, struct bookInfo data)
//{
//  struct Node_bookInfo* pMove = headNode;
//  while (pMove->next != NULL)
//  {
//      pMove = pMove->next;
//  }
//  struct Node_bookInfo* newNode = createNode(data);
//  pMove->next = newNode;
//}


void deleteNodeByName_bookInfo(struct Node_bookInfo* headNode, char* bookName)
{
    struct Node_bookInfo* posLeftNode = headNode;
    struct Node_bookInfo* posNode = headNode->next;
    while (posNode != NULL && strcmp(posNode->data.name, bookName))
    {
        posLeftNode = posNode;
        posNode = posLeftNode->next;
    }
    //讨论查询结果
    if (posNode == NULL)
    {
        printf("删除失败\n");
        return;
    }
    else
    {
        printf("删除成功\n");
        posLeftNode->next = posNode->next;
        free(posNode);
        posNode = NULL;
    }
}

//查找
struct Node_bookInfo* searchByName_bookInfo(struct Node_bookInfo* headNode, char* bookName)
{
    struct Node_bookInfo* posNode = headNode->next;
    while (posNode != NULL && strcmp(posNode->data.name, bookName))
    {
        posNode = posNode->next;
    }
    return posNode;
}

//打印链表，从第二节点开始打印
void printList_bookInfo(struct Node_bookInfo* headNode)
{
    struct Node_bookInfo* pMove = headNode->next;
    printf("书名\t价格\t数量\n");
    while (pMove != NULL)
    {
        printf("%s\t %.1f\t%d\n", pMove->data.name, pMove->data.price, pMove->data.num);
        pMove = pMove->next;
    }
}