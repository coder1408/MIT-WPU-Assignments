#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

char stk[MAX], item, op;
int top = -1, newtop = -1;
char newstack[MAX][MAX];
char newitem;

bool isfull() 
{
    return top == MAX - 1;
}

bool newisfull(){
    if (newtop == MAX - 1){
        return true;
    }
    return false;
}

bool isempty() 
{
    return top == -1;
}

bool newisempty()
{
    if (newtop == -1){
        return true;
    }
    return false;
}

void push(char item)
{
    if (!isfull()) 
    {
        top = top + 1;
        stk[top] = item;
    }
    else
        printf("Stack is full\n");
}

void newpush(char *newitem)
{
    if (!newisfull()){
        newtop++;
        strcpy(newstack[newtop], newitem);
    }
    else printf("Stack if full\n");
}

void newpop(char item[20])
{
    if (!newisempty()){
        
        strcpy(item, newstack[newtop]);
        newtop--;
    
    }
    else{
        printf("Stack if empty\n");
    }

}

char pop() 
{
    if (!isempty()) 
    {
        item = stk[top];
        top = top - 1;
        return item;
    }
    else
    {
        printf("Stack is empty\n");
        return '\0';
    } 
}

int isp(char op)
{
    if(op == '+' || op == '-')
        return 1;
    
    if(op == '*' || op == '/')
        return 2;

    if(op == '^')
        return 3;

    else
        return 0;
}

int icp(char op)
{
    if(op == '+' || op == '-')
        return 1;
    
    if(op == '*' || op == '/')
        return 2;

    if(op == '^')
        return 3;

    if(op == '(')
        return 4;

    else
        return 0;
}

void in_post(char inexp[20])
{
    int k = 0, i = 0;
    char postexp[20];
    char tkn = inexp[i];

    while(tkn != '\0')
    {
        if (isalpha(tkn))
        {
            postexp[k] = inexp[i];
            k++;
        }
        else 
        {
            if (tkn == '(')
            {
                push(tkn);
            }
            else 
            {
                if (tkn == ')')
                {
                    while ((tkn = pop()) != '(')
                    {
                        postexp[k] = tkn;
                        k++;
                    }
                }
                else
                {
                    while (!isempty() && isp(stk[top]) >= icp(tkn))
                    {
                        postexp[k] = pop();
                        k++;
                    }
                    push(tkn);
                }

                
            }         
        }
        i++;
        tkn = inexp[i];    
    }

    while (!isempty())
    {
        postexp[k] = pop();
        k++;
    }
    postexp[k] = '\0';
    printf("Postfix expression is: %s\n", postexp);
}

void post_in(char post_exp[20]){
    int l = strlen(post_exp);
    char x[20], op2[20], op1[20], e1[20];
    for (int i = 0; i < l; i++){
        x[0] = post_exp[i];
        x[1] = '\0';
    
        if (isalpha(x[0]) != 0){
            newpush(x);
        }
        else{
            newpop(op2);
            newpop(op1);
            
            strcpy(e1, "(");
            strcat(e1, op1);
            strcat(e1, x);
            strcat(e1, op2);
            strcat(e1, ")");

            newpush(e1);
        }
    }
    char infix[20];
    newpop(infix);
    printf("%s", infix);
}

void post_pre(char post_exp[20]){
    int l = strlen(post_exp);
    char x[20], op2[20], op1[20], e1[20];
    for (int i = 0; i < l; i++){
        x[0] = post_exp[i];
        x[1] = '\0';
    
        if (isalpha(x[0]) != 0){
            newpush(x);
        }
        else{
            newpop(op2);
            newpop(op1);
            
            strcpy(e1, x);
            strcat(e1, op1);
            strcat(e1, op2);

            newpush(e1);
        }
    }
    char prefix[20];
    newpop(prefix);
    printf("%s", prefix);
}

void free_post()
{
    top = -1;
    memset(stk, 0, sizeof(stk));
}


int main() 
{
    char choice1;
    char inexp[20];

    printf("STACK OPERATIONS\n");

    do
    {
        printf("Enter operation to perform:\n 1. Push\n 2. Pop\n 3. Infix to Postfix\n 4. Postfix to Infix\n 5. Postfix to Prefix\n 6. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Enter item to push: \n");
            scanf(" %c", &item);
            push(item);
            break;
        case 2:
            item = pop();
            if (item != '\0') 
            {
                printf("Item popped is: %c\n", item);
            }
            break;
        
        case 3:
            printf("Enter infix expression: \n");
            scanf("%s",&inexp);
            in_post(inexp);
            break;
        case 4:
            printf("Enter postfix expression: \n");
            scanf("%s",&inexp);
            post_in(inexp);
            free_post();
            break;
        case 5:
            printf("Enter postfix expression: \n");
            scanf("%s",&inexp);
            post_pre(inexp);
            free_post();
            break;
        case 6:
            printf("Exiting...\n");
            break; 
        default:
            printf("Invalid choice\n");
            break;
        }

        printf("Do you want to continue more operations? (y/n): \n");
        scanf(" %c", &choice1);
    }
    while (choice1 == 'y' || choice1 == 'Y');

    return 0;
}
