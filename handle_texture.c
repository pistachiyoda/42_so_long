#include "so_long.h"
#include <stdio.h>
void	load_image(t_info *info, char *path)
{
	info->background_tex.img = mlx_xpm_file_to_image(
			info->mlx, path,
			&info->background_tex.img_width,
			&info->background_tex.img_height);
	info->background_tex.data = (int *)mlx_get_data_addr(
			info->background_tex.img,
			&info->background_tex.bpp,
			&info->background_tex.size_l,
			&info->background_tex.endian);
	if (info->background_tex.data == 0)
		end_game(info, 1, "ERROR: load image failed\n");
}

void	background(t_info *info)
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

void	handle_texture(t_info *info)
{
	char *path = "./textures/siba.xpm";

	load_image(info, path);
	background(info);
}
