#include<stdio.h>

void push(int *st, int s, int *t){
    if(*t < s - 1){
        int val;
        (*t)++;
        printf("Enter the value:\n");
        scanf("%d", &val);
        st[*t] = val;
    }
    else {
        printf("Stack Overflow!!!\n");
    }
}

void pop(int *st, int *t){
    if(*t<0){
        printf("Stack already Empty!!!");
    }
    else{
        (*t)--;
    }
}

void print(int *st, int *t){
    printf("=====\n");
    for(int i=*t; i>=0; i--){
        printf("%d\n^\n", st[i]);
    }
    printf("=====\n");
}

void main() {
    printf("Enter the size of your stack: \n");
    int sz, v;
    scanf("%d", &sz);
    int stck[sz];
    int sw;
    int top = -1;
    do{
        printf("Enter an action to perform: 1.Push  2.Pop  3.Print Stack  4.Exit\n");
        scanf("%d", &sw);
        switch(sw){
            case 1:
                push(stck, sz, &top);
                break;
            case 2:
                pop(stck, &top);
                break;
            case 3:
                print(stck, &top);
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }
    while(sw != 4);
}