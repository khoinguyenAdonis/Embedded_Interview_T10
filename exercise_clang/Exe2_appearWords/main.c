#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
    char *ptr;
    int lenght;
    int count;
    bool status;
}words;

int sizeString(char string[]){
    int count = 1;
    while (*string != '\0'){
        if (*string == ' '){
            count++;
        }
        string++;
    }
    return count;
}

words *Words(char string[],int size){
    words* arr=(words*)malloc(sizeof(words)*size);   
    int index = 0;
    int count = 0;
    arr[index].ptr = string;
    while (*string != '\0'){
        if(*string  ==  ' '){
            arr[index].lenght = count;
            count = 0;
            string ++;
            index ++;
            arr[index].ptr = string;
            continue;
        }
        count++;
        string++;
    }
    arr[index].lenght = count;
    return arr;
}

bool Check(char arr1[], char arr2[]){
    int i = 0;
    while ( arr1[i] != ' ')
    {
        if (arr1[i] > arr2[i] ) return false;
        else if ( arr1[i] < arr2[i]){
            return  false;
        }
        i++;
    }
    return  true;
}

void compareArray(words array[], int size){
    for (int i = 0 ; i < size ; i ++){
        int count = 0;
        if (array[i].status == true) continue;
        for(int j = 0; j < size; j++){
            if(Check(array[i].ptr,array[j].ptr)){
                count++;
                array[i].status = false;
                array[j].status = true;
            }
        }
        array[i].count = count;
    }
}

void hien_thi(char string[]){
    int size = sizeString(string);
    words* array = Words(string,size);
    compareArray(array,size);
    for (int i = 0; i < size; i++)
    {
        if (array[i].status == false )
       {
            int j =0;
            printf("tu '");
            while (j!= array[i].lenght)
            {
                printf("%c",array[i].ptr[j]);
                j++;
            }
            printf("' xuat hien %d lan\n",array[i].count);            
        }        
    }
}

int main (){
    char string [] = "mot hai mot hai mot hai ba bon bon ba";
    hien_thi(string);
    return 0;
}