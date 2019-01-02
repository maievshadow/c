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
    ListNode * l = initList();
    insertList(l, 0, 2);
    insertList(l, 1, 4);
    insertList(l, 2, 3);

    //l1
    ListNode * l1 = initList();
    insertList(l1, 0, 5);
    insertList(l1, 1, 6);
    insertList(l1, 2, 3);

    //add l and l1
    addTwoNumbers2(l, l1);

}


int main(int argc, char ** argv)
{

    //sum_test(argc, argv);
    list_test(argc, argv);

    return 0;
}


