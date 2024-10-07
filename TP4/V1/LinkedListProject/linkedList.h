#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

// 定义一个泛型链表元素类型为 void*
typedef void* Element;

// 定义链表节点结构体
typedef struct Node {
    Element data;        // 链表节点的数据部分
    struct Node* next;   // 链表节点的指向下一个节点的指针
} Node;

// 函数声明
extern Node* createNode(Element data);  // 创建新节点
extern Node* appendNode(Node* head, Element data);  // 在链表末尾添加节点
extern void printList(Node* head, void (*printElement)(Element));  // 打印链表
extern void freeList(Node* head);  // 释放链表占用的内存

#endif // LINKEDLIST_H

