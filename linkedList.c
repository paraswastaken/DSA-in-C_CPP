#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head;

void insert_at_end(int dat){
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

void insert_at_beginning(int dat){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = dat;
    temp->next = head;
    head = temp;
}

void insert_at_pos(int dat, int pos){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = dat;
    temp->next = NULL;

    int flag = 0;
    Node* tmp2 = head;
    while(pos-2 > 0){
        if(tmp2->next == NULL){
            printf("Invalid Position\n");
            pos = 2;
            flag = 1;
        }
        else{
            tmp2 = tmp2->next;
            pos--;
        }
    }
    if(flag != 1){
        temp->next=tmp2->next;
        tmp2->next=temp;
    }
}

void printLL(){
    Node* temp = head;
    if(head == NULL){
        printf("Linked List is empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d", temp->data);
            if(temp->next != NULL){
                printf(" -> ");
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

void delete_from_pos(int pos){
    int flag = 0;
    Node* temp = head;
    Node* temp2;
    while(pos-2 > 0){
        if(temp->next->next == NULL){
            printf("Invalid Position\n");
            pos = 2;
            flag = 1;
        }
        else{
            temp = temp->next;
            pos--;
        }
    }
    if(flag != 1){
        temp2 = temp->next;
        temp->next=temp2->next;
        temp2->next=NULL;
        free(temp2);
    }
}


void main(){
    int val, sw, pos;
    head = NULL;
    do
    {
        printf("Enter your choice:\n1.Insert at End 2.Insert at beginning 3.Insert at Position\n4.Delete from position 5.Print the List 6.Exit\n");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Enter the value to be inserted:\n");
                scanf("%d", &val);
                insert_at_end(val);
                break;
            case 2:
                printf("Enter the value to be inserted:\n");
                scanf("%d", &val);
                insert_at_beginning(val);
                break;
            case 3:
                printf("Enter the value to be inserted:\n");
                scanf("%d", &val);
                printf("Enter position to be inserted in:\n");
                scanf("%d", &pos);
                insert_at_pos(val, pos);
                break;
            case 4:
                printf("Enter position to be deleted from:\n");
                scanf("%d", &pos);
                delete_from_pos(pos);
                break;
            case 5:
                printLL();
                break;
            case 6:
                printf("EXITING!!!!\n");
                break;
            default:
                printf("Enter Valid Choice!!!!\n");
                break;
        }
    } while (sw != 6);
}