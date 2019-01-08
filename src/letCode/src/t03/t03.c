//
// Created by redredmaple on 1/3/19.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "t03.h"

#define MAX_LINE 100
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

    while(i <= len){
        curLen = strlen(str[i]);
        if (curLen > maxLen){
            maxLen = curLen;
            strcpy(maxStr, str[i]);
        }

        free(str[i]);
        i++;
    }

    free(str);
    return strlen(maxStr);
}

//@TODO ???????????????????
char * addString(char * str, char *ch)
{
    int len = strlen(str);
    char * str2 = malloc(sizeof(len + 1));

    strcat(str2, str); //????????????????
    strcat(str2, ch); //???????????????

    return str2;
}

char * resetCurLongest(char * str, char ch)
{
    str[0] = ch;
    str[1] = '\0';

    return str;
}

//@TODO ???????????????????????????
int lengthOfLongestSubstring(char *str)
{
    char *curLongest = malloc(sizeof(char) * MAX_SIZE);
    char ** longstr = malloc(sizeof(char*)*MAX_LINE);
    int len = 0;
    char * pstr = str;
    while( *pstr != '\0') {
        if (inSubString(curLongest, *pstr)) {
            longstr[len] = malloc(sizeof(char) * 50);
            strcpy(longstr[len++], curLongest);
            curLongest = resetCurLongest(curLongest, *pstr++);
            continue;
        }

        char ch[1];
        sprintf(ch, "%c", *pstr);

        char *ch2 = addString(curLongest, ch);
        strcpy(curLongest, ch2); //???????????????
        free(ch2);
        //curLongest = addString(curLongest, ch);
        pstr++;
    }

    longstr[len] = malloc(sizeof(char) * 50);
    strcpy(longstr[len], curLongest);

    free(curLongest);
    return maxLenStr(longstr, len);
}

void t03(int argc, char ** argv)
{
    char * str = "kmtnycpdwdme";
    int len = 0;
    len = lengthOfLongestSubstring(str);
    printf("%d\n", len);
    return;
}