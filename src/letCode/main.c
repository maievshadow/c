//
// Created by redredmaple on 1/2/19.
//

#include <stdio.h>

#include "sum.h"
#include "list.h"

void sum_test(int argc, char ** argv)
{
    if (argc < 1){
        printf("Usage:\n");
    }

    int nums[4] = {2, 7, 11, 15};

    pr(nums, 4);
    int * answer = twoSum(nums, 4, 20);
    pr(answer, 2);
}


void list_test(int argc, char ** argv)
{
    //l

    struct ListNode * l1 = initList();
    struct ListNode * l2 = initList();

    insertList(l1, 0, 1);
    insertList(l2, 0, 9);
    insertList(l2, 1, 9);

    struct ListNode * l3 = addTwoNumbers(l1, l2);

    prList(l1);
    prList(l2);
    prList(l3);
}


int main(int argc, char ** argv)
{

    //sum_test(argc, argv);
    list_test(argc, argv);

    return 0;
}


