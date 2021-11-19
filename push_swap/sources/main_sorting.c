/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:04 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 13:43:25 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	position(t_node *list, int i)
{
	int	pos;

	pos = 1;
	while (list->order != i)
	{
		pos++;
		list = list->next;
	}
	return (pos);
}

int	position_extra(t_node *stack, int i)
{
	t_node	*tmp;
	int		ret;
	int		min;
	int		prev;
	int		next;

	ret = 1;
	min = get_min_ord(stack);
	if (i < min)
		return (position(stack, min));
	tmp = stack->next;
	prev = stack->order;
	next = tmp->order;
	while (1)
	{
		ret++;
		if (prev < i && next > i)
			return (ret);
		prev = tmp->order;
		if (!tmp->next)
			tmp = stack;
		else
			tmp = tmp->next;
		next = tmp->order;
	}
}

int	find_optimal_ret(int ret, t_moves *mv)
{
	int	i;

	i = mv->ra;
	if (mv->ra > mv->rb)
		i = mv->rb;
	while (i)
	{
		ret--;
		i--;
	}
	i = mv->rra;
	if (mv->rra > mv->rrb)
		i = mv->rrb;
	while (i)
	{
		ret--;
		i--;
	}
	return (ret);
}

int	count_moves(t_node *a, t_node *b, t_moves *mv, int order)
{
	int	sum;

	init_moves(mv);
	mv->len = list_len(b);
	mv->i = position(b, order);
	if (mv->len / 2 >= mv->i)
		mv->rb = mv->i - 1;
	else if (mv->len > 1)
		mv->rrb = mv->len - mv->i + 1;
	mv->len = list_len(a);
	mv->i = position_extra(a, order);
	if (mv->len / 2 >= mv->i)
		mv->ra = mv->i - 1;
	else
		mv->rra = mv->len - mv->i + 1;
	sum = mv->ra + mv->rb + mv->rra + mv->rrb;
	return (find_optimal_ret(sum, mv));
}

void	sorting(t_list *stacks, t_moves *mv)
{
	int		count_mv;
	int		min_mv;
	t_node	*tmp;
	t_node	*m;

	min_mv = -1;
	tmp = stacks->b;
	while (tmp)
	{
		count_mv = count_moves(stacks->a, stacks->b, mv, tmp->order);
		if (min_mv == -1 || count_mv <= min_mv)
		{
			min_mv = count_mv;
			m = tmp;
		}
		tmp = tmp->next;
	}
	min_mv = count_moves(stacks->a, stacks->b, mv, m->order);
	sort_elem(&(stacks->a), &(stacks->b), mv);
}
