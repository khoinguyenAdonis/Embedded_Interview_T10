#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char *ptr;
    int lenght;
}words;

int nuberWords(char string[]){
    int count = 1;
    while (*string != '\0'){
        if (*string == ' '){
            count++;
            string++;
            continue;
        }
        string++;
    }
    return count;  
}
words* splitString(char string[], int size){
    words* array = (words*)malloc(sizeof(words)*size);
    int index = 0;
    int count = 0;
    array[index].ptr = string;
    while (*string != '\0')
    {
        if(*string == ' '){
            array[index].lenght = count;
            count = 0;
            index++;
            string++;
            array[index].ptr = string;
            continue;
        }
        string++;
        count++;
        /* code */
    }
    array[index].lenght = count;
    return array;
    
}
int num(char arr[]){
    int count = 0 ;
    while(*arr != '\0'){
        count++;
        arr++;
    }
    return count;
}

void findString(char arr[],char string[]){
    int numArr = num(arr);
    int count = 0;
    int numString = nuberWords(string);
    words* array = splitString(string,numString);
    for (int i = 0; i < numString; i++){
        if(numArr == array[i].lenght){
            int j = 0;
            while (j != numArr)
            {
                if(arr[j] != array[i].ptr[j]) break;
                j++;
            }
            if (j ==  numArr)
            {
                count++;
            }               
        }
    }
    if (count > 0 )
    {
        printf("Da tim thay ==> ``%s`` xuat hien %d lan\n",arr,count);
        /* code */
    }
    else printf ("khong tim thay\n");
    
}

int main (){
    char string [] = "A Wales where large grazing animals where roam freely in natural herds creating complex and dynamic habitat full of life";
    findString("where",string);
    return 0;
}