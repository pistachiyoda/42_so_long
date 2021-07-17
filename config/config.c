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

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		end_game(info, 1, "ERROR: Config file reading error.\n");
	input_config(info, fd);
	check_map(info);
	// init_position(info);
}
