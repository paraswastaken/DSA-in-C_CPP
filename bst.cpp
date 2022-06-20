#include<iostream>
#include<queue>

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

void inOrder(node* cNode){
    if(cNode==NULL) return;
    inOrder(cNode->left);
    cout<<cNode->data<<" ";
    inOrder(cNode->right);
    return;
}

void preOrder(node* cNode){
    if(cNode==NULL) return;
    cout<<cNode->data<<" ";
    preOrder(cNode->left);
    preOrder(cNode->right);
    return;
}

void postOrder(node* cNode){
    if(cNode==NULL) return;
    postOrder(cNode->left);
    postOrder(cNode->right);
    cout<<cNode->data<<" ";
    return;
}

void levelOrder(node* cNode){
    if(cNode==NULL) return;
    queue<node*> Q;
    Q.push(cNode);
    while(!Q.empty()){
        node* current = Q.front();
        cout<<current->data<<" ";
        if(current->left){
            Q.push(current->left);
        }
        if(current->right){
            Q.push(current->right);
        }
        Q.pop();
    }
    return;
}

void invertBT(node* cNode){
    if(cNode==NULL) return;
    invertBT(cNode->left);
    invertBT(cNode->right);
    node* temp = cNode->left;
    cNode->left = cNode->right;
    cNode->right = temp;
    return;
}


int main(){
//    root = insert(root, 15);
//    root = insert(root, 10);
//    root = insert(root, 21);
    int sw, val;
    do {
        cout<<"Enter your choice: 1. Insert 2. Search 3. Print Inorder 4. Print Preorder 5. Print Postorder 6. Print Level Order 7. Invert Tree 8. Exit"<<endl;
        cin>>sw;
        switch(sw){
            case 1:
                cout<<"Enter Value to enter:"<<endl;
                cin>>val;
                root=insert(root, val);
                break;
            case 2:
                cout<<"Enter value to search:"<<endl;
                cin>>val;
                cout<<search(root, val)?"The value is present!":"Value is not present!!";
                cout<<endl;
                break;
            case 3:
                inOrder(root);
                cout<<endl;
                break;
            case 4:
                preOrder(root);
                cout<<endl;
                break;
            case 5:
                postOrder(root);
                cout<<endl;
                break;
            case 6:
                levelOrder(root);
                break;
            case 7:
                invertBT(root);
                break;
            case 8:
                cout<<"Exiting!!!"<<endl;
                break;
            default:
                cout<<"Enter valid option"<<endl;
        }
    }while(sw!=8);
}
