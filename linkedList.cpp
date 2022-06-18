#include<iostream>

using namespace::std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head=NULL;

void insertAtHead(int val){
    Node* temp = new Node();
    temp->next=NULL;
    temp->data=val;
    if(head==NULL){
        head=temp;
        return;
    }
    temp->next = head;
    head = temp;
    return;
}


void insertAtTail(int val){
    Node* temp = new Node();
    temp->next=NULL;
    temp->data=val;
    if(head==NULL){
        head=temp;
        return;
    }
    Node* t2 = head;
    while(t2->next != NULL){
        t2 = t2->next;
    }
    t2->next = temp;
    return;
}

void printL(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int main() {
    int sw=0;
    int inp=0;
    do{
        cout<<"Enter your choice: 1.Insert at Head 2.Insert at Tail 3.Print 4.Exit"<<endl;
        cin>>sw;
        switch (sw){
            case 1:
                cout<<"Enter your value:"<<endl;
                cin>>inp;
                insertAtHead(inp);
                break;
            case 2:
                cout<<"Enter your value:"<<endl;
                cin>>inp;
                insertAtTail(inp);
                break;
            case 3:
                printL();
                break;
            case 4:
                cout<<"Exiting!!!"<<endl;
                break;
        }
    }while(sw<4);
}
