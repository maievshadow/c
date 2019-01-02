//
// Created by redredmaple on 1/2/19.

//Add Two Numbers

//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example:
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode * initList();

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2);

int destoryList(ListNode *);

int insertList(ListNode *, int, int);

void prList(ListNode *);

int lenList(ListNode *);

//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

#endif //PROJECT_LIST_H
