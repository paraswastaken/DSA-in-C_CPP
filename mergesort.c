#include<stdio.h>
#include<stdlib.h>

void merge(int ar[], int l, int m, int r){
    int a1[m-l+1], a2[r-m];
    for(int i=0;i<m-l+1;i++){
        a1[i]=ar[l+i];
    }
    for(int i=0;i<r-m;i++){
        a2[i]=ar[m+i+1];
    }
    int l1=0, l2=0, i = l;
    while(l1 < m-l+1 && l2 < r-m){
        if(a1[l1]>=a2[l2]){
            ar[i]=a2[l2];
            i++;
            l2++;
        }
        else {
            ar[i]=a1[l1];
            i++;
            l1++;
        }
    }
    for(;l1<m-l+1;l1++){
        ar[i]=a1[l1];
        i++;
    }
    for(;l2<r-m;l2++){
        ar[i]=a2[l2];
        i++;
    }
}

void mSort(int ar[], int l, int r){
    if(r>l){
        int m = l + (r-l)/2;
        mSort(ar, l, m);
        mSort(ar, m+1, r);
        merge(ar, l, m, r);
    }
}

int main() {
    int arr[]={1,5,6,4,2,87,45,32,98,54,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    mSort(arr, 0, size-1);
    for(int i=0;i<11;i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}