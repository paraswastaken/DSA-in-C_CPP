#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

// Every operation on a queue in this impelementation is of linear time complexity

void enqueue(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

int dequeue(){
    if(front == NULL){
        printf("Queue is Empty\n");
        return 0;
    }
    else{
        Node* temp = front;
        if(front == rear){
            rear = NULL;
        }
        front = front->next;
        int dat = temp->data;
        free(temp);
        return dat;
    }
}

void printQueue(){
    Node* temp = front;
    printf("< ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("<\n");
}

void main(){
    int sw, dat; 
    do
    {
        printf("Enter the operation to perform:\n1.Enqueue 2.Dequeue 3.Print the Queue 4.Exit\n");
        scanf("%d", &sw);
        switch(sw)
        {
        case 1:
            printf("Enter data to enqueue.\n");
            scanf("%d", &dat);
            enqueue(dat);
            break;
        case 2:
            dat = dequeue();
            break;
        case 3:
            printQueue();
            break;
        case 4:
            printf("Exiting!!!\n");
        default:
            break;
        }
    } while (sw != 4);
}