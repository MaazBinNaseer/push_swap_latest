/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:13:28 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 20:58:51 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sign_check(char *str, t_stack *a, t_stack *b, char **new_av)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			k++;
		if (k > 0)
		{
			ft_putstr_fd("2. Error\n", 2);
			free_split(new_av);
			free_data(a, b, 1);
		}
		i++;
	}
}

void	sign_check2(char *str, t_stack *a, t_stack *b, char **new_av)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && is_space(str[i + 1]))
		{
			ft_putstr_fd("3. Error\n", 2);
			free_split(new_av);
			free_data(a, b, 1);
		}
		if (ft_isdigit(str[i]) && (str[i + 1] == '+' || str[i + 1] == '-'))
		{
			ft_putstr_fd("4. Error\n", 2);
			free_split(new_av);
			free_data(a, b, 1);
		}
		if ((str[i] == '-' || str[i] == '+') && (!str[i + 1]))
		{
			ft_putstr_fd("5. Error\n", 2);
			free_split(new_av);
			free_data(a, b, 1);
		}
		i++;
	}
}

void	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1) // ensure i + 1 is always a valid index
	{
		if (a->data[i] < a->data[i + 1])
		{
			i++;
		}
		else
			break;
	}
	if (i == a->size)
	{
		free (a->data);
		// free (b->data);
		exit(EXIT_SUCCESS);
	}
}

void	is_dup(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->data[i] == a->data[j])
			{
				ft_putstr_fd("6. Error\n", 2);
				free (a->data);
				free (b->data);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
// 2 1 2 3 // need to understand

int	ps_atoi(char *str, t_stack *a, t_stack *b, char **new_av)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-')
		sign = sign * -1;
	sign_check(str, a, b, new_av);
	sign_check2(str, a, b, new_av);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if ((result > 2147483648 && sign == -1)
			|| (result > 2147483647 && sign == 1))
		{
			ft_putstr_fd("7. Error\n", 2);
			free_split(new_av);
			free_data(a, b, 1);
		}
	}
	return (result * sign);
}
// need to understand.
