//
//  part2A.c
//  lab4
//
//  Created by yuejing zhu on 2017/10/26.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "part2.h"


int main(int argc, const char * argv[])
{
    
    srand ((int)time(NULL));
    Team *league[8];
    char *name_array[TN] = {"team1","team2","team3","team4","team5","team6","team7","team8"};
    for (int i=0; i<8; i++) {
        Team *team = malloc(sizeof(Team));
        strcpy(team->teamname,name_array[i]);
        team->score = 0;
        league[i] = team;
    }
    
    Team *team1 = league[0];
    Team *team2 = league[1];
    printf("\n====== PartA ====== \n\n");
    game(team1,team2);
    printf("\n====== PartB ====== \n\n");
    
    tournament(league, TN);
    
    printf("\n====== PartC ====== \n\n");
    tournament_partc(league, TN);
    
    
    return 0;
}





Team * game(Team* team1,Team* team2){
   
    int score1 = rand()%10;
    int score2 = rand()%10;
    team1->score = score1;
    team2->score = score2;
    printf("%s vs %s score is %d vs %d\n",team1->teamname,team2->teamname,team1->score,team2->score);    if (score1 > score2) {
        printf("The winner is %s  The score is %d\n",team1->teamname, score1);
        return team1;
    }else{
         printf("The winner is %s  The score is %d\n",team2->teamname, score2);
        return team2;
    }
}

Team * tournament(Team* teams[],int num){
    Team *win_array[num/2];
    if (num == 8) {
        printf("Round:1\n");
    }else if(num == 4){
        printf("Round:2\n");
    }else{
        printf("Round:3\n");
    }
    for (int i=0; i < num/2; i++) {
        Team *first_team = teams[i*2];
        Team *second_team = teams[i*2+1];
    
        Team * winner = game(first_team,second_team);
        win_array[i] = winner;
      //  printf("%s %s %s\n",first_team->teamname, second_team->teamname, winner->teamname);
        
        
        printf("\n");
        if (num == 2) {
            //_round = 0;
            Team *winner = win_array[0];
            printf("%s is the winner!\n",winner->teamname);
            return winner;
        }
    }
       return tournament(win_array, num/2);
}

Team * game_partc(Team* team1,Team* team2){
    
    int score1 = rand()%10;
    int score2 = rand()%10;
    
    int hadicap1 = rand()%10;
    int hadicap2 = rand()%10;
    
    team1->score = score1+hadicap1;
    team2->score = score2+hadicap2;
    printf("%s handicap is %d,%s hadicap is %d\n",team1->teamname,hadicap1,team2->teamname,hadicap2);
    printf("%s vs %s score is %d vs %d\n",team1->teamname,team2->teamname,team1->score,team2->score);
    if (team1->score > team2->score) {
        printf("The winner is %s  The score is %d\n",team1->teamname, team1->score);
        return team1;
    }else{
        printf("The winner is %s  The score is %d\n",team2->teamname, team2->score);
        return team2;
    }
}

Team * tournament_partc(Team* teams[],int num){
    Team *win_array[num/2];
    if (num == 8) {
        printf("Round:1\n");
    }else if(num == 4){
        printf("Round:2\n");
    }else{
        printf("Round:3\n");
    }
    for (int i=0; i < num/2; i++) {
        Team *first_team = teams[i*2];
        Team *second_team = teams[i*2+1];
        
        Team * winner = game_partc(first_team,second_team);
        win_array[i] = winner;
        //printf("%s %s %s\n",first_team->teamname, second_team->teamname, winner->teamname);
        
        
        printf("\n");
        if (num == 2) {
            //_round = 0;
            Team *winner = win_array[0];
            printf("%s is the winner!\n",winner->teamname);
            return winner;
        }
    }
    return tournament_partc(win_array, num/2);
}


