#include "../../includes/stack.h"

// int stack_size(stack *a)
// {
//     int i;

//     i = 0;
//     while(a)
//     {
//         i++;
//         a = a->next;
//     }    
//     return (i);
// }
// void reset_index(stack *a)
// {
//     while (a)
//     {
//         a->index = -1;
//         a = a->next;
//     }
// }

void assign_index(stack *a)
{
    int size = stack_size(a);
    if (size == 0)
        return;

    int *arr = malloc(sizeof(int) * size);
    if (!arr)
        return; // vérifie l'allocation mémoire

    stack *tmp = a;
    int i = 0;

    // Copier les éléments dans un tableau
    while (tmp)
    {
        arr[i++] = tmp->element;
        tmp = tmp->next;
    }

    // Tri simple du tableau (tri à bulles)
    for (int j = 0; j < size - 1; j++)
    {
        for (int k = j + 1; k < size; k++)
        {
            if (arr[j] > arr[k])
            {
                int t = arr[j];
                arr[j] = arr[k];
                arr[k] = t;
            }
        }
    }

    // Assigner l’index à chaque élément selon sa position dans le tableau trié
    tmp = a;
    while (tmp)
    {
        for (i = 0; i < size; i++)
        {
            if (tmp->element == arr[i])
            {
                tmp->index = i;
                break;
            }
        }
        tmp = tmp->next;
    }

    free(arr);
}
int ft_is_sorted(stack *a)
{
    while (a && a->next)
    {
        if (a->element > a->next->element)
            return 0;
        a = a->next;
    }
    return 1;
}
// int     ft_abs(int cost)
// {
//     if(cost < 0)
//         return -cost;
//     return cost;
// }
// int get_cost (int pos , int size)
// {
//     if(pos <= size / 2)
//         return pos;
//     return -(size - pos);
// }

// int find_position(stack *s,int index)
// {
//     int pos;

//     pos = 0;
//     while(s)
//     {
//         if(s->index == index)
//             return pos;
//         pos++;
//         s = s->next;
//     }
//     return 0;
// }