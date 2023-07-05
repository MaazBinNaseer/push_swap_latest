/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:47:07 by yusman            #+#    #+#             */
/*   Updated: 2023/05/21 23:52:40 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*data;
	int	size;
	int	flag;
}	t_stack;

typedef struct psinfo
{
	t_stack		a;
	t_stack		b;
}	t_psinfo;

typedef struct s_set
{
	int			id;
	int			*values;
	int			size;
}	t_set;

typedef struct setinfo
{
	t_set		*sets;
	int			size;
}	t_setinfo;

# define CHUNK_SIZE 9

void		sa(t_stack *a);
void		sb(t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rra(t_stack *a);
void		rb(t_stack *b);
void		rrb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		swap(int *a, int *b);

int			smallnumber(t_stack *a);
int			bignumber(t_stack *stack);
int			is_digit(int c);
char		*argcheck(char **av);
void		letters(char *args);
void		free_split(char **str);
void		free_all(t_stack *a, t_stack *b, int flag);
void		free_data(t_stack *a, t_stack *b, int flag);
void		swap(int *a, int *b);
int			ps_atoi(char *str, t_stack *a, t_stack *b, char **new_av);
void		is_dup(t_stack *a, t_stack *b);
void		is_sorted(t_stack *a);
void		sign_check2(char *str, t_stack *a, t_stack *b, char **new_av);
void		sign_check(char *str, t_stack *a, t_stack *b, char **new_av);
void		refactor_ac(t_stack *a, t_stack *b, char **av);
void		parsearg(t_stack *a, t_stack *b, char **av);
void		sort_three(t_stack *a);
void		sort_four(t_stack *a, t_stack *b);
void		sort_five(t_stack *a, t_stack *b);
void		print_stack(t_stack *stk);
int			*sort_chunk(t_stack *a);
void		push_2_b(t_stack *a, t_stack *b, int *sorted);
void		chunk_sort(t_stack *a, t_stack *b);
void		bubble(int *list, int top);
void		parsesort(t_stack *a, t_stack *b);

// stack_set
t_setinfo	*create_sets(t_psinfo *info, int min_set_size);
int			*num_sort(int *values, int size);
int			*num_rsort(int *values, int size);

// stack_set_utils
int			init_set(t_set	*set, int id, int size);
t_set		*init_sets(int size, int set_size);
void		free_sets(t_setinfo *info);

// stack_set_utils2
int			get_set_size(int size, int min_size);
void		add_set(t_psinfo *info, t_set *set);
void		add_one_set(t_psinfo *info, t_set *set);
void		add_two_set(t_psinfo *info, t_set *set1, t_set *set2);

// stack_sort_utils
int			find_index_arr(int *a, int value, int n);
void		move_top_stack(int index, t_psinfo *info, int on_b);
int			get_pivot(int *a, int size, int index);

// quick_sort
int			*new_quicksort(int *a, int n);
void		quicksort(int *a, int start, int end);
int			issorted(int *a, int n);

// num_utils
int			ft_numncmp(const int *num, int c, int n);
size_t		ft_numlen(const int *num);
void		ft_numswap(int *a, int *b);
void		ft_numlcpy(int *dest, const int *src, int n);
int			*ft_numdup(const int *src, int n);

// stack_divide_conquer
void		divide_conquer(t_psinfo *info, t_setinfo *setinfo, int min_size);
void		divide_conquer_a(t_psinfo *info, int *sorted,
				int size, int min_size);
void		divide_conquer_b(t_psinfo *info, int *sorted,
				int size, int min_size);

// stack_divide_conquer_utils
void		reverse_move(t_psinfo *info, char *f, int size);

// stack_insertsort_a
void		insertsort_on_a(t_psinfo *info, int *sorted, int size);

// stack_insertsort_b
void		insertsort_on_b(t_psinfo *info, int *sorted, int size);

#endif
