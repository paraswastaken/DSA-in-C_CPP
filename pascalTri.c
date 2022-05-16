#include<stdio.h>


void main(){
    int ar[100][100] = {0}; 
    int i, j, val;
    printf("Enter triangles height:\n");
    scanf("%d", &val);

    for(i=0;i<val;i++){
        ar[i][0] = 1;
    }

    for(i=1;i<val;i++){
        for(j=1;j<val;j++){
            ar[i][j] = ar[i-1][j-1] + ar[i-1][j];
        }
    }
    printf("\n");
    for(i=0;i<val;i++){
        for(j=0;j<val;j++){
            printf("%d      ", ar[i][j]);
        }
        printf("\n");
    }
    // pascal triangle is used to find coefficients in binomial expansion 
}
