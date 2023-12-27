#include <stdio.h>
#include <stdlib.h>

struct node
{
    int prn;
    char name[50];
    struct node *next; 
};


struct node *head;

void create()
{
    struct node *temp = head;
    char choice;

    do
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter PRN: ");
        scanf("%d", &curr->prn);
        printf("Enter Name: ");
        scanf("%s", curr->name);

        curr->next = NULL;
        temp->next = curr;
        temp = curr;

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y');
}

void display()
{
    struct node *curr = head->next;
    if (curr == NULL)
        printf("List is empty\n");
    else
    {
        while (curr != NULL)
        {
            printf("PRN: %d\n", curr->prn);
            printf("Name: %s\n", curr->name);
            curr = curr->next;
        }
    }
}

int len()
{
    int i = 0;
    struct node *curr = head->next;

    while (curr != NULL)
    {
        i++;
        curr = curr->next;
    }
    return i;
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    create();

    display();

    return 0;
}
