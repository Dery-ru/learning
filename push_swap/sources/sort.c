/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:35 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/13 14:45:45 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	three_elem(t_list *stacks)
{
	if (stacks->a->data < stacks->a->next->data)
	{	
		if (stacks->a->data < stacks->a->next->next->data
			&& stacks->a->next->data > stacks->a->next->next->data)
		{
			swap(&stacks->a, "sa\n");
			rotate(&stacks->a, "ra\n");
		}
		else if (stacks->a->data > stacks->a->next->next->data)
			reverse_rotate(&stacks->a, "rra\n");
	}
	else if (stacks->a->data > stacks->a->next->data)
	{
		if (stacks->a->data < stacks->a->next->next->data)
			swap(&stacks->a, "sa\n");
		else if (stacks->a->data > stacks->a->next->next->data
			&& stacks->a->next->data < stacks->a->next->next->data)
			rotate(&stacks->a, "ra\n");
		else if (stacks->a->data > stacks->a->next->next->data
			&& stacks->a->next->data > stacks->a->next->next->data)
		{
			swap(&stacks->a, "sa\n");
			reverse_rotate(&stacks->a, "rra\n");
		}
	}
}

static void	four_elem(t_list *stacks)
{
	int	min;

	min = get_min_val(stacks->a);
	while (stacks->a->data != min)
	{
		rotate(&stacks->a, "ra\n");
	}
	push(&stacks->a, &stacks->b, "pb\n");
	three_elem(stacks);
	push(&stacks->b, &stacks->a, "pa\n");
}

static void	five_elem(t_list *stacks)
{
	int	min;

	min = get_min_val(stacks->a);
	while (stacks->a->data > min)
	{
		rotate(&stacks->a, "ra\n");
	}
	push(&stacks->a, &stacks->b, "pb\n");
	four_elem(stacks);
	push(&stacks->b, &stacks->a, "pa\n");
}

void	less_five_sort(t_list *stacks)
{
	int	list_lenth;

	list_lenth = list_len(stacks->a);
	if (list_lenth < 3)
		if (stacks->a->data > stacks->a->next->data)
			swap(&stacks->a, "sa\n");
	if (list_lenth == 3)
		three_elem(stacks);
	else if (list_lenth == 4)
		four_elem(stacks);
	else if (list_lenth == 5)
		five_elem(stacks);
}

void	pre_sort(t_list *stacks)
{
	t_moves	mv;

	while (list_len(stacks->a) > 5)
	{
		if (stacks->a->order > stacks->size - 5)
			rotate(&(stacks->a), "ra\n");
		else
			push(&(stacks->a), &(stacks->b), "pb\n");
	}
	if (list_len(stacks->a) <= 5)
		less_five_sort(stacks);
	while (list_len(stacks->b))
		sorting(stacks, &mv);
	fin_sort(&(stacks->a), &mv);
}
