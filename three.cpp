#include <stdio.h>  
#include <stdlib.h>  

struct Node{  
    int data;  
    struct Node* next;  
};  

void middle(struct Node *head){
   struct Node *fast = head;
   struct Node *slow = head;
   
   if (head != NULL){
		while (fast != NULL && fast->next != NULL){  
            fast = fast->next->next;  
            slow = slow->next;  
        }  
        printf ("Middle is %d\n", slow->data);  
    }  
}  
  
void push(struct Node** head, int newData){  
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));  
  
    newNode->data = newData;  
    newNode->next = *head;  
    *head = newNode;  
}  
    
void print(struct Node *ptr){  
    while (ptr != NULL){  
        printf ("%d ->", ptr->data);  
        ptr = ptr->next;  
    }  
    printf ("NULL\n");  
}  
  
int main (){  
    struct Node* head = NULL; 
  
    for (int i = 10; i > 0; i--){  
        push(&head, i);  
        print(head);  
        middle(head);  
    }  
  
    return 0;  
}  
