#include "so_long.h"

void	check_cell(t_info *info, int x, int y)
{
	if (
		(y == 0 || y == (info->map_height - 1) || x == 0 || x == (info->map_width - 1))
		&& info->worldMap[y][x] != 1
	)
		end_game(info, 1, "ERROR: Invalid map.\n");
}

void	check_map(t_info *info)
{
	int	current_x;
	int	current_y;

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
