//
//  part3.h
//  lab6
//
//  Created by yuejing zhu on 2017/11/28.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#ifndef part3_h
#define part3_h

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
    struct Node * previous;
};

struct List{
    struct Node * head;
};

struct Stack{
    struct List *list;
};
struct Queue{
    struct List *list;
};
#endif /* part3_h */
