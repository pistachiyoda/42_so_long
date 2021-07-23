#include "so_long.h"

void	cat_move(t_info *info)
{
	double	next_x;

	if (info->to_right)
		next_x = info->cat_posX + info->moveSpeed;
	else
		next_x = info->cat_posX - info->moveSpeed;
	if (info->worldMap[(int)(info->cat_posY)][(int)(next_x)] == WALL)
		info->to_right = !(info->to_right);
	if ((int)(info->posY) == (int)(info->cat_posY)
		&& (int)(info->posX) == (int)(next_x))
		end_game(info, 0, "Game Over\n");
	info->cat_posX = next_x;
}

void	set_cat_left1_colors(t_info *info)
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
			color = info->cat_left_tex1.data
			[((y % 32) * info->cat_left_tex1.size_l / 4)
				+ ((x % 32) * (info->cat_left_tex1.bpp / 8) / 4)];
			if ((color & 0x00FFFFFF) != 0
				&& (double)(x / 32) == (int)(info->cat_posX)
				&& (double)(y / 32) == (int)(info->cat_posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_cat_left2_colors(t_info *info)
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
			color = info->cat_left_tex2.data
			[((y % 32) * info->cat_left_tex2.size_l / 4)
				+ ((x % 32) * (info->cat_left_tex2.bpp / 8) / 4)];
			if ((color & 0x00FFFFFF) != 0
				&& (double)(x / 32) == (int)(info->cat_posX)
				&& (double)(y / 32) == (int)(info->cat_posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_cat_right1_colors(t_info *info)
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
			color = info->cat_right_tex1.data
			[((y % 32) * info->cat_right_tex1.size_l / 4)
				+ ((x % 32) * (info->cat_right_tex1.bpp / 8) / 4)];
			if ((color & 0x00FFFFFF) != 0
				&& (double)(x / 32) == (int)(info->cat_posX)
				&& (double)(y / 32) == (int)(info->cat_posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	set_cat_right2_colors(t_info *info)
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
			color = info->cat_right_tex2.data
			[((y % 32) * info->cat_right_tex2.size_l / 4)
				+ ((x % 32) * (info->cat_right_tex2.bpp / 8) / 4)];
			if ((color & 0x00FFFFFF) != 0
				&& (double)(x / 32) == (int)(info->cat_posX)
				&& (double)(y / 32) == (int)(info->cat_posY))
				info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}
