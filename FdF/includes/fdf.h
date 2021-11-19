/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:55:55 by rhoke             #+#    #+#             */
/*   Updated: 2021/09/23 11:48:22 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct fdf
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;

}	t_fdf;

typedef struct s_fd
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		heigth;
	int		width;
	int		**z_value;
	int		color;
	float	shift_x;
	float	shift_y;
	int		zoom;

	double	angle_x;
	double	angle_y;
	double	angle_z;

	int		win_x;
	int		win_y;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fd;

void	read_file(char *file_name, t_fd *data);
int		ft_splitted(char *line, char split);
void	bresenham(t_fdf draw, t_fd *data);
void	drawing(t_fdf draw, t_fd *data);
void	data_init(t_fd *data);
void	draw_init(t_fdf draw);
void	shift(t_fdf *draw, t_fd *data);
void	color(t_fdf draw, t_fd *data);
void	rotate(t_fdf *draw, t_fd *data);
void	zoom(t_fdf *draw, t_fd *data);
void	ft_error(char *str);
void	malloc_free(int **dst);

#endif