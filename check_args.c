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
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	check_argument(char *arg, char **args, int index, int flag)
{
	long	tmp;

	(void)args;
	(void)index;
	tmp = ft_atoi(arg);
	if (!ft_isnum(arg) || ft_contains(tmp, args, index)
		|| tmp < -2147483648 || tmp > 2147483647)
	{
		if (!flag)
			free_args(args);
		ft_error("Error");
	}
	if ((arg[0] == '+' || arg[0] == '-') && !ft_isnum(arg + 1))
	{
		if (!flag)
			free_args(args);
		ft_error("Error");
	}
}

void	process_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
		flag = 1;
	}
	while (args[i])
	{
		check_argument(args[i], args, i, flag);
		i++;
	}
	if (argc == 2)
		free_args(args);
}
