//
//  part2.c
//  lab6
//
//  Created by yuejing zhu on 2017/11/28.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "part2.h"
struct Node * createNode(int info){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = info;
    ptr->next = NULL;
    ptr->previous = NULL;
    return ptr;
}
struct List * createList(){
    struct List * list = malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

struct Node * front(struct List * list){
    return list->head;
}

struct Node * insert(struct List * list, int index, int num){
   
    struct Node *node = createNode(num);
    struct Node *current = list->head;
        
        if (index == 0) {
            node->next = current;
            list->head = node;
        }else{
            int i=0;
            while (current->next != NULL && i<index) {
                current = current->next;
                i++;
            }
            node->next = current->next;
            current->next = node;
            node->previous = current;
            
        }
        return node;
    }

int delete(struct List * list, int index){
    
    struct Node *current = list->head;
    if (index == 0) {
        list->head = current->next;
        if (list->head) {
            list->head->previous = NULL;
        }
        free(current);
        current = NULL;
        return 1;
    }
    int i = 1;
    while (current->next && i<index) {
        current = current->next;
        i++;
    }
   
    struct Node *temp = current->next;
    current->next = temp->next;
    if (current->next) {
        current->next->previous = current;
    }
    free(temp);
    temp = NULL;
    
    
    return 1;
}

void printList(struct List * list){
    struct Node * current = list->head;
    while (current != NULL) {
        printf("%d",current->data);
        current = current->next;
    }
}
struct Node * lastone(struct List *list){
    struct Node *current = list->head;
    struct Node *temp = current;
    while (current) {
        temp = current;
        current = current->next;
    }
    return temp;
}

int searchForward(struct List *list, int value){
    struct Node *current = list->head;
    int search = 0;
    int i = 1;
    while (current) {
        if (current->data == value) {
            search = 1;
            printf("forward search %d, in step %d\n",value,i);
        }
        current = current->next;
        i++;
    }
    
    return search;
}

int searchBackward(struct List *list, int value){
    struct Node * current = lastone(list);
    int search = 0;
    int i = 1;
    while (current) {
        //printf("data %d",current->data);
        if (current->data == value) {
            search = 1;
            printf("backward search %d, in step:%d\n",value,i);
        }
        current = current->previous;
        i++;
    }
    return search ;
}

void FreeList(struct List * list) {
    struct Node * current =  list->head;
    //int i = 0;
    while (current != NULL) {
        free(current);
        //printf("%dth car: ", ++i);
        //printf("free address is %p\n", current);
        current = current->next;
    }
    free(list);
    list = NULL;
}

int main(){
    printf("===========partA===========\n");
    srand((int)time(NULL));
    struct List *list = createList();
    
    for (int i=0; i<10; i++) {
        int value = rand()%10;
        insert(list, i, value);
        printf("step%d   insertnumber %d\nnow list:",i+1,value);
        printList(list);
        printf("\n");
    }
    
    printf("===========partB===========\n");
    printf("please enter a random number in 0-9:\n");
    int value;
    scanf("%d",&value);
    int search = searchForward(list, value);
    searchBackward(list, value);
    
    if (search == 0) {
        printf("The value %d is not found\n",value);
    }
    for (int i=9; i>=0; i--) {
        delete(list, i);
    }
    FreeList(list);
    list = NULL;
//
    return 0;
}







