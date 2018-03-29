//
//  part1.h
//  lab6
//
//  Created by yuejing zhu on 2017/11/26.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#ifndef part1_h
#define part1_h

#include "part1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Train{
    struct Car * first_car;
};

struct Car{
    int cargo_weight;
    struct Car * next_car;
};

#endif /* part1_h */
