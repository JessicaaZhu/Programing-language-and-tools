//
//  part3.c
//  lab6
//
//  Created by yuejing zhu on 2017/11/28.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "part3.h"
struct Node * createNode(int info){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = info;
    ptr->next = NULL;
    return ptr;
}
struct List * createList(){
    struct List * list = malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}


struct Node * lastone(struct List * list){
    struct Node * current = list->head;
    struct Node * temp = current;
    while (current) {
        temp = current;
        current = current->next;
    }
    return temp;
}

int Count(struct List * list){
    int i = 0;
    struct Node * current = list->head;
    while (current) {
        current = current->next;
        i++;
    }
    return i;
}

struct Node * front(struct List * list){
    return list->head;
}

struct Node * insert(struct List * list, int index, int num){
    
    struct Node * node = createNode(num);
    struct Node * current = list->head;
    
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
    
    
    return 0;
}

void printList(struct List * list){
    struct Node * current = list->head;
    while (current != NULL) {
        printf("%d ",current->data);
        current = current->next;
    }
}

struct Stack *creatStack(){
    struct Stack *stack = malloc(sizeof(struct Stack));
    return stack;
}

void push(struct Stack * stack, int value){
    struct List *list = stack->list;
    int count = Count(list);
    insert(list, count, value);
}


int pop(struct Stack * stack){
    struct List *list = stack->list;
    struct Node *current = lastone(list);
    int count = Count(list);
    int value = current->data;
    delete(list, count-1);
    return value;
}


struct Queue *creatQueue(){
    struct Queue *queue = malloc(sizeof(struct Queue));
    return queue;
}

void enqueue(struct Queue * queue, int value){
    struct List *list = queue->list;
    int count = Count(list);
    insert(list, count, value);
}

int dequeue(struct Queue * queue){
    struct List *list = queue->list;
    int value = front(list)->data;
    delete(list, 0);
    return value;
}

int main(){
    printf("===========PartA==========\n");
    struct List * list = createList();
    struct Stack * stack = creatStack();
    stack->list = list;
    printf("please enter 5 integers:(please use space between each number)\n");
    for (int i=0; i<5; i++) {
        int value ;
        scanf("%d",&value);
        push(stack, value);
    }
    printf("initial list:\n");
    printList(list);
    printf("\n");
    printf("final list:\n");
    for (int  i = 0; i < 5; i++) {
        int value = pop(stack);
        printf("%d ",value);
    }
    printf("\n");

    
    printf("===========PartB==========\n");
    
    struct Queue * queue = creatQueue();
    queue->list = list;
    
    printf("please enter 5 integers in :(plaese use space)\n");
    for (int i = 0; i < 5; i++) {
        int value;
        scanf("%d",&value);
        enqueue(queue, value);
    }
    
    printf("initial list:\n");
    printList(list);
    printf("\n");
    printf("final list:\n");
    for (int i = 0; i < 5; i++) {
        int value = dequeue(queue);
        printf("%d ",value);
    }
    printf("\n");
    free(list);
    list = NULL;
    free(stack);
    stack = NULL;
    free(queue);
    queue = NULL;
    
    
    
    return 0;
}
