#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exp;
    struct poly *next;
};

void create(struct poly *H)
{

    struct poly *temp = H;
    char n = 'y';

    while (n == 'y')
    {
        struct poly *curr = (struct poly *)malloc(sizeof(struct poly));

        printf("Enter coefficient: ");
        scanf("%d", &curr->coeff);
        printf("Enter exponent: ");
        scanf("%d", &curr->exp);

        curr->next = H;
        temp->next = curr;
        temp = curr;

        printf("Create another term? (y/n): ");
        scanf(" %c", &n);
    }
}

void display(struct poly *H)
{
    if (H->next == H)
    {
        printf("List is empty\n");
    }
    else
    {
        struct poly *temp = H->next;
        while (temp != H)
        {
            printf("%dx^%d ", temp->coeff, temp->exp);
            if (temp->next != H)
                printf("+ ");
            temp = temp->next;
        }
        printf("\n");
    }
}

void addition(struct poly *H1, struct poly *H2)
{
    create(H1);
    display(H1);
    create(H2);
    display(H2);

    struct poly *H3, *t1, *t2, *t3, *temp;
    H3 = (struct poly *)malloc(sizeof(struct poly));
    H3->next = H3;
    t3 = H3;
    t1 = H1->next;
    t2 = H2->next;

    while (t1->exp != -1 || t2->exp != -1)
    {
        temp = (struct poly *)malloc(sizeof(struct poly));

        if (t1->exp == t2->exp)
        {
            temp->coeff = t1->coeff + t2->coeff;
            temp->exp = t1->exp;
            t1 = t1->next;
        }
        else if (t1->exp > t2->exp)
        {
            temp->coeff = t1->coeff;
            temp->exp = t1->exp;
            t1 = t1->next;
        }
        else
        {
            temp->coeff = t2->coeff;
            temp->exp = t2->exp;
            t2 = t2->next;
        }

        t2 = t2->next;
        t3->next = temp;
        t3 = temp;
        temp->next = H3;
    }

    printf("Result of addition: ");
    display(H3);
}

int main()
{
    struct poly *H1, *H2;
    H1 = (struct poly *)malloc(sizeof(struct poly));
    H2 = (struct poly *)malloc(sizeof(struct poly));
    H1->exp = -1;
    H2->exp = -1;
    H1->next = H1;
    H2->next = H2;
    addition(H1, H2);

    return 0;
}
