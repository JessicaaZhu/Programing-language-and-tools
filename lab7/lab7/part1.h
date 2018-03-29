//
//  part1.h
//  lab7
//
//  Created by yuejing zhu on 2017/11/29.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#ifndef part1_h
#define part1_h

#include <stdio.h>
#include <stdlib.h>

struct Data{
    int value;
};

struct Node{
    struct Data * data;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
};

struct Tree{
    struct Node * root;
};
#endif /* part1_h */
