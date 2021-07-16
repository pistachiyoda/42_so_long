#include "so_long.h"

// void	init_map_info(t_info *info)
// {
// 	int	i;

// 	info->worldMap = NULL;
// 	info->map_height = 0;
// 	info->map_width = 0;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		info->texture[i].img = NULL;
// 		info->texture[i].data = NULL;
// 		i++;
// 	}
// 	info->floor_color = -1;
// 	info->ceiling_color = -1;
// 	info->initial_direction = '\0';
// }
#include <stdio.h>
void	load_image(t_info *info, t_img *texture,char *path)
{
	texture->img = mlx_xpm_file_to_image(
			info->mlx, path,
			&texture->img_width,
			&texture->img_height);
	texture->data = (int *)mlx_get_data_addr(
			texture->img,
			&texture->bpp,
			&texture->size_l,
			&texture->endian);
	if (texture->data == 0)
		end_game(info, 1, "ERROR: load image failed\n");
}

void	load_images(t_info *info)
{
	t_img	img;

	load_image(info, &info->background_tex, "./textures/siba.xpm");
	load_image(info, &info->wall_tex, "./textures/hana.xpm");
	// load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
	// load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	// load_image(info, info->texture[3], "textures/greystone.xpm", &img);
	// load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	// load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	// load_image(info, info->texture[6], "textures/wood.xpm", &img);
	// load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
	// load_image(info, info->texture[8], "textures/barrel.xpm", &img);
	// load_image(info, info->texture[9], "textures/pillar.xpm", &img);
	// load_image(info, info->texture[10], "textures/greenlight.xpm", &img);
}

void	init_info(t_info *info)
{
	int	i;
	int	j;

	info->mlx = mlx_init();
	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		end_game_without_info(1, "ERROR: Invalid argument.");
	info = (t_info *)malloc(sizeof(t_info));
	init_info(info);
	info->win = mlx_new_window(info->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "so_long");
	info->img.img = mlx_new_image(info->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(
			info->img.img, &(info->img.bpp),
			&(info->img.size_l), &(info->img.endian));
	load_images(info);
	// read_config(info, argv[1]);
	mlx_loop_hook(info->mlx, &main_loop, info);
	// mlx_hook(info->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, info);
	// mlx_hook(info->win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, info);
	// mlx_hook(info->win, X_EVENT_KEY_EXIT, 1L << 17, close_window, info);
	mlx_loop(info->mlx);
}
