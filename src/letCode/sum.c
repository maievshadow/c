/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.


You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void pr(int *, int);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    
    int *answer = malloc(sizeof(int)*2);
    
    for (;i < numsSize; i++)
    {
        j = i + 1;
        for (j = i + 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                
                answer[0] = i;
                answer[1] = j;

                return answer;
            }
        }   
    }
    
    return NULL;
}


int main(int argc, char ** argv)
{
    if (argc < 1){
        printf("Usage:\n");
    }

    int nums[4] = {2, 7, 11, 15};

    pr(nums, 4);
    int * answer = twoSum(nums, 4, 20);
    pr(answer, 2);
}

void pr(int * answer, int size)
{
    int *ptr = answer;
    if (answer == NULL){
        printf("no answer\n");
        return;
    }

    for(; ptr != answer + size; ptr++)
        printf(" %d ", *ptr);
    printf("\n");
    return;
}