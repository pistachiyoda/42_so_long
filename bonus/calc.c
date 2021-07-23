#include "so_long.h"

void	draw(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->screen_height)
	{
		x = 0;
		while (x < info->screen_width)
		{
			info->img.data[y * (info->img.size_l / 4) + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	set_back_colors(info);
	set_wall_colors(info);
	set_treasure_colors(info);
	set_opened_treasure_colors(info);
	set_goal_colors(info);
	if (info->cnt_in_loop < 40)
	{
		set_player1_colors(info);
		if (info->to_right)
			set_cat_right1_colors(info);
		else
			set_cat_left1_colors(info);
	}
	else
	{
		set_player2_colors(info);
		if (info->to_right)
			set_cat_right2_colors(info);
		else
			set_cat_left2_colors(info);
	}
}

int	main_loop(t_info *info)
{
	info->cnt_in_loop += 1;
	if (info->cnt_in_loop > 80)
		info->cnt_in_loop = 0;
	cat_move(info);
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}
