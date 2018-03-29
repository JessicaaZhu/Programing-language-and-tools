//
//  part2.h
//  lab5
//
//  Created by yuejing zhu on 2017/11/8.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#ifndef part2_h
#define part2_h

#include <stdio.h>
#include <stdlib.h>
//
#define jedifirstlen 2
#define jedilastlen 3
#define S 30

struct Names{
    char *first_name;
    char *last_name;
    char *jedi_name;
};
int strlength(char *haystack);
char * jedi(struct Names *name);
void * allocate(unsigned int size);
void * deallocate(void *ptr, int size);
int parta(void);




#endif /* part2_h */
