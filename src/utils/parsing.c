/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:10:19 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/09 19:48:00 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_free(char **elements)
{
	int	k;
	
	k = 0;
	while(elements[k]!=NULL)
	{
		free(elements[k]);
		k++;
	}
	free(elements);
}

int parse_args(stack **a,int ac,char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = ac -1;
	while(i >0)
	{
		char	**digits = ft_split(argv[i],' ');
		if(!digits)
			return 0;
		j = 0;
		while(digits[j])
		{
			while (digits[j])
			{
    			if (!is_number(digits[j]) || !insert_value(a, digits[j]))
    			{
      				  write(2, "Error\n", 6);
       				  ft_free(digits);
       			      return 0;
  			   }	
    			j++;
			}

		}
		ft_free(digits);
        	i--;
	}
	return 1;
}


