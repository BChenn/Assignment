#include <stdio.h> 
#include <stdlib.h> 
  
struct Node{ 
    int data; 
    Node* next; 
}; 

void removeDuplicates(struct Node* head){ 
    struct Node* curr = head; 
    struct Node* nextt;  
    
    if (curr == NULL){
       return;  
	}
	
    while (curr->next != NULL){ 
       if (curr->data == curr->next->data){             
           nextt = curr->next->next; 
           free(curr->next); 
           curr->next = nextt;   
       } 
       else { 
          curr = curr->next;  
       } 
    } 
} 

void push(struct Node** headd, int newData){ 
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 

    newNode->data = newData; 
    newNode->next = *headd;      
    *headd = newNode; 
} 
  
void print(struct Node *node){ 
    while (node != NULL){ 
       printf ("%d ", node->data); 
       node = node->next; 
    } 
    printf ("\n");
}  

int main (){
    struct Node* head = NULL; 
    
    push(&head, 30); 
    push(&head, 15); 
    push(&head, 15);   
    push(&head, 10); 
    push(&head, 10); 
    push(&head, 10);                                     
  
//    printf ("Before  "); 
//    print(head);  
  
    removeDuplicates(head);  
  
//    printf ("After ");          
    print(head);             
    
    return 0; 
} 
