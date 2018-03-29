//
//  part2A.h
//  lab4
//
//  Created by yuejing zhu on 2017/10/26.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#ifndef part2A_h
#define part2A_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TN 8

typedef struct{
    char teamname[20];
    int score;
}Team;

Team * game(Team* team1,Team* team2);
Team * tournament(Team* teams[],int num);
Team * game_partc(Team* team1,Team* team2);
Team * tournament_partc(Team* teams[],int num);
#endif /* part2A_h */
