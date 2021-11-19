#include "../includes/fdf.h"

void	zoom_key(int key, t_fd *data)
{
	if (key == 0)
		data->zoom -= 5;
	if (key == 12)
		data->zoom += 5;
}

void	rotate_key(int key, t_fd *data)
{
	if (key == 69)
		data->angle_y += 0.1;
	if (key == 78)
		data->angle_y -= 0.1;
	if (key == 91)
		data->angle_x += 0.1;
	if (key == 87)
		data->angle_x -= 0.1;
	if (key == 92)
		data->angle_z += 0.1;
	if (key == 88)
		data->angle_z -= 0.1;
}

int	move_key(int key, t_fd *data, t_fdf draw)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 53)
	{
		malloc_free(data->z_value);
		exit(1);
	}
	zoom_key(key, data);
	rotate_key(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drawing(draw, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fd	*data;
	t_fdf	draw;

	if (argc == 2)
	{
		data = (t_fd *)malloc(sizeof(t_fd));
		if (!data)
			return (0);
		data_init(data);
		draw_init(draw);
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x,
				data->win_y, "fdf");
		drawing(draw, data);
		mlx_key_hook(data->win_ptr, move_key, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	return (0);
}
