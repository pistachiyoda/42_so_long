#include "so_long.h"

void	handle_key_w(t_info *info)
{
	if (info->worldMap[(int)(info->posY
			- info->moveSpeed)][(int)(info->posX)] != WALL)
	{
		if ((int)(info->posY) != (int)(info->posY - info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(
				info, (int)info->posX, (int)(info->posY - info->moveSpeed));
		}
		info->prev_posY = info->posY;
		info->posY -= info->moveSpeed;
		get_treasure(info);
	}
}

void	handle_key_s(t_info *info)
{
	if (info->worldMap[(int)(info->posY
			+ info->moveSpeed)][(int)(info->posX)] != WALL)
	{
		if ((int)(info->posY) != (int)(info->posY + info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(
				info, (int)info->posX, (int)(info->posY + info->moveSpeed));
		}
		info->prev_posY = info->posY;
		info->posY += info->moveSpeed;
		get_treasure(info);
	}
}

void	handle_key_d(t_info *info)
{
	if (info->worldMap[(int)(info->posY)]
			[(int)(info->posX + info->moveSpeed)] != WALL)
	{
		if ((int)(info->posX) != (int)(info->posX + info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(
				info, (int)(info->posX + info->moveSpeed), (int)info->posY);
		}
		info->prev_posX = info->posX;
		info->posX += info->moveSpeed;
		get_treasure(info);
	}
}

void	handle_key_a(t_info *info)
{
	if (info->worldMap[(int)(info->posY)]
			[(int)(info->posX - info->moveSpeed)] != WALL)
	{
		if ((int)(info->posX) != (int)(info->posX - info->moveSpeed))
		{
			move_cnt(info);
			check_goal_condition(
				info, (int)(info->posX - info->moveSpeed), (int)info->posY);
		}
		info->prev_posX = info->posX;
		info->posX -= info->moveSpeed;
		get_treasure(info);
	}
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
