/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:32:06 by cnahle            #+#    #+#             */
/*   Updated: 2024/08/23 13:32:06 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(tmp, args, i) || tmp < -2147483648 || tmp > 2147483647)
		{
			if (argc == 2)
			{
				int j = 0;
				while (args[j])
					free(args[j++]);
				free(args); 
			}
			ft_error("Error");
		}
		if ((args[i][0] == '+' || args[i][0] == '-') && !ft_isnum(args[i] + 1))
		{
			if (argc == 2)
			{
				int j = 0;
				while (args[j])
					free(args[j++]);
				free(args); 
			}
			ft_error("Error");
		}
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);  // Free each string in the split array
		free(args);           // Free the array itself
	}
}
