//
// Created by redredmaple on 1/2/19.
//

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


#ifndef PROJECT_SORTARRAY_H
#define PROJECT_SORTARRAY_H

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

#endif //PROJECT_SUM_H
