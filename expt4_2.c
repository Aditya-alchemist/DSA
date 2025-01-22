#include <stdio.h>
#include <stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node* link;
};

struct node* createnode(int coefficient, int exponent) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coefficient = coefficient;
    newnode->exponent = exponent;
    newnode->link = NULL;
    return newnode;
}

struct node* addPolynomials(struct node* head1, struct node* head2) {
    struct node* result = NULL; 
    struct node** tail = &result; 

    while (head1 != NULL || head2 != NULL) {
        int coeff = 0, exp;

        if (head1 != NULL && (head2 == NULL || head1->exponent > head2->exponent)) {
            coeff = head1->coefficient;
            exp = head1->exponent;
            head1 = head1->link;
        } else if (head2 != NULL && (head1 == NULL || head2->exponent > head1->exponent)) {
            coeff = head2->coefficient;
            exp = head2->exponent;
            head2 = head2->link;
        } else { 
            coeff = head1->coefficient + head2->coefficient;
            exp = head1->exponent;
            head1 = head1->link;
            head2 = head2->link;
        }

        if (coeff != 0) {
            *tail = createnode(coeff, exp);
            tail = &((*tail)->link);
        }
    }
    return result;
}

void displayPolynomial(struct node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    while (head != NULL) {
        printf("%d*x^%d", head->coefficient, head->exponent);
        if (head->link != NULL) {
            printf(" + ");
        }
        head = head->link;
    }
    printf("\n");
}

int main() {
    struct node* head1 = createnode(5, 3);
    head1->link = createnode(4, 2);
    head1->link->link = createnode(6, 0);

    struct node* head2 = createnode(3, 3);
    head2->link = createnode(2, 1);
    head2->link->link = createnode(1, 0);

    printf("1st Polynomial: ");
    displayPolynomial(head1);

    printf("2nd Polynomial: ");
    displayPolynomial(head2);

    
    struct node* result = addPolynomials(head1, head2);

    
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
