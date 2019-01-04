//
// Created by redredmaple on 1/3/19.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "t03.h"

int inSubString(char * str, char ch)
{
    while( *str != '\0'){
        if (ch == *str){
            return 1;
        }
    }

    return 0;
}

int maxLenStr(char *ptr[], int len)
{
    int i = 0;
    int maxLen = 0;
    char *maxStr;
    while(i <= len){
        char *cur = ptr[len];
        if (strlen(cur) > maxLen){
            maxLen = strlen(cur);
            strcpy(maxStr, cur);
        }
    }

    printf("the string is %s", maxStr);
    printf("the Len is %d", maxLen);

    return maxLen;
}

//@TODO ???????????????????????????
static int lengthOfLongestSubstring(char *str)
{
    /*
     1:
    char * pstr = malloc(sizeof(char) * 50);
    printf("%s", str);

    while( *str != '\0'){
        *pstr++ = *str++;
    }

    *pstr = '\0';
    printf("%s\n", pstr);

     2:
    char curLongest[50];
    int i = 0;
    while( i <= strlen(str)){
        curLongest[i] = str[i];
        ++i;
    }

    curLongest[i] = '\0';
     1/2 ????????????????????????
    */

    char *curLongest = malloc(sizeof(char)* 50);
    char *longstr[90];
    int len = 0;
    int i = 0;
    while( *str != '\0'){
        if (inSubString(curLongest, *str)) {
            longstr[len] = malloc(sizeof(char)*50);
            //strcpy(curLongest, longstr[len++]); ///???????????????/
            strcpy(longstr[len++], curLongest);
            curLongest[0] = *str;
            curLongest[1] = '\0';
            continue;
        }

        curLongest[i++] = *str;
        curLongest[i++] = '\0';
    }

    maxLenStr(longstr, len);

    return 0;
}

void t03(int argc, char ** argv)
{
    lengthOfLongestSubstring("abcabcbb");
    return;
}