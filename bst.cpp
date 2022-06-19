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

node* insert(node* cNode, int val){
    if(cNode==NULL){
        cNode = newNode(val);
    }
    else if(cNode->data<=val){
        cNode->right = insert(cNode->right,val);
    }
    else{
        cNode->left = insert(cNode->left,val);
    }
    return cNode;
}

bool search(node* cNode, int dat){
    if(cNode==NULL) return false;
    else if(cNode->data==dat) return true;
    else if(cNode->data<=dat) return search(cNode->right,dat);
    else return search(cNode->left, dat);
}

int main(){
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 21);
    cout<<search(root, 21);
}
