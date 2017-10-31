//
//  maiev.h
//  
//
//  Created by maievshabu on 2017/8/30.
//
//

#ifndef maiev_h
#define maiev_h

#include <stdio.h>

void byteOrder(){
    union{
        short value;
        char union_btypes[sizeof (short)];
    }test;
    test.value = 0x0102;
    if ((test.union_btypes[0] == 1 &&
           test.union_btypes[1] == 2)){
        printf("big endian\n");
    }else if ((test.union_btypes[0] == 2 &&
               test.union_btypes[1] == 1)){
        printf("smal endian\n");
    }else{
        printf("unknow\n");
    }
}

#endif /* maiev_h */
