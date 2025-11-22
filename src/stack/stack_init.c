#include "../../includes/stack.h"

stack *creatstack(int element)
{
    stack *s = malloc(sizeof(stack));
    if (!s)
        return NULL;
    s->element = element;
    s->next = NULL;
    return s;
}

int isert_at_top(stack **head, int element)
{
    stack *node = creatstack(element);
    if (!node)
        return -1;
    node->next = *head;
    *head = node;
    return 0;
}
