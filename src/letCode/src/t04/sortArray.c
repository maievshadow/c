#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "sortArray.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int *p = malloc((sizeof(int)* (nums1Size + nums2Size)));
    if (p == NULL){
        return 0;
    }

    printf("%d-%d\n", nums1Size, nums2Size);
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size){
        if (nums1[i] < nums2[j]){
            *(p+k)= nums1[i++];
        }else{
            *(p+k) = nums2[j++];
        }
        ++k;
    }

    while(i<nums1Size){
        p[k++] = nums1[i++];
    }

    while(j<nums2Size){
        p[k++] = nums2[j++];
    }

    i = 0; j = k - 1;
    int mid = i + (j - i) / 2;

    printf("mid %d\n", mid);

    if (mid %2 == 0){
        return *(p+mid -1);
    }else{
        return (*(p+mid -1) + *(p+mid) )/2.0;
    }
}

