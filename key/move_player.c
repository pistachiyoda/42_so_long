#include "so_long.h"

void	handle_key_w(t_info *info)
{
	if (info->worldMap[(int)(info->posY - info->moveSpeed)][(int)(info->posX)] != 1)
		info->posY -= info->moveSpeed;
}

void	handle_key_s(t_info *info)
{
	if (info->worldMap[(int)(info->posY + info->moveSpeed)][(int)(info->posX)] != 1)
		info->posY += info->moveSpeed;
}

void	handle_key_d(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX + info->moveSpeed)] != 1)
		info->posX += info->moveSpeed;
}

void	handle_key_a(t_info *info)
{
	if (info->worldMap[(int)(info->posY)][(int)(info->posX - info->moveSpeed)] != 1)
		info->posX -= info->moveSpeed;
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