#include "so_long.h"

void	set_player_colors(t_info *info)
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
			color = info->player_tex.data[(y % 32) * info->player_tex.size_l / 4 + ((x % 32) * (info->player_tex.bpp / 8) / 4)];
			if((color & 0x00FFFFFF) != 0 && (double)(x / 32) == floor(info->posX) && (double)(y / 32) == floor(info->posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}