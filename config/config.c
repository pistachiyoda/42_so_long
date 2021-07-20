#include "so_long.h"

int	ft_strcmp(char *a, char *b)
{
	while (1)
	{
		if (*a == '\0' && *b == '\0')
			return (1);
		if (*a != *b)
			return (0);
		a++;
		b++;
	}
}

void	input_config(t_info *info, int fd)
{
	int		ret;
	int		y;
	char	*line;

	ret = -1;
	y = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strcmp(line, ""))
		{
			free(line);
			end_game(info, 1, "ERROR: Unexpected empty line.\n");
		}
		handle_map(info, line, &y);
		free(line);
	}
}

void	read_config(t_info *info, char *file_path)
{
	int		fd;
	int		sizex;
	int		sizey;
	int		calced_width;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		end_game(info, 1, "ERROR: Config file reading error.\n");
	input_config(info, fd);
	check_map(info);
	mlx_get_screen_size(info->mlx, &sizex, &sizey);
	if (info->map_width * 32 > sizex || info->map_height * 32 > sizey)
		end_game_without_info(1, "ERROR: Input map is bigger than window size.\n");
	info->screen_height = info->map_height * 32;
	info->screen_width = info->map_width * 32;
	int i;
	int j;
	info->buf = (int *)malloc((sizeof (int *)) * info->screen_height);
	i = 0;
	while (i < info->screen_height)
	{
		j = 0;
		info->buf[i] = (int *)malloc((sizeof (int)) * info->screen_width);
		while (j < info->screen_width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	// init_position(info);
}
