#include "../../includes/stack.h"

void display_data(stack **head)
{
    stack *temp = *head;

    while (temp)
    {
        printf("%d ", temp->element);
        temp = temp->next;
    }
    printf("\n");
}
