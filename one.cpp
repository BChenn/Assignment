#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct Node{ 
    int number; 
    Node* next; 
}; 

void move(struct Node** end, struct Node** start){ // swapping
    struct Node* newNode = *start; 
    assert(newNode != NULL); 
  
    *start = newNode->next; 
    *end = newNode; 
} 

struct Node* MergeSort(struct Node* a, struct Node* b){ 
    struct Node temp; 
    struct Node* tail = &temp; 
    temp.next = NULL; 
    
    while (1){ 
        if (a == NULL){ 
            tail->next = b; 
            break; 
        } 
        else if (b == NULL){ 
            tail->next = a; 
            break; 
        } 
        if (a->number <= b->number){
            move(&(tail->next), &a); 
        } 
        else {
            move(&(tail->next), &b); 
        }
        tail = tail->next; 
    } 
    return (temp.next); 
} 

void push(struct Node** head, int newNumber){ // pushTail
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
    
    newNode->number = newNumber; 
    newNode->next = *head; 
    *head = newNode; 
} 
  
void print(struct Node *node){ 
    while (node != NULL){ 
        printf ("%d ", node->number); 
        node = node->next; 
    } 
    printf ("\n");
} 

struct Node* res = NULL; 
struct Node* a = NULL; 
struct Node* b = NULL; 

int main (){  
    push(&a, 5); 
    push(&a, 3); 
    push(&a, 1); 
    push(&b, 9); 
    push(&b, 7); 
    push(&b, 4); 

    res = MergeSort(a, b); 
  
    printf("Merged Linked List are : \n"); 
    print(res); 
  
    return 0; 
} 
