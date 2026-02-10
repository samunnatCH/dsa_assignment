#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* link;
}Node;

Node* head=NULL;

void append(int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->value=val;
    newnode->link=NULL;

    if(head==NULL){
        head=newnode;
        return;
    }

    Node* temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newnode;
}

void prepend(int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->value=val;
    newnode->link=head;
    head=newnode;
}

void printForward(){
    Node* temp=head;
    printf("[ ");
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->link;
    }
    printf("]\n");
}

void printReverseHelper(Node* node){
    if(node==NULL)
        return;
    printReverseHelper(node->link);
    printf("%d ",node->value);
}

void printReverse(){
    printf("[ ");
    printReverseHelper(head);
    printf("]\n");
}

int main(){
    printf("Linked List Reverse Print\n");

    append(5);
    append(10);
    append(15);
    append(20);
    append(25);

    printf("Forward: ");
    printForward();
    printf("Reverse: ");
    printReverse();

    printf("\n");

    head=NULL;
    prepend(100);
    prepend(80);
    prepend(60);
    prepend(40);
    prepend(20);

    printf("Forward: ");
    printForward();
    printf("Reverse: ");
    printReverse();

    return 0;
}
