/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:22 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/13 14:31:10 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stacks_init(t_list *stacks)
{
	stacks->b = NULL;
	stacks->stack_a_value = NULL;
	stacks->max = 0;
	stacks->min = 0;
	stacks->size = 0;
}

void	init_moves(t_moves *mv)
{
	mv->len = 0;
	mv->i = 0;
	mv->ra = 0;
	mv->rb = 0;
	mv->rra = 0;
	mv->rrb = 0;
}

int	main(int argc, char **argv)
{
	t_list	*stacks;

	if (argc == 1)
		exit(0);
	stacks = (t_list *) malloc(sizeof(t_list));
	if (!stacks)
		exit(0);
	stacks_init(stacks);
	stacks->argc = argc;
	stacks->argv = argv;
	stacks->a = check_args(stacks);
	stacks->size = list_len(stacks->a);
	if (order_check(stacks->a))
		exit(1);
	stacks->stack_a_value = list_to_arr(stacks->a);
	set_order(&stacks->a, stacks->stack_a_value);
	pre_sort(stacks);
	deletet_list(&stacks->a);
	free(stacks->stack_a_value);
	free(stacks);
	return (0);
}
