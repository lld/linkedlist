#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int
main()
{
    struct Node *head, *ptr;
    head = (struct Node *)malloc(sizeof(struct Node));//ʹ��֮ǰ������ж�̬�����ڴ�
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
        ptr->next = node;//ָ����һ���ڵ�
        ptr = node;
    }
    ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    while(ptr->next != NULL)
    {
        n = ptr->next;
        printf("%d\n", n->value);
        free(ptr);//ʹ����Ҫ�ͷ��Ѿ�������ڴ�
        ptr = n;
    }
    free(head);//ͷ��㻹û�ͷ�
    return 0;
}
