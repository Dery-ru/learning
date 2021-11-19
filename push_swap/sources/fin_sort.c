/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:40:58 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/11 12:01:21 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_continue(t_node **a, t_node **b, t_moves *mv)
{
	if (mv->ra > 0)
	{
		rotate(a, "ra\n");
		mv->ra--;
	}
	else if (mv->rb > 0)
	{
		rotate(b, "rb\n");
		mv->rb--;
	}
	else if (mv->rra > 0)
	{
		reverse_rotate(a, "rra\n");
		mv->rra--;
	}
	else if (mv->rrb > 0)
	{
		reverse_rotate(b, "rrb\n");
		mv->rrb--;
	}
}

void	sort_elem(t_node **a, t_node **b, t_moves *mv)
{
	while (mv->ra || mv->rb || mv->rrb || mv->rra)
	{
		if (mv->ra && mv->rb)
		{
			duo_rotate(a, b, "rr\n");
			mv->ra--;
			mv->rb--;
		}
		else if (mv->rra && mv->rrb)
		{
			duo_reverse_rotate(a, b, "rrr\n");
			mv->rra--;
			mv->rrb--;
		}
		else
			sort_continue(a, b, mv);
	}
	if (b)
		push(b, a, "pa\n");
}

void	fin_sort(t_node **a, t_moves *mv)
{
	init_moves(mv);
	mv->len = list_len(*a);
	mv->i = position(*a, 1);
	if (mv->len / 2 >= mv->i)
		mv->ra = mv->i - 1;
	else if (mv->len > 1)
		mv->rra = mv->len - mv->i + 1;
	sort_elem(a, NULL, mv);
	return ;
}

// ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`;