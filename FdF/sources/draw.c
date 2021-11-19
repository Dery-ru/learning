#include "../includes/fdf.h"

static float	find_max(float a, float b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	else
		return (b);
}

void	shift(t_fdf *draw, t_fd *data)
{
	draw->x1 += data->shift_x;
	draw->y1 += data->shift_y;
	draw->x += data->shift_x;
	draw->y += data->shift_y;
}

void	color(t_fdf draw, t_fd *data)
{
	data->color = 0x00f0f0f0;
	if (draw.z > 0 || draw.z1 > 0)
		data->color = 0x00ff04a5;
	if (draw.z < 0 || draw.z1 < 0)
		data->color = 0x000000a0;
}

void	bresenham(t_fdf draw, t_fd *data)
{
	float	max;
	float	x_step;
	float	y_step;

	draw.z = data->z_value[(int)data->y][(int)data->x] * data->zoom;
	draw.z1 = data->z_value[(int)data->y1][(int)data->x1] * data->zoom;
	zoom(&draw, data);
	color(draw, data);
	rotate(&draw, data);
	shift(&draw, data);
	x_step = draw.x1 - draw.x;
	y_step = draw.y1 - draw.y;
	max = find_max(x_step, y_step);
	x_step = x_step / max;
	y_step = y_step / max;
	while ((int)(draw.x - draw.x1) || (int)(draw.y - draw.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			draw.x, draw.y, data->color);
		draw.x += x_step;
		draw.y += y_step;
	}
}

void	drawing(t_fdf draw, t_fd *data)
{
	data->y = 0;
	while (data->y < data->heigth)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->x < data->width - 1)
			{
				data->x1 = data->x + 1;
				data->y1 = data->y;
				bresenham(draw, data);
			}
			if (data->y < data->heigth - 1)
			{
				data->x1 = data->x;
				data->y1 = data->y + 1;
				bresenham(draw, data);
			}
			data->x += 1;
		}
		data->y += 1;
	}
}
