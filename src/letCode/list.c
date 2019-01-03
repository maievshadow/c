//
// Created by redredmaple on 1/2/19.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//注意这里表头的原因。一定要注意～

struct ListNode* newListNode()
{
    struct ListNode* l = malloc(sizeof(struct ListNode));

    l->next = NULL;
    l->val = 0;

    return l;
}

//head
struct ListNode * initList()
{
    struct ListNode * l = newListNode(NULL);

    return l;
}

int lenList(struct ListNode* node)
{
    int len = 0;
    if (node == NULL){
        return 0;
    }

    struct ListNode * tmp = node;
    while(tmp->next != NULL){
        ++len;
        tmp = tmp->next;
    }

    return len;
}


int insertList(struct ListNode * node, int locate, int elem)
{
    if (lenList(node) > locate){
        printf("over boundary\n");
        return 0;
    }

    struct ListNode * cur = node;
    struct ListNode * newNode = newListNode();
    newNode->val = elem;

    if (locate == 0 ){
        node->val = elem;
        return 0;
    }

    while(cur->next != NULL){
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;

    return 1;
}

static void adjust(struct ListNode* l)
{
    int elem = 0;
    int nextAdd = 0;
    struct ListNode *p = l;

    while(p != NULL){
        int tmp = p->val;
        elem = tmp % 10 + nextAdd;

        if (tmp >= 10 || elem >= 10){
            nextAdd = 1;
        }else{
            nextAdd = 0;
        }

        p->val = elem % 10;
        p = p->next;
    }

    //@TODO BUG BUG.....

    /*
    [1]
    [9,9]
    Output
    [0,10]
    Expected
    [0,0,1]
    */

    if (nextAdd == 1){
        struct ListNode * newNode = newListNode();
        newNode->val = 1;
        newNode->next = NULL;
        p = l;
        while(p != NULL){
            p = p->next;
        }

        newNode->next = p->next;
        p->next = newNode;
        p->next = newNode;
    }

    return ;
}

static void insert(struct ListNode* l, struct ListNode *h1, struct ListNode *h2, int locate)
{
    int elem = 0;

    if (h1 != NULL && h2 != NULL){
        elem = h1->val + h2->val;
    }else if (h1 != NULL){
        elem = h1->val;
    }else if (h2 != NULL){
        elem = h2->val;
    }

    insertList(l, locate, elem);

    return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode * h1 = l1;
    struct ListNode * h2 = l2;
    struct ListNode * l3 = newListNode();
    int locate = 0;

    //l1 and l2 has the same length;
    while(h1 != NULL && h2 != NULL){
        insert(l3, h1, h2, locate++);
        h1 = h1->next;
        h2 = h2->next;
    }

    while (h1 != NULL){
        insert(l3, h1, NULL, locate++);
        h1 = h1->next;
    }

    while (h2 != NULL){
        insert(l3, NULL, h2, locate++);
        h2 = h2->next;
    }

    adjust(l3);

    return l3;

}

void prList(struct ListNode *l)
{
    static int i = 0;
    printf("l%d:", ++i);
    while(l != NULL)
    {
        printf("%d", l->val);
        l = l->next;
    }
    printf("\n");
}



