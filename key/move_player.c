#include "so_long.h"

void	handle_key_w(t_info *info)
{
	if (info->worldMap[(int)(info->posY - info->moveSpeed)][(int)(info->posX)] != 1)
	{
		if ((int)(info->posY) != (int)(info->posY - info->moveSpeed))
			move_cnt(info);
		info->prev_posY = info->posY;
		info->posY -= info->moveSpeed;
		// if (info->worldMap[])
	}
}

void	handle_key_s(t_info *info)
{
	if (info->worldMap[(int)(info->posY + info->moveSpeed)][(int)(info->posX)] != 1)
	{
		if ((int)(info->posY) != (int)(info->posY + info->moveSpeed))
			move_cnt(info);
		info->prev_posY = info->posY;
		info->posY += info->moveSpeed;
	}
}

void	handle_key_d(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX + info->moveSpeed)] != 1)
	{
		if ((int)(info->posX) != (int)(info->posX + info->moveSpeed))
			move_cnt(info);
		info->prev_posX = info->posX;
		info->posX += info->moveSpeed;
	}
}

void	handle_key_a(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX - info->moveSpeed)] != 1)
	{
		if ((int)(info->posX) != (int)(info->posX - info->moveSpeed))
			move_cnt(info);
		info->prev_posX = info->posX;
		info->posX -= info->moveSpeed;
	}
}

void	move_cnt(t_info *info)
{
	info->move_cnt += 1;
	ft_putstr_fd("Number of Movement :", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putstr_fd("\n", 1);
}

void	collect_cnt(t_info *info)
{
	info->collect_cnt += 1;
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

void	get_tresure(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX)] == 2)
	{
		info->worldMap[(int)(info->posY)][(int)(info->posX)] = 4;
		info->collect_cnt += 1;
	}
}

void	key_update(t_info *info)
{
	key_move(info);
	get_tresure(info);
}