/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:05:57 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/10 17:08:06 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int             element;
    struct s_stack *next;
    int             index;
}   stack;

stack   *creatstack(int element);

int     insert_at_bottom(stack **head, int element); 

int     stack_size(stack *a);
int     ft_stack_size(stack *s);
int     ft_is_sorted(stack *a);
int     check_stack(stack **head);
void    Remove_first(stack **head);
int insert_at_top(stack **head, int element);
int     pop(stack **st);
void    push(stack **head, int element);
int     peek(stack **st);

void    display_data(stack **head);

void    sort_three(stack **a);
void    sort_five(stack **a, stack **b);
void    sort_big(stack **a, stack **b);
int     find_min(stack *a);
int     find_index(stack *a, int value);

void    sa(stack **a, int iscalled);
void    sb(stack **b, int iscalled);
void    ss(stack **a, stack **b);

void    pa(stack **a, stack **b);
void    pb(stack **a, stack **b);

void    ra(stack **a, int iscalled);
void    rb(stack **b, int iscalled);
void    rr(stack **a, stack **b);

void    rra(stack **a, int iscalled);
void    rrb(stack **b, int iscalled);
void    rrr(stack **a, stack **b);

int     is_number(char *str);
int     already_exist(stack *stk, int value);
long    ft_atol(char *str);
int     insert_value(stack **a, char *str);
int     parse_args(stack **a, int ac, char **argv);
void    ft_free(char **elements);
char    **ft_split(char *str, char c);
int     is_separator(char c, char sep);
int     count_words(char *str, char sep);
char    *malloc_word(char *str, char sep);

#endif
