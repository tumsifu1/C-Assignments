// queueproblem.c – Lab 02 – Aaron, Moise
#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode{ //structure for noddes of the queue
struct queueNode *next;
struct queueNode *prev;
int value;


}queue;


queue *front0 = NULL; //front of the structure with modulo 4 = 0
queue *end0 = NULL; //end of the structure modulo 4 = 0

queue *front1 = NULL; //front of the structure with modulo 4 = 0
queue *end1= NULL; //end of the structure modulo 4 = 0

queue *front2 = NULL; //front of the structure modulo 4 = 2
queue *end2 = NULL; //end of the structure modulo 4 = 2

queue *front3 = NULL; //front of the structure with the number modulo 4 = 3
queue *end3 = NULL; //end of the structure modulo 4 = 3



queue *newNode(int d){ //function that creates new nodes 
    queue *p = (queue*)malloc(sizeof(queue));

    if(p != NULL){
        //intialize values of new node 
        p->value = d;
        p->prev = NULL;
        p->next = NULL;
    }
    return p;
}
int push(int d){
    queue *p = newNode(d); //temporary varaible to reorder the pointers
    if(p == NULL) {
        return -1; //makes sure memory was allocaated
    }

    if( d%4 == 0) { //push number in queue 0 if d%4 is 0
        if(end0 != NULL){
            end0->next = p;
            p->prev = end0;
            end0 = p;
        }else{
            front0 = p;
            end0 = p;
        }
    }
    if( d%4 == 1) { //push number in queue 0 if d%4 is 1
        if(end1 != NULL){
            end1->next = p;
            p->prev = end1;
            end1 = p;
        }else{
            front1 = p;
            end1 = p;
        }
    }

    if( d%4 == 2) { //push number in queue 0 if d%4 is 2
        if(end2 != NULL){
            end2->next = p;
            p->prev = end2;
            end2 = p;
        }else{
            front2 = p;
            end2 = p;
        }
    }

    if( d%4 == 3) { //push number in queue 0 if d%4 is 3
        if(end3 != NULL){
            end3->next = p;
            p->prev = end3;
            end3 = p;
        }else{
            front3 = p;
            end3 = p;
        }
    }
    return 0;
}

/* void pop(){
    queue *temp = front;
    if(end == NULL){
        printf("List is empty\n"); //check if the list is empty
    }else{
        front = temp->next;
        front->prev = NULL;
        free(temp);
    }
} */

void printQueue(void){

    int count; //counter to check if 12 outputs have been printed
    if(front0 == NULL && front1 == NULL && front2 == NULL && front3 == NULL){
        printf("\nALL LISTS ARE EMPTY\n");
        return;
    }
    if(front0 == NULL){ // front of list of d%4 = 0
        printf("\nLIST 1 IS EMPTY\n");
    }
    if(front1 == NULL){ // front of list of d%4 = 1
         printf("\nLIST 2 IS EMPTY\n");
    }
    if(front2 == NULL){ // front of list of d%4 = 2
         printf("LIST 3 IS EMPTY\n");
    }
    if(front3 == NULL){ // front of list of d%4 = 3
        printf("LIST 4 IS EMPTY\n");
    }
    
    
    for(queue *temp = end0; temp != NULL; temp = temp->prev){ //iterate and check end condition of print statement
        if(temp == end0){
            printf("\n");
        }
        printf("%5d", temp->value); //print the current value
        count++;
        if(count > 12){ //check if 12 values have been printed
            printf("\n");
            count = 0;
        } 
    }
    //code below is repeated of whats above but of the different queues
    for(queue *temp = end1; temp != NULL; temp = temp->prev){
        if(temp == end1){
            printf("\n");
        }
        printf("%5d", temp->value);
        count++;
        if(count > 12){
            printf("\n");
            count = 0;
        } 
    }
    for(queue *temp = end2 ; temp!= NULL; temp = temp->prev){
        if(temp == end2){
            printf("\n");
        }
        printf("%5d", temp->value);
        count++;
        if(count > 12){
            printf("\n");
            count = 0;
        } 
    }
    for(queue *temp = end3; temp != NULL ; temp = temp->prev){
        if(temp == end3){
            printf("\n");
        }
        printf("%5d", temp->value);
        count++;
        if(count > 12){
            printf("\n");
            count = 0;
        } 
    }
}

int main(){
    int d;
    int count = 0;
    printf("Enter up to 400 inputs or until a negative number is input\n");
    printf("seperate inputs by using enter\n");
    

    while (count < 399){ //limit of 400 inputs
        scanf("%5d", &d); //get the letter they are inputting
        
        if(d<0){ //if d<0 no more inputs
            break;
        }
        if(d == 10 || d == 32){ //avoid ascii value of 10 and 32 which = new line and space
            push(d );
            count++;
        }else if((char) d != '\n' && (char) d !=' '){ //if input is enter or space push into queue node
            push(d );
            count++;
        }else {
            break;
        }
    }
    
    printQueue();
    return 0;
}