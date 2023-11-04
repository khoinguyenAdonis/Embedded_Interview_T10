#include <stdio.h>
void hien_thi(int number[], int size){
    int check[size];
    for(int i = 0; i < size; i++){
        check[i] = 0;
    }
    for(int i = 0; i < size ; i++){
        if (check[i] == 1) continue;
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (number[i] == number[j]){
                count +=1;
                check[j] = 1; 
                /* code */
            }            
            /* code */
        }
        printf("so %d xuat hien %d lan\n",number[i], count);
        count = 0;        
    }
}
int main (){
    int number[] = {1, 2, 3, 1, 2, 4, 2, 1, 1, 6};
    hien_thi(number,sizeof(number)/sizeof(number[0]));
    return 0;
}