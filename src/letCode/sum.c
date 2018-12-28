/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.


You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].



Approach 1: Brute Force

The brute force approach is simple. Loop through each element xxx and find if there is another value that equals to target−xtarget - xtarget−x.

Approach 2: Two-pass Hash Table

To improve our run time complexity, we need a more efficient way to check if the complement exists in the array. If the complement exists, we need to look up its index. What is the best way to maintain a mapping of each element in the array to its index? A hash table.

We reduce the look up time from O(n)O(n)O(n) to O(1)O(1)O(1) by trading space for speed. A hash table is built exactly for this purpose, it supports fast look up in near constant time. I say "near" because if a collision occurred, a look up could degenerate to O(n)O(n)O(n) time. But look up in hash table should be amortized O(1)O(1)O(1) time as long as the hash function was chosen carefully.

A simple implementation uses two iterations. In the first iteration, we add each element's value and its index to the table. Then, in the second iteration we check if each element's complement (target−nums[i]target - nums[i]target−nums[i]) exists in the table. Beware that the complement must not be nums[i]nums[i]nums[i] itself!


Approach 3: One-pass Hash Table

It turns out we can do it in one-pass. While we iterate and inserting elements into the table, we also look back to check if current element's complement already exists in the table. If it exists, we have found a solution and return immediately.



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