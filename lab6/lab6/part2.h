//
//  part2.h
//  lab6
//
//  Created by yuejing zhu on 2017/11/28.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#ifndef part2_h
#define part2_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * previous;
};

struct List{
    struct Node * head;
};
#endif /* part2_h */
