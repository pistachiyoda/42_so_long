#include "so_long.h"

void	get_treasure(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX)] == TREASURE)
	{
		info->worldMap[(int)(info->posY)][(int)(info->posX)] = OPENED_TREASURE;
		info->collect_cnt += 1;
		ft_putstr_fd("+++++++++You got the Treasure!!!!!+++++++++\n", 1);
		ft_putstr_fd("Number of Treasure you got : ", 1);
		ft_putnbr_fd(info->collect_cnt, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	check_goal_condition(t_info *info, int posX, int posY)
{
	if (info->worldMap[posY][posX] == GOAL)
	{
		if (info->num_of_treasure == info->collect_cnt)
		{			
			ft_putstr_fd("\\\\\\\\\\\\Congraturation////////////\n", 1);
			ft_putstr_fd("You collected all Treasures!\n", 1);
			ft_putstr_fd("Please press ESC to end game!!\n", 1);
		}
		else
			ft_putstr_fd(
				"There are still treasures left you haven't collected yet.\n", 1);
	}
}

void	move_cnt(t_info *info)
{
	info->move_cnt += 1;
	ft_putstr_fd("Number of Movement : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putstr_fd("\n", 1);
}
