#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// 创建新节点
Node* createNode(Element data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾添加节点
Node* appendNode(Node* head, Element data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// 打印链表
void printList(Node* head, void (*printElement)(Element)) {
    Node* temp = head;
    while (temp != NULL) {
        printElement(temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 释放链表占用的内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

