/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:38:35 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/10 20:58:09 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/stack.h"
#include <string.h>


int ft_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int apply_operation(stack **a, stack **b, const char *op)
{
    if (ft_strcmp(op, "sa") == 0) sa(a, 1);
    else if (ft_strcmp(op, "sb") == 0) sb(b, 1);
    else if (ft_strcmp(op, "ss") == 0) ss(a, b);
    else if (ft_strcmp(op, "pa") == 0) pa(a, b);
    else if (ft_strcmp(op, "pb") == 0) pb(a, b);
    else if (ft_strcmp(op, "ra") == 0) ra(a, 1);
    else if (ft_strcmp(op, "rb") == 0) rb(b, 1);
    else if (ft_strcmp(op, "rr") == 0) rr(a, b);
    else if (ft_strcmp(op, "rra") == 0) rra(a, 1);
    else if (ft_strcmp(op, "rrb") == 0) rrb(b, 1);
    else if (ft_strcmp(op, "rrr") == 0) rrr(a, b);
    else return 0; 
    return 1;
}

// void print_stack(stack *s, char name)
// {
//     printf("Stack %c: ", name);
//     while (s)
//     {
//         printf("%d ", s->element);
//         s = s->next;
//     }
//     printf("\n");
// }



int main(int argc, char **argv)
{
    stack *a = NULL;
    stack *b = NULL;

    if (argc < 2)
        return 0;
    if (!parse_args(&a, argc, argv))
    {
        write(1,"Error\n",6);
        return -1;
    }
    execute_operations(&a, &b);
    if (ft_is_sorted(a) && b == NULL)
        write(1,"OK\n",3);
    else
        write(1,"KO\n",3);
    while(a) Remove_first(&a);
    while(b) Remove_first(&b);
    return 0;
}

