#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char* ptr;
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
        /* code */
    }
    return count;
    
}
words *splitsWords(char string[], int size){
    words* array= (words*)malloc(sizeof(words)*size);
    int count = 0;
    int index = 0;
    array[index].ptr = string;
    while(*string != '\0'){
        if (*string == ' '){
            array[index].lenght = count;
            count = 0;
            index ++;
            string ++;
            array[index].ptr = string;
            continue;
            /* code */
        }
        count++;
        string++;
    }
    array[index].lenght = count;
    return array;
}

void display(char string[]){
    int size = nuberWords(string);
    words* array = splitsWords(string,size);
    words* swapString = (words*)malloc(sizeof(words)*size);
    for (int i =0 ; i< size; i++){
        swapString[i] = array[size - 1 -i];      
    }
    for (int i = 0; i < size; i++){
        int j = 0;
        while (j != swapString[i].lenght){
            printf("%c",swapString[i].ptr[j]);
            j++;
        }
        printf(" ");
    }
    printf("\n");
    free(array);
    free(swapString);
}

int main (){
    char string[] = "​A Wales where large grazing animals roam freely in natural herds, creating complex and dynamic habitat full of life.";
    display(string);             
}