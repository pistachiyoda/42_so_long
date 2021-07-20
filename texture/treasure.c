#include "so_long.h"

void	set_treasure_colors(t_info *info)
{
	int	x;
	int	y;
	int color;

	y = 0;

	while (y < info->screen_height)
	{
		x = 0;
		while (x < info->screen_width)
		{
			color = info->tresure_tex.data[(y % 32) * info->tresure_tex.size_l / 4 + ((x % 32) * (info->tresure_tex.bpp / 8) / 4)];
			if((color & 0x00FFFFFF) != 0 && (info->worldMap[y / 32][x / 32] == TREASURE))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_opened_treasure_colors(t_info *info)
{
	int	x;
	int	y;
	int color;

	y = 0;

	while (y < info->screen_height)
	{
		x = 0;
		while (x < info->screen_width)
		{
			color = info->opened_tresure_tex.data[(y % 32) * info->opened_tresure_tex.size_l / 4 + ((x % 32) * (info->opened_tresure_tex.bpp / 8) / 4)];
			if((color & 0x00FFFFFF) != 0 && (info->worldMap[y / 32][x / 32] == OPENED_TREASURE))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}