#include "so_long.h"

void	set_player_colors(t_info *info)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < info->screen_height)
	{
		x = 0;
		while (x < info->screen_width)
		{
			color = info->player_tex.data
			[((y % 32) * info->player_tex.size_l / 4)
				+ ((x % 32) * (info->player_tex.bpp / 8) / 4)];
			if ((color & 0x00FFFFFF) != 0
				&& (double)(x / 32) == (int)(info->posX)
				&& (double)(y / 32) == (int)(info->posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_player1_colors(t_info *info)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < info->screen_height)
	{
		x = 0;
		while (x < info->screen_width)
		{
			color = info->player_tex1.data
			[((y % 32) * info->player_tex1.size_l / 4)
				+ ((x % 32) * (info->player_tex1.bpp / 8) / 4)];
			if ((color & 0x00FFFFFF) != 0
				&& (double)(x / 32) == (int)(info->posX)
				&& (double)(y / 32) == (int)(info->posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_player2_colors(t_info *info)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < info->screen_height)
	{
		x = 0;
		while (x < info->screen_width)
		{
			color = info->player_tex2.data
			[((y % 32) * info->player_tex2.size_l / 4)
				+ ((x % 32) * (info->player_tex2.bpp / 8) / 4)];
			if ((color & 0x00FFFFFF) != 0
				&& (double)(x / 32) == (int)(info->posX)
				&& (double)(y / 32) == (int)(info->posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}
