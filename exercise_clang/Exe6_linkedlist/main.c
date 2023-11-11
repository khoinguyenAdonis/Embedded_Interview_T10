#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int value;
    struct Node *next;
}Node;



Node *createNode(int value){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}
// adds a new element ‘g’ at the end of the list.
int sizeList(Node **ptr){
    
    if (ptr == NULL) {
        printf("Khong co list nao ca");
    }
    else{
        int count = 0;
        Node *p = *ptr;
        while(p->next!=NULL){
            count++;
            p = p->next;
        }
        return count;
    }
}
void push_back(Node **ptp, int value){
    Node *temp = createNode(value);    //0xc9
    if(*ptp == NULL){
        *ptp = temp;
    }else{
        Node *p = *ptp;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

// removes the last element of the list, and reduces the size of the list by 1
void pop_back(Node **ptp){
    if (*ptp == NULL){
        printf("Danh sach rong");
        return;
    }
    else if ((*ptp)->next == NULL){
        *ptp = NULL;
    }else{
        Node *p = NULL;
        Node *current = *ptp;
        while (current->next != NULL){
            p = current;
            current = current->next;
            /* code */
        }
        free(current);
        p->next = NULL;        
    }
}


// inserts new elements in the list before the element at a specified position.

void insert(Node **ptp, int value, int index){
    Node *temp = createNode(value);
    int size = sizeList(ptp);
    if(index == 0){
        if(*ptp == NULL){
            *ptp = temp;
        }else{
            temp->next = *ptp;
            *ptp = temp;
        }
    }
    else if(index <= 0 || index > size+1){
        printf("Vi tri khong hop le\n");
        return;
    }
    else if(index == size+1){
        push_back(ptp,value);
    }
    else{
        Node *p = *ptp;
        for(int i =0; i< index-1; i++ ){
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

// moves a single element or a range of elements from the list.

void erase(Node **ptp, int index){
    int size = sizeList(ptp);
    if(*ptp == NULL ){
        printf("danh sach rong");
        return;
    }
    else if (index > size)
    {
        printf("Vi tri xoa khong hop le");
        return;
    }
    else if (index == size) pop_back(ptp);
    else{
        if ((*ptp)->next == NULL) *ptp = NULL;
        else if (index == size) pop_back(ptp);
        else{
            Node *p = NULL;
            Node *current = *ptp;
            for(int i = 0 ; i < index; i++){
                p = current;
                current = current->next;
            }
            p->next = current->next;           
            free(current);
        } 
    }
}


int getIndex(const Node *ptr, int index){
    
    int i = 0;

    while (index != i)      //2
    {
        ptr = ptr->next;
        i++;
    }

    return ptr->value;
    
}

int main(int argc, char const *argv[])
{
    Node *array = NULL;   //0xc5

    push_back(&array, 5);
    push_back(&array, 12);
    push_back(&array, 11);
    push_back(&array, 18);
    push_back(&array, 35);

    //pop_back(&array);
    //insert(&array,31,4);
    erase(&array,3);
    printf("test: %d\n", getIndex(array, 2));
    return 0;
}
