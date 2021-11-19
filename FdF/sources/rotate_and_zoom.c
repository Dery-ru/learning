#include "../includes/fdf.h"

static void	rotate_x(float *y, float *z, t_fd *data)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(data->angle_x) + *z * sin(data->angle_x);
	*z = -previous_y * sin(data->angle_x) + *z * cos(data->angle_x);
}

static void	rotate_y(float *x, float *z, t_fd *data)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(data->angle_y) + *z * sin(data->angle_y);
	*z = -previous_x * sin(data->angle_y) + *z * cos(data->angle_y);
}

static void	rotate_z(float *x, float *y, t_fd *data)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(data->angle_z) - previous_y * sin(data->angle_z);
	*y = previous_x * sin(data->angle_z) + previous_y * cos(data->angle_z);
}

void	zoom(t_fdf *draw, t_fd *data)
{
	draw->x = data->x * data->zoom;
	draw->y = data->y * data->zoom;
	draw->x1 = data->x1 * data->zoom;
	draw->y1 = data->y1 * data->zoom;
}

void	rotate(t_fdf *draw, t_fd *data)
{
	rotate_x(&draw->y, &draw->z, data);
	rotate_x(&draw->y1, &draw->z1, data);
	rotate_y(&draw->x, &draw->z, data);
	rotate_y(&draw->x1, &draw->z1, data);
	rotate_z(&draw->x, &draw->y, data);
	rotate_z(&draw->x1, &draw->y1, data);
}
