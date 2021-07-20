#include "so_long.h"

int	proc_map_element(char c, t_info *info)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (WALL);
	if (c == 'C')
	{
		info->C_cnt += 1;
		return (TREASURE);
	}
	if (c == 'E')
	{
		info->E_cnt += 1;
		return (GOAL);
	}
	if (c == 'P')
	{
		info->P_cnt += 1;
		return (0);
	}
	return (-1);
}

void	handle_line(t_info *info, int y, char *line, int line_len)
{
	int	i;

	i = 0;
	info->worldMap[y] = (int *)malloc(sizeof(int) * (line_len + 1));
	if (!info->worldMap[y])
		end_game(info, 1, "ERROR: Malloc failed.\n");
	while (i < line_len)
	{
		if (!ft_strrchr("01CEP", line[i]))
			end_game(info, 1, "ERROR: Invalid map.\n");
		if (line[i] == 'C')
			info->num_of_treasure += 1;
		info->worldMap[y][i] = proc_map_element(line[i], info);
		if (ft_strrchr("P", line[i]))
		{
			info->posX = i;
			info->posY = y;
		}
		i++;
	}
	info->worldMap[y][i] = -2;
}

int	handle_map(t_info *info, char *line, int *y)
{
	int	**new_map_array;
	int	i;
	int	line_len;

	new_map_array = (int **)malloc(sizeof(int *) * ((*y) + 1));
	if (!new_map_array)
		end_game(info, 1, "ERROR: Malloc failed.\n");
	i = 0;
	while (i < *y)
	{
		new_map_array[i] = info->worldMap[i];
		i++;
	}
	if ((*y) != 0)
		free(info->worldMap);
	info->worldMap = new_map_array;
	line_len = ft_strlen(line);
	handle_line(info, *y, line, line_len);
	if (info->map_width != 0 && info->map_width != line_len)
		end_game(info, 1, "ERROR: Invalid map.\n");
	info->map_width = line_len;
	(info->map_height)++;
	(*y)++;
	return (1);
}  
