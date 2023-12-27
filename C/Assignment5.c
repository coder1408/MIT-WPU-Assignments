#include <stdio.h>
#include <stdlib.h>

struct node
{
    int prn;
    char name[50];
    struct node *next;
};

int len();
void display();


void freeList(struct node *head)
{
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = (head)->next;
        free(temp);
    }
}

void create(struct node *H)
{
    H->next = NULL;
    struct node *temp = H;
    char n = 'y';
    while(n == 'y')
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        int prn;

        printf("Enter prn: ");
        scanf("%d", &prn);
        printf("Enter name: ");
        scanf("%s", &curr->name);

        curr->prn = prn;
        curr->next = NULL;
        temp->next = curr;
        temp = curr;

        printf("Create another node(y/n)?: ");
        scanf(" %c", &n);
    }  
}

void display(struct node *H)
{
    if (H->next == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nPRN\t|\tName\t|\tDesignation");
        struct node *curr = H->next;
        if (curr == H->next)
        {
             printf("\n%d\t|\t%s\t|\tPresident", curr->prn, curr->name);        
        }
        
        curr = curr->next;

        while(curr != NULL){
            
            if (curr->next == NULL)
            {
                printf("\n%d\t|\t%s\t|\tSecretary \n", curr->prn, curr->name);
            }
            else
            {
                printf("\n%d\t|\t%s\t|\tMember",  curr->prn, curr->name);
            }
            
            curr = curr->next;
        }
    }
}

int len(struct node *head)
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

void insertbypos(struct node *head)
{
    display(head);

    struct node *nnode, *curr;
    int i = 1, pos, k;
    char choice;

    curr = head;

    do
    {
        nnode = (struct node *)malloc(sizeof(struct node));

        if (nnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter PRN for the new node: ");
        scanf("%d", &nnode->prn);

        printf("Enter Name for the new node: ");
        scanf("%s", nnode->name);

        printf("Enter position to insert: ");
        scanf("%d", &pos);

        k = len(head);

        if (pos > k + 1)
        {
            printf("Position is out of bounds\n");
        }
        else
        {
            i = 1;
            while (curr != NULL && i < pos)
            {
                i++;
                curr = curr->next;
            }

            nnode->next = curr->next;
            curr->next = nnode;
        }

        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } 
    while (choice == 'y' || choice == 'Y');

    display(head);
}

void deletebypos(struct node *head)
{
    display(head);

    struct node *prev, *curr, *temp;
    int pos, ctr, k;
    char choice;

    prev = head;
    curr = (head)->next;

    do
    {
        printf("Enter position to delete: ");
        scanf("%d", &pos);

        k = len(head);

        if (k < pos)
        {
            printf("Position is out of bounds\n");
        }
        else
        {
            ctr = 1;
            while (ctr < pos && curr != NULL)
            {
                ctr++;
                prev = curr;
                curr = curr->next;
            }

            temp = curr;
            prev->next = curr->next;
            curr->next = NULL;
            free(temp);
        }

        printf("Do you want to delete another node? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    display(head);
        
}

void reverse(struct node *head)
{
    struct node *prev, *curr, *future;

    prev = NULL;
    curr = head->next;

    while (curr != NULL)
    {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }

    head->next = prev;
    display(head);
}

void sort(struct node *head)
{
    struct node *curr, *prev, *temp, *next;
    int length = len(head);

    for(int i = 1; i < length; i++)
    {
        prev = head;
        curr = (head)->next;
        
        for(int j = 0; j < length - i; j++)
        {
            temp = curr ->next;

            if(curr->prn > temp->prn)
            {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

void merge(struct node *head1, struct node *head2)
{
    printf("Enter the first list:\n");
    create(head1);
    printf("Enter the second list:\n");
    create(head2);
    sort(head1);
    sort(head2);
    

    struct node *curr1, *curr2, *temp;
    int flag = 0;

    curr1 = (head1)->next;
    curr2 = (head2)->next;

    if(curr1->prn < curr2->prn)
    {
        temp = head1;
        flag = 1;
    }
    else
    {
        temp = head2;
        flag = 0;
    }

    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1->prn < curr2->prn)
        {
            temp->next = curr1;
            temp = curr1;
            curr1 = curr1->next;
        }
        else
        {
            temp->next = curr2;
            temp = curr2;
            curr2 = curr2->next;
        }
    }

    if(curr1 == NULL)
    {
        temp->next = curr2;
    }
    if(curr2 == NULL)
    {
        temp->next = curr1;
    }
    if (flag == 1)
    {
        display(head1);
    }
    else
    {
        display(head2);
    }
    
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    int choice;
    char choice2;

    struct node *head1, *head2;
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));

    do
    {
        printf("1. Create\n2. Insert by position\n3. Delete by Position\n4. Reverse the List\n5. Sort\n6. Merge two lists\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            freeList(head);
            create(head);
            display(head);
            break;
        case 2:
            insertbypos(head);
            break;
        case 3:
            deletebypos(head);
            break;
        case 4:
            reverse(head);
            break;
        case 5:
            sort(head);
            display(head);
            break;
        case 6:
            merge(head1, head2);
            break;
        case 7:
            printf("Exiting..\n");
            exit(0);
            break;
        default:
            printf("Choice not available!");
            break;
        }

        printf("Do you want to see more options?");
        scanf(" %c", &choice2);
    } 
    while (choice2 == 'y' || choice2 == 'Y');
    
    
}
