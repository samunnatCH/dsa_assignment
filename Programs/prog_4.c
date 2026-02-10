#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* previous;
    struct node* following;
}Node;

Node* first=NULL;

void show(){
    Node* ptr=first;
    if(ptr==NULL){
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while(ptr!=NULL){
        printf("%d ",ptr->val);
        ptr=ptr->following;
    }
    printf("\n");
}

void addBegin(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=value;
    newNode->previous=NULL;
    newNode->following=first;
    if(first!=NULL){
        first->previous=newNode;
    }
    first=newNode;
}

void addEnd(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=value;
    newNode->following=NULL;

    if(first==NULL){
        newNode->previous=NULL;
        first=newNode;
        return;
    }

    Node* ptr=first;
    while(ptr->following!=NULL){
        ptr=ptr->following;
    }
    ptr->following=newNode;
    newNode->previous=ptr;
}

void insertAfter(Node* prevNode,int value){
    if(prevNode==NULL){
        printf("Given node is NULL\n");
        return;
    }

    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=value;
    newNode->previous=prevNode;
    newNode->following=prevNode->following;

    if(prevNode->following!=NULL){
        prevNode->following->previous=newNode;
    }

    prevNode->following=newNode;
    printf("Inserted %d after %d\n",value,prevNode->val);
}

void deleteNode(int value){
    if(first==NULL)
        return;

    Node* ptr=first;
    while(ptr!=NULL&&ptr->val!=value){
        ptr=ptr->following;
    }

    if(ptr==NULL){
        printf("Value %d not found\n",value);
        return;
    }

    if(ptr->previous!=NULL){
        ptr->previous->following=ptr->following;
    }
    else{
        first=ptr->following;
    }

    if(ptr->following!=NULL){
        ptr->following->previous=ptr->previous;
    }

    printf("Deleted %d\n",value);
    free(ptr);
}

int main(){
    printf("Doubly Linked List Demo\n\n");

    addBegin(30);
    addBegin(20);
    addBegin(10);
    printf("After adding at beginning: ");
    show();

    addEnd(40);
    addEnd(50);
    printf("After adding at end: ");
    show();

    printf("\nInserting 25 after first->following (20):\n");
    insertAfter(first->following,25);
    show();

    printf("\nDeleting 25:\n");
    deleteNode(25);
    show();

    printf("Deleting 10:\n");
    deleteNode(10);
    show();

    return 0;
}
