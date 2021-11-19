/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:57:52 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/11 12:02:06 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				data;
	int				order;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;

}				t_node;

typedef struct s_moves{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	len;
	int	i;
}	t_moves;

typedef struct s_list
{
	t_node	*a;
	t_node	*b;
	t_moves	*moves;
	int		size;
	int		*stack_a_value;
	int		min;
	int		max;
	char	**argv;
	int		argc;
}				t_list;

// push_swap_utils
void	ft_error(void);
int		get_min_val(t_node *list);
int		get_max_val(t_node *list);
int		get_min_ord(t_node *list);
void	init_moves(t_moves *mv);
// arg_checker
void	check_argv(char *argv);
void	overflow(char *str);
void	check_nums(char *str);
t_node	*check_args(t_list *stacks);
// struct
t_node	*create_list(int data);
void	deletet_list(t_node **list);
void	pushBack(t_node **list, int data);
int		list_len(t_node *list);
// steps
int		order_check(t_node *list);
int		*sort_arr(int *arr, int len);
//operations
void	swap(t_node **list, char *s);
void	rotate(t_node **list, char *s);
void	push(t_node **list, t_node **dest, char *s);
void	reverse_rotate(t_node **list, char *s);
// duo_operation
void	duo_swap(t_node **list, t_node **dest, char *s);
void	duo_rotate(t_node **list, t_node **dest, char *s);
void	duo_reverse_rotate(t_node **list, t_node **dest, char *s);
// sort
void	less_five_sort(t_list *stacks);
void	pre_sort(t_list *stacks);
// steps
int		order_check(t_node *list);
int		*list_to_arr(t_node *list);
void	set_order(t_node **list, int *arr);
int		*sort_arr(int *arr, int len);
// main_sorting
int		count_moves(t_node *a, t_node *b, t_moves *mv, int order);
void	sorting(t_list *stacks, t_moves *mv);
int		position(t_node *list, int i);
// fin_sort
void	sort_elem(t_node **a, t_node **b, t_moves *mv);
void	sort_continue(t_node **a, t_node **b, t_moves *mv);
void	fin_sort(t_node **a, t_moves *mv);

#endif
