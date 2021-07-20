#include "so_long.h"

void	handle_key_w(t_info *info)
{
	if (info->worldMap[(int)(info->posY - info->moveSpeed)][(int)(info->posX)] != 1)
	{
		if ((int)(info->posY) != (int)(info->posY - info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(info, (int)info->posX, (int)(info->posY - info->moveSpeed));
		}
		info->prev_posY = info->posY;
		info->posY -= info->moveSpeed;
		get_treasure(info);
	}
}

void	handle_key_s(t_info *info)
{
	if (info->worldMap[(int)(info->posY + info->moveSpeed)][(int)(info->posX)] != 1)
	{
		if ((int)(info->posY) != (int)(info->posY + info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(info, (int)info->posX, (int)(info->posY + info->moveSpeed));
		}
		info->prev_posY = info->posY;
		info->posY += info->moveSpeed;
		get_treasure(info);
	}
}

void	handle_key_d(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX + info->moveSpeed)] != 1)
	{
		if ((int)(info->posX) != (int)(info->posX + info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(info, (int)(info->posX + info->moveSpeed), (int)info->posY);
		}
		info->prev_posX = info->posX;
		info->posX += info->moveSpeed;
		get_treasure(info);
	}
}

void	handle_key_a(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX - info->moveSpeed)] != 1)
	{
		if ((int)(info->posX) != (int)(info->posX - info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(info, (int)(info->posX - info->moveSpeed), (int)info->posY);
		}
		info->prev_posX = info->posX;
		info->posX -= info->moveSpeed;
		get_treasure(info);
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
		{
			ft_putstr_fd("There are still treasures left you haven't collected yet.\n", 1);
		}
	}
}

void	move_cnt(t_info *info)
{
	info->move_cnt += 1;
	ft_putstr_fd("Number of Movement : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putstr_fd("\n", 1);
}

void	key_move(t_info *info)
{
	if (info->key_w)
		handle_key_w(info);
	if (info->key_s)
		handle_key_s(info);
	if (info->key_d)
		handle_key_d(info);
	if (info->key_a)
		handle_key_a(info);
}

void	get_treasure(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX)] == 2)
	{
		info->worldMap[(int)(info->posY)][(int)(info->posX)] = 4;
		info->collect_cnt += 1;
		ft_putstr_fd("+++++++++You got the Treasure!!!!!+++++++++\n", 1);
		ft_putstr_fd("Number of Treasure you got : ", 1);
		ft_putnbr_fd(info->collect_cnt, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	key_update(t_info *info)
{
	key_move(info);
	get_treasure(info);
}