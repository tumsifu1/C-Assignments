// stackproblem.c – Lab 02 – Aaron, Moise
#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode{
struct stackNode *next;
struct stackNode *prev;
char value;
}stack;

stack *front = NULL;
stack *end = NULL; 

stack *newNode(char d){ //function that creates new nodes 
    stack *p = (stack*)malloc(sizeof(stack));

    if(p != NULL){
        //intialize values of new node 
        p->value = d;
        p->prev = NULL;
        p->next = NULL;
    }
    return p;
}
char push(char d){
    stack *p = newNode(d);
    if(p == NULL) {
        return -1;
    }

    if(front != NULL){ // assign values to new node 
        p->next = front;
        front->prev = p;
        front = p;
    }else{ // assign values to new node if it is the first node
        front = p;
        end = p;
    }
    return 0;
}


void printStack(void){
    if(front == NULL){ // no inputs
        printf("LIST IS EMPTY");
        return;
    }
    for(stack *temp = front; temp != NULL; temp = temp->next){ //iterate the list backwards
        printf("%c", temp->value); //print character
    }
}

int main(){
    char ch;
    int count = 0;
    printf("Enter up to 80 charatchers on the line and they will be printed in reverse order\n");
    printf("Enter pop to remove the current value at the top of the list\n");
    printf("To end input type enter\n");
    
    while (count < 79){
        scanf("%c", &ch); //get the letter they are inputting
        if (ch != '\n'){ //if input is enter end the input 
            push(ch);
            count++;
        }else {
            break;
        }
    }
    
    printStack();
    return 0;
}