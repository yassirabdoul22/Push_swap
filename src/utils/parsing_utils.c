/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:32:03 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/06 17:52:41 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(stack *a,int value)
{
	int i;
	if(!str || !*str)
		return 0;
	if(str[0] = '-' || str[0]='+')
		i++;
	if(!str[i])
		return 0;
	while(str[i])
	{
		if(str[i]<'0' || str[i]>'9')
			return 0;
		i++;
	}
	return 1;

}

int	already_exist(stack *stk,int value)
{
	while(stk)
	{
		if(stk->element == value)
			return 1;
		stk = stk->next;
	}
	return 0;
}

long	ft_atol(char *str)
{
	long res;
	int sign;
	int i;

	res = 0;
	i = 0;
	sign = 1;
	if(!str)
		return 0;
	if(str[0]=='-' || str[0]=='+')
	{
		if(str[0] == '-')
			sign = -1;
		i++;
	}
	while(str[i])
	{
		res = res*10 + (str[i]-'0');
		i++;
	}
	return res*sign;
}

int	insert_value(stack **a,char *str)
{
	long val;
	int ival;

	if(!is_number(str))
		return 0;
	val = ft_atol(str);
	if(val>INT_MAX || val <INT_MAX)
		return 0;
	ival = (int)val;
	if(already_exist(*a,ival))
		return 0;
	isert_at_top(a,ival);
	return 1;	

}
