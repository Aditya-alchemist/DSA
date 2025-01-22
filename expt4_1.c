#include <stdio.h>
#include <stdlib.h>

struct node{
   int coefficient;
   int exponent;
   struct node* link;

};

struct node* createnode(int coefficient,int exponent){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->coefficient = coefficient;
        newnode->exponent = exponent;
        newnode->link=NULL;

        return newnode;
}



int main( ){
   
 int v1,ex1,v2,ex2,v3,ex3;

 printf("enter the first polynomial coefficent:");
 scanf("%d",&v1);
 printf("enter the exponent of first variable: ");
 scanf("%d",&ex1);
 printf("enter the second polynomial coefficent:");
 scanf("%d",&v2);
 printf("enter the exponent of second variable: ");
 scanf("%d",&ex2);
 printf("enter the third polynomial coefficent:");
 scanf("%d",&v3);
 printf("enter the exponent of third variable: ");
 scanf("%d",&ex3);
     struct node* head = createnode(v1,ex1);
    head->link = createnode(v2,ex2);
    head->link->link = createnode(v3,ex3);


     printf("Original list: ");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d,%d ->", temp->coefficient,temp->exponent);
        temp = temp->link;
    }
    printf("NULL\n");




}


   