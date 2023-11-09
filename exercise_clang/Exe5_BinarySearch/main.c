#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[],int id, int left, int right){  
    if (left == right){
        if (array[left] == id) return id;
        else return -1;
    }
    else{
        int mid = (left+right)/2;
        if (array[mid] == id) return id;
        else{
            if(array[mid] > id) return binarySearch(array,id,left,mid - 1);
            else return binarySearch(array,id,mid+1,right);
        }
    }
}

int main(){
    int array[10000];
    for(int i=0; i<10000; i++){
        array[i] = array[i-1] + rand() % 100 ;
    }
    printf("\n");
    int id = 8170;
    int left = 0;
    int right =  sizeof(array)/sizeof(array[0])-1;
    int result = binarySearch(array,id, left,right);
    printf("ID:\t%d\nResult:\t%s",id,(result > 0)? "Valid":"Not Valid");
    return 0;
}