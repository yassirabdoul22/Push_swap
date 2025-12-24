/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:05:57 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/20 21:09:32 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_stack
{
	int					element;
	int					cost_a;
	int					cost_b;
	int					index;
	struct s_stack		*target;
	struct s_stack		*next;
}	t_stack;

/* Stack utils */
t_stack	*create_stack(int element);
int		insert_at_bottom(t_stack **head, int element);
int		insert_at_top(t_stack **head, int element);
int		stack_size(t_stack *s);

int		ft_is_sorted(t_stack *a);
void	remove_first(t_stack **head);
/* Parsing */
int		is_number(char *str);
int		already_exist(t_stack *stk, int value);
long	ft_atol(char *str);
int		insert_value(t_stack **a, char *str);
int		parse_args(t_stack **a, int ac, char **argv);
/* Small sorts */
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	ft_fr(char *ptr);
/* Operations */
void	sa(t_stack **a, int iscalled);
void	sb(t_stack **b, int iscalled);
void	ss(t_stack **a, t_stack **b, int check);
void	pa(t_stack **a, t_stack **b, int called);
void	pb(t_stack **a, t_stack **b, int called);
void	ra(t_stack **a, int iscalled);
void	rb(t_stack **b, int iscalled);
void	rr(t_stack **a, t_stack **b, int check);
void	rra(t_stack **a, int iscalled);
void	rrb(t_stack **b, int iscalled);
void	rrr(t_stack **a, t_stack **b, int check);

int		apply_operation(t_stack **a, t_stack **b, const char *op);

/* Turk sort */
t_stack	*find_smallest(t_stack *a);
t_stack	*find_in_chunk(t_stack *a, int min, int max);
void	assign_index(t_stack *a);
void	execute_operations(t_stack **a, t_stack **b);
int		get_chunk_size(int size);
void	update_chunk_limits(int *min, int *max, int chunk);
void	find_target(t_stack *a, t_stack *b);
void	calculate_costs(t_stack *a, t_stack *b);
t_stack	*find_cheapest(t_stack *b);
void	double_move(t_stack **a, t_stack **b, t_stack *n);
void	execute_move(t_stack **a, t_stack **b, t_stack *n);
void	turk_sort(t_stack **a, t_stack **b);
void	bring_to_top(t_stack **a, int index);
void	single_move(t_stack **a, t_stack **b, t_stack *n);
void	final_align(t_stack **a);
int		ft_abs(int n);
int		get_cost(int pos, int size);
int		find_position(t_stack *s, int index);

/* Libft */
void	ft_free(char **fr);
char	**ft_split(char *str, char c);
int		is_separator(char c, char sep);
int		count_words(char *str, char sep);
char	*malloc_word(char *str, char sep);
char	*read_operations(int fd);
char	*extract_operation(char *buffer);
char	*update_buffer(char *buffer);
char	*get_next_operation_from_buffer(char **buffer);

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strncpy(char *dst, const char *src, int n);
#endif
