#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* root=NULL;

Node* createNode(int dat){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = dat;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(int dat){
    if(root == NULL){
        temp = createNode(dat);
        root = temp;
    }
    else if(temp->data < root->data){
        
    }
}

void main(){

}