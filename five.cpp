#include <inttypes.h> 
#include <stdio.h> 
#include <stdlib.h> 

struct Node {  
    int data; 
    Node* nexx; 
}; 

struct Node* XOR(struct Node* a, struct Node* b){ 
    return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b)); 
} 

struct Node* insert(struct Node** head, int value){ 
    if (*head == NULL){ 
        struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
        
        node->data = value; 
        node->nexx = XOR(NULL, NULL); 
        *head = node; 
    } 
    
    else { 
        struct Node* curr = *head; 
        struct Node* prev = NULL; 
        
        struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
  
        curr->nexx = XOR(node, XOR(NULL, curr->nexx)); 
        node->nexx = XOR(NULL, curr); 
        *head = node; 
		node->data = value; 
    } 
    return *head; 
} 
  
void print(struct Node** head){ 
    struct Node* curr = *head;
    struct Node* prev = NULL; 
    struct Node* next; 
  
    while (curr != NULL){ 
        printf("%d ", curr->data); 

        next = XOR(prev, curr->nexx); 
        prev = curr; 
        curr = next; 
    } 
    printf ("\n");
} 

struct Node* NthNode(struct Node** head, int n){ 
    int count = 0; 
  
    struct Node* curr = *head; 
    struct Node* curr1 = *head; 
    struct Node* prev = NULL; 
    struct Node* prev1 = NULL; 

    struct Node* next; 
    struct Node* next1; 
  
    while (count < n && curr != NULL){ 
        next = XOR(prev, curr->nexx); 
        prev = curr;
        curr = next; 
        count++; 
    } 
  
    if (curr == NULL && count < n){ 
        puts ("Wrong Input"); 
        return (uintptr_t)0; 
    } 
    else { 
        while (curr != NULL){ 
            next = XOR(prev, curr->nexx); 
            next1 = XOR(prev1, curr1->nexx); 
  
            prev = curr; 
            prev1 = curr1; 
  
            curr = next; 
            curr1 = next1; 
        } 
        printf("%d", curr1->data); 
    } 
} 
  
int main (){ 
    struct Node* head = NULL; 
  
    insert(&head, 0); 
    insert(&head, 2); 
    insert(&head, 1); 
    insert(&head, 3); 
    insert(&head, 11); 
    insert(&head, 8); 
    insert(&head, 6); 
    insert(&head, 7); 
  
    NthNode(&head, 5); 
  
    return 0; 
}
