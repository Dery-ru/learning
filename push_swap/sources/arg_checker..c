/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker..c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:40:44 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 15:54:57 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_argv(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(argv) == 1 && argv[i] == ' ')
		ft_error();
	if (ft_strlen(argv) == 0)
		ft_error();
	while (argv[i])
	{
		if (argv[i] != ' ')
			return ;
		i++;
	}
	ft_error();
}

void	overflow(char *str)
{
	long long	temp;

	temp = ft_atoi(str);
	if ((temp > 2147483647 || temp < -2147483648)
		|| ft_strlen(str) > 11)
		ft_error();
}

void	check_nums(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-'
			&& str[i] != '+')
			ft_error();
		i++;
	}
	overflow(str);
}

t_node	*check_args(t_list *stacks)
{
	int		i;
	int		j;
	char	**tmp;
	t_node	*start;

	j = 0;
	start = NULL;
	while (stacks->argv[++j])
	{
		i = 0;
		check_argv(stacks->argv[j]);
		tmp = ft_split(stacks->argv[j], ' ');
		while (tmp[i])
		{
			check_nums(tmp[i]);
			pushBack(&start, ft_atoi(tmp[i]));
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
	return (start);
}
