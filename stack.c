#include <stdio.h>
#include<stdlib.h>

typedef struct  stack{
    int element;
    struct stack *next;
}stack;



stack   *creatstack(int element)
{
    stack   *stack = malloc(sizeof(stack));
    if(!stack)
        return NULL;
    stack->element = element;
    stack->next=NULL;
    return stack;
}

//adding element at the top of the stack 

int    isert_at_top(stack **head,int element)
{
    stack * stack = creatstack(element);
    if(!stack)
        return -1;
    if(!*head)
    {
        *head = stack;
        return 0;
    }
    stack->next = *head;
    *head = stack;
    return 0;
}
//this function remove the first element of the stack
void    Remove_first(stack **head)
{
    stack *temp = *head;
    *head = (*head)->next;
    free(temp);
}
//this function check if the stack is empty
int check_stack(stack **head)
{   
    return *head==NULL;
}   

int pop(stack **stack)
{
    if(check_stack(stack))
    {
         printf("Stack Overflow!\n");
         return -1;
    }
    int value = (*stack)->element;
    Remove_first(stack);
    return value;
}
void    push(stack **head , int element)
{
    if(isert_at_top(head,element))
        printf("Stack Overflow!\n");
}

int peek(stack **stack)
{   
    if(!check_stack(stack))
        return (*stack)->element;
    return -1;
}

void    display_data(stack **head)
{
    stack *temp = *head;
    while(temp)
    {
        printf("%d ",temp->element);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    stack* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    printf("Stack: ");
    display_data(&stack);
    pop(&stack);
    pop(&stack);
    printf("\nStack: ");
    display_data(&stack);

    return 0;
}



