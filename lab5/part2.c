//
//  part2.c
//  lab5
//
//  Created by yuejing zhu on 2017/11/8.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "part2.h"
#include <string.h>


int heap_usage = 0;



int main(){
    printf("=========partA&B=========\n");
    void *ptr = allocate(S);
    printf("allocate address is %p\n",ptr);
    printf("\n");
    deallocate(ptr, S);
    printf("freed address is %p\n",ptr);
    printf("\n");
    ptr = NULL;//why NULL operation must in the main function
    printf("After NULL operation:");
    printf("freed address is %p\n",ptr);
    printf("\n");
    printf("=========partC=========\n");
    parta();
}




int strlength(char *haystack){
    
    int i = 0;
    while(haystack[i] != '\0')
    {
        i++;
    }
    return i;
}


char * jedi(struct Names *name){
    int i,j;
    
    
    int last = strlength(name->last_name);
    int length;
    if(last < jedilastlen){
        length = (int)last;
    }else{
        length = jedilastlen;
    }
    
    for (i = 0; i < length; i++)
    {
        name->jedi_name[i] = name->last_name[i];
    }
    for (j = 0; j < jedifirstlen; j++)
    {
        name->jedi_name[i+j] = name->first_name[j];
    }
    return name->jedi_name;
    
}



void * allocate(unsigned int size){
    
    void * ptr = malloc(size);
    if (ptr == NULL)
    {
        printf("error!\n");
        exit(1);
    }else{
        printf("malloc success!\n");
        heap_usage += size;
        printf("There are %d bytes of memory were allocated, %d bytes of memory are currectly in use\n ",size,heap_usage);
        return ptr;
    }
}

void * deallocate(void *ptr, int size){
    free(ptr);
    heap_usage -= size;
    printf("There are %d bytes of memory were freed, %d bytes of memory are currectly in use\n ",size,heap_usage);
    return NULL;
}

int parta(void){
    
    char *firstn = allocate(S);
    char *lastn = allocate(S);
    char *buff = allocate(S);
    
    FILE * fptr = fopen("File", "a+");
    fseek(fptr, 0, SEEK_SET);
    printf("\n");
    while (fscanf(fptr, "%s  %s",firstn,lastn) >= 0){
        memset(buff,0,S);
        struct Names name = {firstn,lastn,buff};
        jedi(&name);
        printf("first name:%s  last name:%s  jedi name:%s\n",name.first_name,name.last_name,name.jedi_name);
    }
    printf("\n");
    
    deallocate(firstn, S);
    deallocate(lastn, S);
    deallocate(buff, S);
    
    fclose(fptr);
    
    return 0;
    
}


