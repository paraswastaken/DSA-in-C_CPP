#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    char STR[1000];
    int top;
    /* data */
}stack;

void push(char ch, stack *st){
    st->STR[++(st->top)] = ch;
}

char pop(stack *st){
    return (st->STR[(st->top)--]);
}

void reset(stack *st){
    st->top = -1;
}

void print(stack *st){
    int i=st->top;
    for(;i>=0;i--){
        printf("\n%c\n^", st->STR[i]);
    }
}

int top(stack *st){
    return (st->top);
}

// Driver Code
void main(){
    stack stck;
    int sw;
    char tmp;
    do{
        printf("Enter action: 1.Push 2.Pop 3.Top 4. Reset 5.Print 6. Exit\n");
        scanf("%d", &sw);
        switch (sw)
        {
        case 1:
            printf("Enter character:\n");
            scanf("%c", &tmp);
            push(tmp, &stck);
            break;
        case 2:
            printf("%c\n", pop(&stck));
            break;
        case 3:
            printf("%d\n", top(&stck));
            break;
        case 4:
            reset(&stck);
            break;
        case 5:
            print(&stck);
            break;
        case 6:
            printf("Exiting\n");
            break;
        default:
            printf("Enter a valid choice!!!\n");
            break;
        }
    }
    while (sw!=6);
}
