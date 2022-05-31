#include<stdio.h>


void main(){
    int ar[100][100] = {0}; 
    int i, j, val;
    printf("Enter triangles height:\n");
    scanf("%d", &val);

    for(i=0;i<val;i++){
        for(j=0;j<=i;j++){
            if(i==0||i==j){
                ar[i][j]=1;
                continue;
            }
            ar[i][j]=ar[i-1][j]+ar[i-1][j-1];
        }
    }
    for(i=0;i<val;i++){
        for(j=0;j<=i;j++){
            printf("%d\t", ar[i][j]);
        }
        printf("\n");
    }
    // pascal triangle is used to find coefficients in binomial expansion 
}
