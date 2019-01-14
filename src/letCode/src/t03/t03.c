//
// Created by redredmaple on 1/3/19.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "t03.h"

#define MAX_LINE 1000
#define MAX_SIZE 256

int inSubString(char * str, char ch)
{
    char * ret = strchr(str, ch);

    if (ret != NULL){
        return 1;
    }

    return 0;
}

int substrcmp(char * str, char *str2)
{
    return strcmp(str, str2);
}

int maxLenStr(char **str, int len)
{
    int i = 0;
    int maxLen = 0;
    char maxStr[MAX_SIZE];
    int curLen = 0;

    strcpy(maxStr,str[0]);

    while(i <= len){
        curLen = strlen(str[i]);
        if (curLen > maxLen){
            maxLen = curLen;
            strcpy(maxStr, str[i]);
        }
        printf("maxLen %d maxStr %s \n", maxLen, maxStr);
        free(str[i]);
        i++;
    }

    //free(str);
    return strlen(maxStr);
}

char * addString(char * s1, char * s2)
{
    while (*s1 != '\0') {
        s1++;
    }
    while ((*s1++ = *s2++) != '\0') {
        ;
    }

    return NULL;
}

char * resetCurLongest(char * str, char ch)
{
    memset(str, 0, sizeof(char)*MAX_SIZE);
    //str[0] = ch;
    //str[1] = '\0';

    return NULL;
}

int lengthOfLongestSubstring(char *s)
{
    int n = strlen(s);
    if (0==n)
        return 0;
    if (1==n)
        return 1;

    int ret = 1;
    int arr[256] = {-1};
    memset(arr, -1, 256*sizeof(int));
    arr[s[0]] = 0;
    int i = 0;
    int j = 1;
    for (;i<n;)
    {
        if (j<n && arr[s[j]]==-1)
        {
            arr[s[j]] = j;
            ret = (ret > j-i+1)?ret:(j-i+1);
            j++;
            if (j==n)
                break;
        }
        else
        {
            int t = arr[s[j]];
            int k;
            for (k=i; k<=t; ++k)
                arr[s[k]] = -1;
            i = t + 1;
        }
    }

    return ret;
}

//@TODO ???????????????????????????
int lengthOfLongestSubstring2(char *str)
{
    char curLongest[MAX_SIZE];
    char * longstr[MAX_LINE];
    char lastLongStr[MAX_SIZE];
    int len = 0;
    char * p1 = str;
    char * p2 = NULL;

    if (strlen(str) <= 1){
        return strlen(str);
    }

    memset(curLongest, 0 ,sizeof(char));
    memset(lastLongStr, 0 ,sizeof(char));

    while( *p1 != '\0') {
        p2 = p1+1;
        while(p2 != '\0'){
            if (inSubString(curLongest, *p2)) {
                if (strlen(lastLongStr) <= strlen(curLongest)){
                    strcpy(lastLongStr, curLongest);
                }
                resetCurLongest(curLongest, *(p2-1));
                break;
            }else{
                char ch[2];
                sprintf(ch, "%c", *p2);
                addString(curLongest, ch);
                p2 = p2 + 1;
            }
        }
        p1 = p1 + 1;
    }

    /*
    longstr[len] = malloc(sizeof(char) * MAX_SIZE);
    strcpy(longstr[len], curLongest);
     */

    if (strlen(lastLongStr) <= strlen(curLongest)){
        strcpy(lastLongStr, curLongest);
    }

    return strlen(lastLongStr);
}

int reverse(int x) {
    int rev[MAX_SIZE] = {0};
    int i = 0;
    int y = 0;
    int ret = 0;

    while (x !=  0){
        y = x % 10;
        x = x / 10;
        rev[i++] = y;
    }

    return ret;
}

void t03(int argc, char ** argv)
{
    //char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNO";
    //char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
    //char str[] = "\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@";

    int len = 0;
    //len = lengthOfLongestSubstring(str);

    reverse(1534236469);
    return;
}