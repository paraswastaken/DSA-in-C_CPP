#include<stdio.h>
#include<stdlib.h>

void printarr(int ar[4][4]){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}

void rotateM(int ar[4][4]){
    int tmp[4][4];
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp[i][3-j]=ar[i][j];
        }
    }
    // printarr(tmp);
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            ar[i][j]=tmp[j][i];
        }
    }
}

void main(){
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printarr(arr);
    rotateM(arr);
    printf("\n");
    printarr(arr);
}