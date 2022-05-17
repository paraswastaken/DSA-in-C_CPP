#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(char ch){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = ch;
    temp->next = NULL;
    if(top == NULL){
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
}

void pop(){
    Node* temp;
    temp = top;
    top = temp->next;
    free(temp);
}

void main(){
    char arr[100];
    printf("Enter the expression to evaluate balanced parenthesis(max 99 char):\n");
    scanf("%c", arr);
    for(int i=0; arr[i]!= '\0' || i<100; i++){
        if(arr[i]== ("(" || "{" || "[")){
            push(arr[i]);
        }
        else if(arr[i] == (")" || "}" || "]")){
            if(arr[i] != top->data){
                printf("Unbalanced parenthesis\n");
                break;
            }
            else{
                pop();
            }
        }
    }
    if(top == NULL){
        printf("Balanced parenthesis\n");
    }
    else{
        printf("Unbalanced parenthesis\n");
    }
}
