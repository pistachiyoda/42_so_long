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

void	proc_map_size(t_info *info)
{
	int		sizex;
	int		sizey;

	mlx_get_screen_size(info->mlx, &sizex, &sizey);
	info->screen_height = info->map_height * 32;
	info->screen_width = info->map_width * 32;
	if (info->map_width * 32 > sizex || info->map_height * 32 > sizey)
	{
		ft_putstr_fd("sizex = ", 1);
		ft_putnbr_fd(sizex, 1);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("sizey = ", 1);
		ft_putnbr_fd(sizey, 1);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("info->screen_width = ", 1);
		ft_putnbr_fd(info->screen_width, 1);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("info->screen_height = ", 1);
		ft_putnbr_fd(info->screen_height, 1);
		ft_putchar_fd('\n', 1);
		end_game_without_info(
			1, "ERROR: Input map is bigger than window size.\n");
	}
}

void	set_buf(t_info *info)
{
	int		i;
	int		j;

	info->buf = (int **)malloc((sizeof (int **)) * info->screen_height + 1);
	i = 0;
	while (i < info->screen_height)
	{
		j = 0;
		info->buf[i] = (int *)malloc((sizeof (int)) * info->screen_width + 1);
		while (j < info->screen_width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		info->buf[i][j] = '\n';
		i++;
	}
	info->buf[i] = NULL;
}

void	read_config(t_info *info, char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		end_game_without_map(info, "ERROR: Config file reading error.\n");
	input_config(info, fd);
	check_map(info);
	proc_map_size(info);
	set_buf(info);
}
