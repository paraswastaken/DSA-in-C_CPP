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

int bstTrack=0;

bool isBST(node* cNode){
    if(cNode==NULL)return true;
    if(!isBST(cNode->left)) return false;
    if(cNode->data<bstTrack) return false;
    bstTrack = cNode->data;
    if(!isBST(cNode->right)) return false;
    return true;
}

int count=-1;

void print2D(node* cNode){
    if(cNode==NULL) return;
    count++;
    print2D(cNode->right);
    for(int i=0; i<count; i++){
        cout<<"       ";
    }
    cout<<cNode->data;
    cout<<endl<<endl;
    print2D(cNode->left);
    count--;
    return;
}

node* delMain(node* rootT, int val){
    node* temp;
    if(rootT==NULL) return rootT;
    else if(rootT->data>val) rootT->left = delMain(rootT->left, val);
    else if(rootT->data<val) rootT->right = delMain(rootT->right, val);
    else if(rootT->data==val){
        if(rootT->left==NULL && rootT->right==NULL){
            delete rootT;
            return NULL;
        }
        else if(rootT->left==NULL){
            temp = rootT;
            rootT = rootT->right;
            delete temp;
        }
        else if(rootT->right==NULL){
            temp = rootT;
            rootT = rootT->left;
            delete temp;
        }
        else{
            temp = rootT->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            rootT->data=temp->data;
            rootT->right = delMain(rootT->right, temp->data);
        }
    }
    return rootT;
}


int main(){
//    root = insert(root, 15);
//    root = insert(root, 10);
//    root = insert(root, 21);
    int sw, val;
    do {
        cout<<"Enter your choice: 1. Insert 2. Search 3. Print Inorder 4. Print Preorder 5. Print Postorder 6. Print Level Order 7. Check BST 8. Invert Tree 9. Print 2D 10. Delete a value 11. Exit"<<endl;
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
                search(root, val)?cout<<"The value is present!":cout<<"Value is not present!!";
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
                cout<<endl;
                break;
            case 7:
                if(isBST(root)) {
                    cout<<"It's a Binary Search Tree!"<<endl;
                }
                else {
                    cout<<"It's not a Binary Search Tree!"<<endl;
                }
                bstTrack = 0;
                break;
            case 8:
                invertBT(root);
                break;
            case 9:
                print2D(root);
                break;
            case 10:
                cout<<"Enter value to delete:"<<endl;
                cin>>val;
                root = delMain(root, val);
                break;
            case 11:
                cout<<"Exiting!!!"<<endl;
                break;
            default:
                cout<<"Enter valid option"<<endl;
        }
    }while(sw!=11);
}
