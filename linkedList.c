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

    Node* tmp2 = head;
    while(pos-2 > 0){
        if(tmp2->next == NULL){
            printf("Invalid Position\n");
            return;
        }
        else{
            tmp2 = tmp2->next;
            pos--;
        }
    }
    temp->next=tmp2->next;
    tmp2->next=temp;
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
    Node* temp = head;
    Node* temp2;
    while(pos-2 > 0){
        if(temp->next->next == NULL){
            printf("Invalid Position\n");
            return;
        }
        else{
            temp = temp->next;
            pos--;
        }
    }
    temp2 = temp->next;
    temp->next=temp2->next;
    temp2->next=NULL;
    free(temp2);
}

void reverse_LL(){
    Node* t1;
    Node* t2;
    t1 = head->next;
    head->next=NULL;
    while(t1 != NULL){
        t2 = t1->next;
        t1->next = head;
        head = t1;
        t1 = t2;
    }
}

void reverse_recursive(Node* n){
    if(n->next->next == NULL){
        head = n->next;
        head->next=n;
        return;
    }
    else{
        Node* temp;
        temp = n->next;
        reverse_recursive(temp);
        temp->next=n;
        n->next = NULL;
    }
}

void main(){
    int val, sw, pos;
    head = NULL;
    do
    {
        printf("Enter your choice:\n1.Insert at End 2.Insert at beginning 3.Insert at Position 4.Delete from position\n5.Print the List 6.Reverse LinkeList 7.Reverse Recursively 8.Exit\n");
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
                reverse_LL();
                break;
            case 7:
                reverse_recursive(head);
                break;
            case 8:
                printf("EXITING!!!!\n");
                break;
            default:
                printf("Enter Valid Choice!!!!\n");
                break;
        }
    } while (sw != 8);
}