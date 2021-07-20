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

void	end_game(t_info *info, int status, char *message)
{

	free_info(info);
	ft_putstr_fd(message, 1);
	exit(status);
}
