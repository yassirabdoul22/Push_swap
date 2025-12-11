/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:05:57 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/11 19:37:39 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <stdio.h>
#include <string.h> 
# include <unistd.h>
# include <limits.h>
# include "stdint.h"

#define BUFFER_SIZE 32

typedef struct s_stack
{
    int             element;
    int             cost_a;
    int             cost_b;
    
    int             index;
    struct s_stack *target;
    struct s_stack *next;
}   stack;

stack   *creatstack(int element);
size_t	ft_strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
int     insert_at_bottom(stack **head, int element); 
void execute_operations(stack **a, stack **b);
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
int apply_operation(stack **a, stack **b, const char *op);

void    sort_three(stack **a);
void    sort_five(stack **a, stack **b);
void    sort_big(stack **a, stack **b);
int     find_min(stack *a);
int     find_index(stack *a, int value);

void    sa(stack **a, int iscalled);
void    sb(stack **b, int iscalled);
void    ss(stack **a, stack **b,int check);

void    pa(stack **a, stack **b,int called);
void    pb(stack **a, stack **b,int called);

void    ra(stack **a, int iscalled);
void    rb(stack **b, int iscalled);
void    rr(stack **a, stack **b,int check);

void    rra(stack **a, int iscalled);
void    rrb(stack **b, int iscalled);
void    rrr(stack **a, stack **b,int check);

char *get_next_operation_from_buffer(char **buffer);
int     is_number(char *str);
int     already_exist(stack *stk, int value);
long    ft_atol(char *str);
int     insert_value(stack **a, char *str);
int     parse_args(stack **a, int ac, char **argv);
void    ft_free(char **fr);
char    **ft_split(char *str, char c);
int     is_separator(char c, char sep);
int     count_words(char *str, char sep);
char    *malloc_word(char *str, char sep);


int     ft_strchr(char *s, char c);
size_t  ft_strlen(char *s);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strdup(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strjoin(char *s1, char *s2);


char    *read_operations(int fd);
char    *extract_operation(char *buffer);
char    *update_buffer(char *buffer);
char    *get_next_operation_from_buffer(char **buffer);


char    *read_operations(int fd);
char    *extract_operation(char *buffer);
char    *update_buffer(char *buffer);
char    *get_next_operation_from_buffer(char **buffer);

stack *find_smallest(stack *a);
void find_target(stack *a, stack *b);
void calculate_costs(stack *a, stack *b);
stack *find_cheapest(stack *b);
void double_move(stack **a, stack **b, stack *n);
void execute_move(stack **a, stack **b, stack *n);
void turk_sort(stack **a, stack **b);

// Utilitaires
int ft_abs(int cost);
int get_cost(int pos, int size);
int find_position(stack *s, int index);
void reset_index(stack *a);
void assign_index(stack *a);
void print_stack(stack *s, char *name);
#endif
