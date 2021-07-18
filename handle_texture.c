#include "so_long.h"
#include <stdio.h>
void	set_back_colors(t_info *info)
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
			color = info->background_tex.data[(y % 32) * info->background_tex.size_l / 4 + ((x % 32) * (info->background_tex.bpp / 8) / 4)];
			info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_wall_colors(t_info *info)
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
			color = info->wall_tex.data[(y % 32) * info->wall_tex.size_l / 4 + ((x % 32) * (info->wall_tex.bpp / 8) / 4)];
			if((color & 0x00FFFFFF) != 0 && (info->worldMap[y / 32][x / 32] == 1))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}


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
			if((color & 0x00FFFFFF) != 0 && (info->worldMap[y / 32][x / 32] == 2))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_goal_colors(t_info *info)
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
			color = info->goal_tex.data[(y % 32) * info->goal_tex.size_l / 4 + ((x % 32) * (info->goal_tex.bpp / 8) / 4)];
			if((color & 0x00FFFFFF) != 0 && (info->worldMap[y / 32][x / 32] == 3))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

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
			if((color & 0x00FFFFFF) != 0 && (info->worldMap[y / 32][x / 32] == 4))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}