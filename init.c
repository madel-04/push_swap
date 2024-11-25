/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:30:02 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 11:30:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] + '0');
		i++;
	}
	return (num * isneg);
}
/* Atoi pero para long num */

void	stack_init(t_stack_node **a, char **av, bool flag_ag_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ag_2);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ag_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag_ag_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_ag_2)
		free_matrix(av);
}
