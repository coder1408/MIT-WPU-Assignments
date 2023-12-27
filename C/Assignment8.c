#include <stdio.h>

#define MAX 4
int queue[MAX];
int front = -1, rear = -1;

int isfull()
{
    if(rear == MAX - 1)
        return 1;
    else
        return 0;
}

int enqueue(int item)
{
    if(isfull())
    {
        printf("Queue is full\n");
        return -1;
    }
    else
    {
        if (front == -1)
            front = 0; 
        rear = rear + 1;
        queue[rear] = item;
        return 0;
    }
}


int isempty()
{
    if(front == rear)
        return 1;
    else
        return 0;
}

int dequeue()
{
    int item;
    if(isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        item = queue[front];
        front = front + 1;
        return item;
    }
}

int peekfront()
{
    if(isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
        return queue[front];
}

int peekrear()
{
    if(isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
        return queue[rear];
}

void display()
{
    int i;
    if (isempty())
        printf("Queue is empty\n");
    else
    {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++)
            printf("%d\n", queue[i]);
    }
}


int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek front\n");
        printf("4. Peek rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if(item != -1)
                    printf("The deleted element is %d\n", item);
                display();
                break;
            case 3:
                item = peekfront();
                if(item != -1)
                    printf("The front element is %d\n", item);
                break;
            case 4:
                item = peekrear();
                if(item != -1)
                    printf("The rear element is %d\n", item);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}