//
//  part1.c
//  lab7
//
//  Created by yuejing zhu on 2017/11/29.
//  Copyright © 2017年 yuejing. All rights reserved.
//

#include "part1.h"

struct Data * createData(int info){
    struct Data * data = malloc(sizeof(struct Data));
    data->value = info;
    return data;
}

struct Tree * createTree(){
    struct Tree * tree = malloc(sizeof(struct Tree));
    tree->root = NULL;
    return tree;
}

struct Node * createNode(struct Data * info){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->parent = NULL;
    ptr->data = info;
    return ptr;
}

void insert(struct Tree * tree, struct Data * data){
    struct Tree * temp = createTree();
    if (tree->root == NULL) {
        printf("The tree is empty\n");
    }else{
    
    if(data->value < tree->root->data->value){
        if(tree->root->left == NULL){
            tree->root->left = createNode(data);
            tree->root->left->parent = tree->root;
        }else{
            temp->root = tree->root->left;
            insert(temp, data);
        }
    }else if (data->value > tree->root->data->value){
        if (tree->root->right == NULL) {
            tree->root->right = createNode(data);
            tree->root->right->parent = tree->root;
        }else{
            temp->root = tree->root->right;
            insert(temp, data);
        }
    }else{
        printf("You cannot insert duplicate values!");
    }
    }
}

struct Node * SearchNode(struct Node * node,struct Data * data){
    if (data->value < node->data->value) {
        if (node->left == NULL) {
            printf("value not found\n");
        }else{
            printf("left %d\n",node->left->data->value);
            node = SearchNode(node->left, data);
        }
    }else if (data->value > node->data->value){
        if (node->right == NULL) {
            printf("value not found\n");
        }else{
             printf("right %d\n",node->right
                ->data->value);
            node = SearchNode(node->right, data);
        }
    }
    return node;
}

struct Node * search(struct Tree * bst,struct Data * value){
    if (bst->root == NULL) {
        printf("The tree is empty\n");
    }else{
        printf("Root %d\n",bst->root->data->value);
        return SearchNode(bst->root, value);
    }
    return NULL;
}

void init(struct Tree * tree){
    //struct Tree * tree = createTree();
    struct Tree * temp = createTree();
    int value;
    ///Users/yuejingzhu/Desktop/580u/lab7/lab7/
    FILE * fptr = fopen("./data.txt", "a+");
    fseek(fptr, 0, SEEK_SET);
    int i = 0;
    while (fscanf(fptr, "%d", &value) >= 0) {
        struct Data * data = createData(value);
        if (i == 0) {
            tree->root = createNode(data);
        } else {
            //struct Tree * temp = createTree();
            temp->root = tree->root;
            insert(temp, data);
        }
        i++;
    }
    fclose(fptr);
    fptr = NULL;
}
int main(){
    printf("==============part1&2==============\n");
    struct Data * datat = createData(5);
    struct Node * test = createNode(datat);
    printf("%d\n",test->data->value);
    struct Tree * treet = createTree();
    treet->root = test;
    printf("%d\n",treet->root->data->value);
    struct Data * data1 = createData(3);
    insert(treet, data1);
    printf("%d\n",treet->root->left->data->value);
    printf("==============part3==============\n");
    struct Tree * tree = createTree();
    init(tree);
    int num = 0;
    while (1) {
        printf("please input the number you want to search:\n");
        scanf("%d", &num);
        if (num == 0) {
            printf("Stop searching.\n");
            break;
        }
        struct Data * searchnum = createData(num);
        struct Node * node = search(tree, searchnum);
        if (node != NULL) {
            if (node->parent != NULL) {
                printf("the parent node is %d\n", node->parent->data->value);
            }
            if (node->left != NULL) {
                printf("the left node is %d\n", node->left->data->value);
            }
            if (node->right != NULL) {
                printf("the right node is %d\n ", node->right->data->value);
            }
        }
        free(searchnum);
        searchnum = NULL;
        printf("\n");
    }
    return 0;
}
