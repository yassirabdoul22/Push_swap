
#include "../../includes/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

void    ra(stack **a)
{
    if(!a || !*a || !(*a)->next)
        return;
    stack *first;
    stack *last;
    first = *a;
    last = *a;
    while(last->next)
        last = last->next;
    *a = first->next;
    first->next = NULL;
    last->next=first;
    write(1,"ra ",3);    
}



void    rb(stack **b)
{
    if(!b || !*b || !(*b)->next)
        return;
    stack *first;
    stack *last;
    
    first = *b;
    last = *b;
    while(last->next)
        last = last->next;
    *b = first->next;
    first->next=NULL;
    last->next=first;
    write(1,"rb ",3);
}


void    rr(stack **a,stack **b)
{
    ra(a);
    rb(b);
}


stack *new(int x)
{
    stack *n = malloc(sizeof(stack));
    n->element = x;
    n->next = NULL;
    return n;
}

void print_stack(char *name, stack *s)
{
    printf("%s: ", name);
    while (s)
    {
        printf("%d ", s->element);
        s = s->next;
    }
    printf("\n");
}

int main()
{
    // ------- Création de la pile A -------
    stack *a = new(5);
    a->next = new(2);
    a->next->next = new(8);
    a->next->next->next = new(1);

    // ------- Création de la pile B -------
    stack *b = new(9);
    b->next = new(4);
    b->next->next = new(7);

    printf("=== Avant rotation ===\n");
    print_stack("A", a);
    print_stack("B", b);

    printf("\n-- ra --\n");
    ra(&a);
    print_stack("A", a);

    printf("\n-- rb --\n");
    rb(&b);
    print_stack("B", b);

    printf("\n-- rr --\n");
    rr(&a, &b);
    print_stack("A", a);
    print_stack("B", b);

    return 0;
}