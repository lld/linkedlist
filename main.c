#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int
main()
{
    struct Node *head, *ptr;
    head = (struct Node *)malloc(sizeof(struct Node));//使用之前必须进行动态分配内存
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        perror("allocate failed");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    ptr = head;
    int i;
    struct Node *node;
    for (i = 0; i < 6; i++)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        if (node == NULL)
        {
            perror("allocate failed");
            exit(EXIT_FAILURE);
        }
        scanf("%d", &node->value);
        node->next = NULL;
        ptr->next = node;//指向下一个节点
        ptr = node;
    }
    ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    while(ptr->next != NULL)
    {
        n = ptr->next;
        printf("%d\n", n->value);
        free(ptr);//使用完要释放已经分配的内存
        ptr = n;
    }
    free(head);//头结点还没释放
    return 0;
}
