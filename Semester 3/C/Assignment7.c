#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 20
int stk[MAX], top = -1, item;
char post[MAX];

bool isfull() 
{
    return top == MAX - 1;
}

bool isempty() 
{
    return top == -1;
}

void push(int item)
{
    if (!isfull()) 
    {
        top = top + 1;
        stk[top] = item;
    }
    else
        printf("Stack is full\n");
}

int pop() 
{
    if (!isempty()) 
    {
        item = stk[top];
        top = top - 1;
        return item;
    }
    else
        printf("Stack is empty\n");
    
    return 0; 
}

int calc(int c1, int c2, char op)
{
    switch(op)
    {
        case '+': return c1 + c2;
            break;
        case '-': return c1 - c2;
            break;
        case '*': return c1 * c2;
            break;
        case '/': return c1 / c2;
            break;
        case '^': return pow(c2, c1);
            break;
        default: return 1;
    }

    return 0;
}

void eval(char post[MAX])
{
    int i, op1, op2, ans, val;
    for (i = 0; post[i] != '\0'; i++)
    {
        if (isalpha(post[i]) != 0)
        {
            printf("Enter the value of %c: ", post[i]);
            scanf("%d", &val);
            push(val);
        }
        else
        {
            op1 = pop();
            op2 = pop();
            ans = calc(op1, op2, post[i]);
            push(ans);
        }        
    }
    printf("Answer: %d\n", stk[top]);
}

int main()
{
    printf("Enter the postfix expression: ");
    scanf("%s", &post);
    eval(post);

    return 0;
}