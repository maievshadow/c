#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "sum.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    
    int *answer = malloc(sizeof(int)*2);
    
    for (;i < numsSize; i++)
    {
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

