/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:37:10 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/14 13:34:23 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

#define BUFFER_SIZE 32

char	*read_operations(int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		r;
	char	*res;

	res = NULL;
	r = read(fd, tmp, BUFFER_SIZE);
	while (r > 0)
	{
		tmp[r] = '\0';
		res = ft_strjoin(res, tmp);
		if (!res)
			return (NULL);
		r = read(fd, tmp, BUFFER_SIZE);
	}
	if (r < 0)
	{
		ft_fr(res);
		return (NULL);
	}
	return (res);
}

char	*extract_operation(char *buffer)
{
	char	*newline;
	char	*op;
	int		len;

	if (!buffer)
		return (NULL);
	newline = strchr(buffer, '\n');
	if (!newline)
		return (NULL);
	len = newline - buffer;
	if (len <= 0)
		return (NULL);
	op = (char *)calloc(len + 1, sizeof(char));
	if (!op)
		return (NULL);
	strncpy(op, buffer, len);
	return (op);
}

char	*update_buffer(char *buffer)
{
	char	*newline;
	char	*tmp;

	if (!buffer)
		return (NULL);
	newline = strchr(buffer, '\n');
	if (!newline)
		return (NULL);
	tmp = strdup(newline + 1);
	ft_fr(buffer);
	return (tmp);
}

char	*get_next_operation_from_buffer(char **buffer)
{
	char	*op;

	if (!buffer || !*buffer || !**buffer)
		return (NULL);
	op = extract_operation(*buffer);
	if (!op)
	{
		ft_fr(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	*buffer = update_buffer(*buffer);
	return (op);
}

void	execute_operations(t_stack **a, t_stack **b)
{
	char	*buffer;
	char	*op;

	buffer = read_operations(STDIN_FILENO);
	if (!buffer || !*buffer)
		return ;
	while (op != NULL)
	{
		if (!apply_operation(a, b, op))
		{
			write(2, "Error\n", 6);
			ft_fr(op);
			break ;
		}
		ft_fr(op);
		op = get_next_operation_from_buffer(&buffer);
	}
	ft_fr(buffer);
}
