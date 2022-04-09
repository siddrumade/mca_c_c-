#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int *x,int *y){
    int tmp= *x;
    *x = *y;
    *y = tmp;
}
void printArray(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        cout << arr[i] << "  \n";

    }
}
void selectionSort(int arr[],int n){
    printf("before sort");
    printArray(arr,5);
    int i,j, min_idx;
    for(i=0;i<n-1;i++){
        
        min_idx = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[min_idx]){
                min_idx=j;
            }
        }
        swap(&arr[min_idx],&arr[i]);

    }
    printf("after sort");
    printArray(arr,5);

}



int main(){
    int arr[] {64 ,25,12,22,11};
    //printArray(arr,5);
    selectionSort(arr,5);
    return 0;
}