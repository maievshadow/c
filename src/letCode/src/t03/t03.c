//
// Created by redredmaple on 1/3/19.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "t03.h"

#define MAX_LINE 1000
#define MAX_SIZE 1000

int inSubString(char * str, char ch)
{
    char * ret = strchr(str, ch);

    if (ret != NULL){
        return 1;
    }

    free(ret);

    return 0;
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
        printf("maxLen %d maxStr %s curStr %s, curLen %d \n", maxLen, maxStr, str[i], curLen);
        free(str[i]);
        i++;
    }

    //free(str);
    return strlen(maxStr);
}

//@TODO ???????????????????
char * addString(char * s1, char * s2)
{
    /*
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    if (result == NULL) exit (1);

    strcpy(result, s1);
    strcat(result, s2);
    return result;
    */

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
    memset(str, 0, sizeof(char));
    str[0] = ch;
    str[1] = '\0';

    return NULL;
}

int copyToLongestStr(char *str, int num, char * longest)
{
    return strncpy(longest, str, num);
}


int lengthOfLongestSubstring(char * str)
{
    char *start = str;
    char *end;
    char curLongest[MAX_SIZE];
    char longStr[MAX_SIZE];

    int len = strlen(str);

    if (len <= 1){
        return len;
    }

    while(*start != '\0') {
        end = start + 1;
        while (*end != '\0') {
            if (*end != *start) {
                end++;
            } else{
                break;
            }
        }

        copyToLongestStr(start, end - start, curLongest);

        if (strlen(curLongest) > strlen(longStr)) {
            strcpy(longStr, curLongest);
        }

        start++;
    }

    return strlen(longStr);
}

//@TODO ???????????????????????????
int lengthOfLongestSubstring2(char *str)
{
    //char *curLongest = malloc(sizeof(char) * MAX_SIZE);
    //char ** longstr = malloc(sizeof(char*)*MAX_LINE);
    char curLongest[MAX_SIZE];
    char *longstr[MAX_LINE];
    int len = 0;
    char * pstr = str;
    char * pstr1 = str;
    memset(curLongest, 0 ,sizeof(char));
    while( *pstr != '\0') {
        if (inSubString(curLongest, *pstr)) {
            longstr[len] = malloc(sizeof(char) * MAX_SIZE);
            strcpy(longstr[len++], curLongest);
            resetCurLongest(curLongest, *pstr++);
            continue;
        }

        char ch[2];
        sprintf(ch, "%c", *pstr);
        addString(curLongest, ch);
        pstr++;

        longstr[len] = malloc(sizeof(char) * MAX_SIZE);
        strcpy(longstr[len], curLongest);
    }

    return maxLenStr(longstr, len);
}

void t03(int argc, char ** argv)
{
    char str[MAX_SIZE] = "dvdf";
    int len = 0;
    len = lengthOfLongestSubstring2(str);
    printf("%d\n", len);
    return;
}