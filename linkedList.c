#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

void insert(int dat){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = dat;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        Node* tmp2 = head;
        while(tmp2->next != NULL){
            tmp2 = tmp2->next;
        }
        tmp2->next = temp;
    }
}

void print(){
    if(head = NULL){
        printf("Linked List is empty\n");
    }
    else{
        int out;
        Node* temp = head;
        while(temp != NULL){
            out = temp->data;
            temp = temp->next;
            printf("%d -> ", out);
        }
    }
}

void main(){
    int val, sw;
    do
    {
        printf("Enter your choice: 1.Insert 2.Print 3.Exit\n");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Enter the value to be entered:\n");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                print();
                break;
            case 3:
                printf("EXITING!!!!\n");
                break;
            default:
                printf("Enter Valid Choice!!!!\n");
                break;
        }
    } while (sw != 3);
}