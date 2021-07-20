#include "so_long.h"

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
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->mlx)
	{
		if (IS_LINUX)
			mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
	free_map(info);
	free(info);
}

int	close_window(t_info *info)
{
	free_info(info);
	ft_putstr_fd("End game.\n", 1);
	exit(0);
}

void	end_game_without_info(int status, char *message)
{
	ft_putstr_fd(message, 1);
	exit(status);
}

void	end_game(t_info *info, int status, char *message)
{

	free_info(info);
	ft_putstr_fd(message, 1);
	exit(status);
}
