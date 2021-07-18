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
	set_goal_colors(info);
	set_player_colors(info);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	// key_update(info);
	return (0);
}
