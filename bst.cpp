#include<iostream>

using namespace::std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* root=NULL;

node* newNode(int val){
    node* temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(int val, node* cNode){
    if(cNode->data<val){
        if(cNode->right==NULL){
            cNode->right=newNode(val);
            return;
        }
        else{
            insert(val, cNode->right);
        }
    }
    else{
         if(cNode->left==NULL){
            cNode->left=newNode(val);
            return;
        }
        else{
            insert(val, cNode->left);
        }
    }
}

int main(){
    
}
