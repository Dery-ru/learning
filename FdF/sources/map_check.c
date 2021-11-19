#include "../includes/fdf.h"

static int	get_y(char *file_name)
{
	char	*line;
	int		fd;
	int		y;

	fd = open(file_name, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		y++;
	}
	free(line);
	close(fd);
	return (y);
}

static int	get_x(char *file_name)
{
	int		fd;
	char	*line;
	char	*temp_line;
	int		x;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	x = ft_splitted(line, ' ');
	temp_line = line;
	while (get_next_line(fd, &line))
	{
		if (ft_splitted(line, ' ') != ft_splitted(temp_line, ' '))
			ft_error("invalid file");
		free(line);
	}
	free(temp_line);
	free(line);
	close(fd);
	return (x);
}

static void	write_z_value(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

static void	z_val_allocate(t_fd *data)
{
	int	i;

	data->z_value = (int **)malloc(sizeof(int *) * (data->heigth + 1));
	if (!data->z_value)
		exit(0);
	i = 0;
	while (i < data->heigth)
	{
		data->z_value[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->z_value)
			malloc_free(data->z_value);
	}
	data->z_value[i] = NULL;
}

void	read_file(char *file_name, t_fd *data)
{
	int		fd;
	char	*line;
	int		i;

	data->heigth = get_y(file_name);
	data->width = get_x(file_name);
	z_val_allocate(data);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		write_z_value(data->z_value[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
