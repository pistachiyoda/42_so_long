#include "so_long.h"

void	check_element(t_info *info)
{
	if (info->P_cnt != 1)
		end_game(info, 1, "ERROR: Number of Player is invalid\n");
	if (info->E_cnt != 1)
		end_game(info, 1, "ERROR: Number of Goal is invalid\n");
	if (info->C_cnt == 0)
		end_game(info, 1, "ERROR: Number of Treasure is invalid\n");
}

void	check_cell(t_info *info, int x, int y)
{
	if (
		(y == 0 || y == (info->map_height - 1)
			|| x == 0 || x == (info->map_width - 1))
		&& info->worldMap[y][x] != 1
	)
		end_game(info, 1, "ERROR: Invalid map.\n");
}

void	check_map(t_info *info)
{
	int	current_x;
	int	current_y;

	check_element(info);
	current_y = 0;
	while (current_y < info->map_height)
	{
		current_x = 0;
		while (current_x < info->map_width)
		{
			if (info->worldMap[current_y][current_x] != 0)
			{
				current_x++;
				continue ;
			}
			check_cell(info, current_x, current_y);
			current_x++;
		}
		current_y++;
	}
}
