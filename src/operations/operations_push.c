/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:27:41 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/11 19:17:56 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"


void pa(stack **a, stack **b, int called)
{
    stack *tmp;

    if (!b || !*b)
        return;

    tmp = *b;          // prendre le node en tête de B
    *b = (*b)->next;   // retirer ce node de B
    tmp->next = *a;    // l’ajouter au sommet de A
    *a = tmp;          // mettre à jour A

    if (!called)
        write(1, "pa\n", 3);
}

void pb(stack **a, stack **b, int called)
{
    stack *tmp;

    if (!a || !*a)
        return;

    tmp = *a;          // prendre le node en tête de A
    *a = (*a)->next;   // retirer ce node de A
    tmp->next = *b;    // l’ajouter au sommet de B
    *b = tmp;          // mettre à jour B

    if (!called)
        write(1, "pb\n", 3);
}
