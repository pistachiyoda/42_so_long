#include "so_long.h"

void	load_image(t_info *info, t_img *texture, char *path)
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
	load_image(info, &info->tresure_tex, "./textures/takara.xpm");
	load_image(info, &info->goal_tex, "./textures/goal.xpm");
	load_image(info, &info->player_tex, "./textures/mae.xpm");
	load_image(info, &info->opened_tresure_tex, "./textures/kara_takara.xpm");
}

void	init_info(t_info *info)
{
	int	i;
	int	j;

	info->mlx = mlx_init();
	info->buf = NULL;
	info->moveSpeed = 0.02;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	info->prev_posX = 0;
	info->prev_posY = 0;
	info->move_cnt = 0;
	info->num_of_treasure = 0;
	info->collect_cnt = 0;
	info->E_cnt = 0;
	info->P_cnt = 0;
	info->C_cnt = 0;
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		end_game_without_info(1, "ERROR: Invalid argument.");
	info = (t_info *)malloc(sizeof(t_info));
	init_info(info);
	read_config(info, argv[1]);
	info->win = mlx_new_window(
			info->mlx, info->screen_width, info->screen_height, "so_long");
	info->img.img = mlx_new_image(
			info->mlx, info->screen_width, info->screen_height);
	info->img.data = (int *)mlx_get_data_addr(
			info->img.img, &(info->img.bpp),
			&(info->img.size_l), &(info->img.endian));
	load_images(info);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 1L << 17, close_window, info);
	mlx_loop(info->mlx);
}
