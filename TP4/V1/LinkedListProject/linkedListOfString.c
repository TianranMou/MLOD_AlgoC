#include <stdio.h>
#include <string.h>
#include "linkedList.h"

// 打印字符串
void printString(Element data) {
    printf("%s ", (char*)data);
}

int main() {
    Node* head = NULL;

    // 向链表中添加字符串
    head = appendNode(head, "Hello");
    head = appendNode(head, "world");
    head = appendNode(head, "from");
    head = appendNode(head, "linked");
    head = appendNode(head, "list!");

    // 打印链表内容
    printList(head, printString);

    // 释放链表内存
    freeList(head);

    return 0;
}

