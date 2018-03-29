//
//  part1.c
//  lab5
//
//  Created by yuejing zhu on 2017/11/2.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "part1.h"
#include <string.h>

int main(){
    char firstn[30] = {"yuejing"};
    char lastn[30] = {"zhu"};
    char buff[20];
    jedi(firstn, lastn, buff);
    printf("=========partA=========\n");
    printf("%s\n",buff);
    
    printf("=========partB=========\n");
    FILE * fptr = fopen("/Users/yuejingzhu/Desktop/580u/lab5/lab5/File", "a+");
    printf("Please enter a name\n");
    scanf("\n%s  %s",firstn,lastn);
    fputs(firstn, fptr);
    fputs("\t", fptr);
    fputs(lastn, fptr);
    fputs("\n", fptr);
    
    fscanf(fptr, "%s  %s",firstn,lastn);
    fseek(fptr, 0, SEEK_SET);
    printf("\n");
    while (fscanf(fptr, "%s  %s",firstn,lastn) >= 0){
        memset(buff,0,10);
        jedi(firstn, lastn, buff);
        printf("first name:%s  last name:%s  jedi name:%s\n",firstn,lastn,buff);
    }
    
    fclose(fptr);
    
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

char * jedi(char *firstname, char *lastname, char *buffer){
    int i,j;
    
    int last = strlength(lastname);
    int length;
    if(last < jedilastlen){
        length = last;
    }else{
        length = jedilastlen;
    }
    
    for (i = 0; i < length; i++)
    {
        buffer[i] = lastname[i];
    }
    for (j = 0; j < jedifirstlen; j++)
    {
        buffer[i+j] = firstname[j];
    }
    return buffer;
}
