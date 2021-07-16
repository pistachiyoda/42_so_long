#include "so_long.h"
#include <stdio.h>
void	set_back_colors(t_info *info)
{
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			color = info->background_tex.data[(y % 32) * info->background_tex.size_l / 4 + ((x % 32) * (info->background_tex.bpp / 8) / 4)];
			info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}
