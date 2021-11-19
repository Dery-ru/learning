#include "../includes/fdf.h"

void	draw_init(t_fdf draw)
{
	draw.x = 0;
	draw.y = 0;
	draw.x1 = 0;
	draw.y1 = 0;
	draw.z = 0;
	draw.z1 = 0;
}

void	data_init(t_fd *data)
{
	data->x = 0;
	data->y = 0;
	data->x1 = 0;
	data->y1 = 0;
	data->heigth = 0;
	data->width = 0;
	data->z_value = NULL;
	data->color = 0x00f0f0f0;
	data->shift_x = 200;
	data->shift_y = 200;
	data->zoom = 10;
	data->angle_x = 0.0;
	data->angle_y = 0.0;
	data->angle_z = 0.0;
	data->win_x = 1000;
	data->win_y = 1000;
}
