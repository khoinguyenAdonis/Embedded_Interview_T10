#include <stdio.h>

void converdWord(char string[], int size){
    char tmp[size];
    int first = 0;
    int last = size - 2;
    int idx = 0;
    for (int i = size; i >= 0; i--)
    {
        if (string[i] == ' '){
            first = i + 1;
            for (int j = first; j <= last; j++){
                tmp[idx++] = string[j];
            }
            tmp[idx++] = ' ';
            last = first - 2;
        }
    }
    for (int j = 0; j <= last; j++){
        tmp[idx] = string[j];
        idx++;
    }
    char *p = tmp;
    for (int i = 0 ; i < size; i++){
      *string = *p;
      string++;
      p++;
    }
}

int main (){
    char string[] = "​A Wales where large grazing animals roam freely in natural herds, creating complex and dynamic habitat full of life.";
    int size = sizeof(string)/sizeof(char);
    converdWord(string,size); 
    printf("%s\n",string);
    return 0;            
}