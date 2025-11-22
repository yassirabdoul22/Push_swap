#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
    int             element;
    struct s_stack *next;
}   stack;

stack *creatstack(int element);
int    isert_at_top(stack **head, int element);


void   Remove_first(stack **head);
int    pop(stack **stack);
void   push(stack **head, int element);
int    peek(stack **stack);
int    check_stack(stack **head);

void   display_data(stack **head);

#endif
