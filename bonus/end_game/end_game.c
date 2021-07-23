#include "so_long.h"

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

void	end_game_without_map(t_info *info, char *message)
{
	if (IS_LINUX)
		mlx_destroy_display(info->mlx);
	free(info->mlx);
	free(info);
	ft_putstr_fd(message, 1);
	exit(1);
}

void	end_game(t_info *info, int status, char *message)
{
	ft_putstr_fd(message, 1);
	free_info(info);
	exit(status);
}
