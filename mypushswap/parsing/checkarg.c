/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:14:32 by yusman            #+#    #+#             */
/*   Updated: 2023/05/21 21:46:33 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*argcheck(char **av)
{
	int		i;
	int		j;
	int		k;
	char	*args;

	i = 1;
	j = 0;
	while (av[i])
		j = j + ft_strlen(av[i++]);
	args = malloc(j + i - 1);
	i = 1;
	j = 0;
	while (av[i])
	{
		k = 0;
		while (av[i][k])
			args[j++] = av[i][k++];
		if (av[i + 1])
			args[j++] = ' ';
		i++;
	}
	args[j] = '\0';
	return (args);
}

int	is_digit(int c)
{
	if (!((c >= '0' && c <= '9') || (c == ' ') || c == '-' || c == '+'))
		return (1);
	return (0);
}

void	letters(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (is_digit(args[i]))
		{
			free(args);
			ft_putstr_fd("1. Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
void	refactor_ac(t_stack *a, t_stack *b, char **av)
{
	char	*args;
	char	**new_av;
	int		len;
	int		i;

	args = argcheck(av);
	letters(args);
	new_av = ft_split(args, ' ');
	free(args);
	len = 0;
	while (new_av[len])
		len++;
	a->size = len;
	b->size = 0;
	a->data = malloc(sizeof(int) * len);
	b->data = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		a->data[i] = ps_atoi(new_av[i], a, b, new_av);
		i++;
	}
	free_split(new_av);
}

void	parsearg(t_stack *a, t_stack *b, char **av)
{
	refactor_ac(a, b, av);
	is_sorted(a);
	is_dup(a, b);
}
