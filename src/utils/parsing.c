/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:10:19 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/06 17:27:03 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	k;

	j = 0;
	i = 1;
	while(i<ac)
	{
		char	**digits = ft_split(argv[i],' ');
		if(!digits)
			return 0;
		j = 0;
		while(digits[j])
		{
			if(!is_number(token[j]) || !insert_value(a,ft_atol(token[j])))
			{
				write(2, "Error\n", 6);
				ft_free(digits);
    				return 0;    
			}

		}
		ft_free(digits);
        	i++;
	}
	return 1;
}


