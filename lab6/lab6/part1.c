//
//  part1.c
//  lab6
//
//  Created by yuejing zhu on 2017/11/26.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "part1.h"
int k = 1;
struct Car * createCar(int weight){
    struct Car * ptr = malloc(sizeof(struct Car));
    ptr->next_car = NULL;
    ptr->cargo_weight = weight;
    return ptr;
}

struct Train * createTrain(){
    struct Train * train = malloc(sizeof(struct Train));
    train->first_car = NULL;
    return train;
}

void insertCar(struct Car * car, int weight){
    if(car->next_car == NULL){
        car->next_car = createCar(weight);
    }else{
        insertCar(car->next_car,weight);
    }
}

struct Car * readCar(struct Car * car, int weight){
    if(car->next_car == NULL){
        printf("This is the last car, weight %d, address is %p\n",car->cargo_weight,&car->cargo_weight);
    }else{
        printf("%dth car weight %d, address is %p\n",++k,car->cargo_weight,&car->cargo_weight);
        
        car = readCar(car->next_car, weight);
    }
    return car;
}

struct Car * Read( struct Train * train, int weight){
    if(train->first_car == NULL){
        printf("This train is empty");
    }else{
        printf("fristcar weight %d, address is %p\n",train->first_car->cargo_weight,&train->first_car->cargo_weight);
        return readCar(train->first_car->next_car, weight);
    }
    return NULL;
}

void FreeTrain(struct Train * train) {
    struct Car * current = train->first_car;
    int i = 0;
    while (current != NULL) {
        free(current);
        printf("%dth car: ", ++i);
        printf("free address is %p\n", current);
        current = current->next_car;
    }
    free(train);
    train = NULL;
}

int main(){
    printf("please enter number of car of the train:\n");
    int num;
    scanf("%d",&num);
   // printf("%d\n",num);
    printf("please enter weight of %d car of the train:(please use space)\n",num);
    /*int test;
    scanf("%d",&test);
    int weight[num];
    for (int i = 0; i < num; i++) {
        weight[num-1-i] = test%10;
        test = test/10;
    }*/
    int weight[num];
    for (int i=0; i<num; i++) {
        int temp;
        scanf("%d",&temp);
        weight[i] = temp;
    }

    //len = strlen(weight);
    struct Car * car = createCar(weight[0]);
    struct Train * train = createTrain();
    train->first_car = car;
    for (int i = 1; i < num ; i++) {
        insertCar(car, weight[i]);
    }
    Read(train, weight[0]);
    printf("free memory:\n");
    FreeTrain(train);
   
}














