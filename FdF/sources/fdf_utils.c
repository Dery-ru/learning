#include "../includes/fdf.h"
#include <stdio.h>

int	ft_splitted(char *line, char split)
{
	char	**str;
	int		i;

	str = ft_split(line, split);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (i);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	malloc_free(int **dst)
{
	size_t	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
}
