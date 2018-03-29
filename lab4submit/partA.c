//
//  partA.c
//  lab4
//
//  Created by yuejing zhu on 2017/10/24.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "partA.h"

int main(){
    char haystack0[] = "apple";char needle0[] = "app";
    char haystack1[] = "orange"; char needle1[] = "ge";
    char haystack2[] = "blueberry";char needle2[] = "ueber";
    char haystack3[] = "strawberry";char needle3[] = "strawberry";
    char haystack4[] = "grapefruit";char needle4[] = "terrible";
    
    char buffer0[20] = {'\0'};
    char buffer1[20] = {'\0'};
    char buffer2[20] = {'\0'};
    char buffer3[20] = {'\0'};
    char buffer4[20] = {'\0'};
    
    int r0 = myStrStr(haystack0, needle0, buffer0);
    printf("haystack: %s needle: %s buffer: %s |same or not: %d\n",haystack0,needle0,buffer0,r0);
    int r1 = myStrStr(haystack1, needle1, buffer1);
    printf("haystack: %s needle: %s buffer: %s |same or not: %d\n",haystack1,needle1,buffer1,r1);
    int r2 = myStrStr(haystack2, needle2, buffer2);
    printf("haystack: %s needle: %s buffer: %s |same or not: %d\n",haystack2,needle2,buffer2,r2);
    int r3 = myStrStr(haystack3, needle3, buffer3);
    printf("haystack: %s needle: %s buffer: %s |same or not: %d\n",haystack3,needle3,buffer3,r3);
    int r4 = myStrStr(haystack4, needle4, buffer4);
    printf("haystack: %s needle: %s buffer: %s |same or not: %d\n",haystack4,needle4,buffer4,r4);
    
    
    return 0;
}

int strlength(char haystack[]){
    
    int i = 0;
    while(haystack[i] != '\0')
    {
        i++;
    }
    return i;
}

int myStrStr (char haystack[], char needle[], char buffer[]){
    int size = strlength(haystack);
    int i = 0, j = 0,k = 0;
    
    while(i < size && j < size && k < size){
        if (haystack[i] != needle[j]) {
            i++;
        }else{
            buffer[k] = haystack[i];
            i++;
            j++;
            k++;
        }
    }
    if (strlength(buffer) > 1) {
        return 1;
    }else{
        return 0;
    }
    
}
    
    

