//
// Created by redredmaple on 1/2/19.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static ListNode* newListNode(void * elem)
{
    ListNode* l = malloc(sizeof(ListNode));

    l->next = NULL;
    l->val = 0;

    if (elem != NULL){
        l->val = (int)elem;
    }

    return l;
}

//head
ListNode * initList()
{
    return  newListNode(NULL);
}

int lenList(ListNode* node)
{
    int len = 0;
    if (node == NULL){
        return 0;
    }

    ListNode * tmp = node;
    while(tmp->next != NULL){
        ++len;
        tmp = tmp->next;
    }

    return len;
}

int insertList(ListNode * node, int locate, int elem)
{
    if (lenList(node) > locate){
        printf("over boundary\n");
        return 0;
    }

    ListNode * cur = node;
    ListNode * newNode = newListNode((void*)elem);

    if (cur->next == NULL){
        cur->next = newNode;

        return 0;
    }

    while(cur->next != NULL){
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;

    return 1;
}

int destoryList(ListNode *l)
{
   return 0;
}

void prList(ListNode *l)
{
    static int i = 0;
    printf("l%d:", ++i);
    while(l->next != NULL)
    {
        l = l->next;
        printf("%d", l->val);
    }
    printf("\n");
}

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
{
    prList(l1);
    prList(l2);

    ListNode * p1 = l1->next;
    ListNode * p2 = l2->next;
    ListNode * l3 = newListNode(NULL);
    int i = 0;

    while(p1->next != NULL && p2->next != NULL){
        insertList(l3, i++, (p1->val + p2->val)%10);
        p1 = p1->next;
        p2 = p2->next;
    }

    insertList(l3, i++, (p1->val + p2->val)%10);

    prList(l3);

    return l3;
}

