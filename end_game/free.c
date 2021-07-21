#include "so_long.h"

void	free_buf(int **buf)
{
	int	i;
	i = 0;
	while (buf[i] != NULL)
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

void	free_map(t_info *info)
{
	int	i;

	if (info->worldMap)
	{
		i = 0;
		while (i < info->map_height)
		{
			free(info->worldMap[i]);
			i++;
		}
		free(info->worldMap);
	}
}

void	free_info(t_info *info)
{
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->background_tex.img)
		mlx_destroy_image(info->mlx, info->background_tex.img);
	if (info->wall_tex.img)
		mlx_destroy_image(info->mlx, info->wall_tex.img);
	if (info->opened_tresure_tex.img)
		mlx_destroy_image(info->mlx, info->opened_tresure_tex.img);
	if (info->tresure_tex.img)
		mlx_destroy_image(info->mlx, info->tresure_tex.img);
	if (info->goal_tex.img)
		mlx_destroy_image(info->mlx, info->goal_tex.img);
	if (info->player_tex.img)
		mlx_destroy_image(info->mlx, info->player_tex.img);
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->mlx)
	{
		if (IS_LINUX)
			mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
	free_map(info);
	if (info->buf)
		free_buf(info->buf);
	free(info);
}
