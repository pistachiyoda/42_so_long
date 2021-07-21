#ifndef SO_LONG_H
# define	SO_LONG_H
# include	"mlx.h"
# include	"libft.h"
# include	"get_next_line.h"
# include	<fcntl.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# define	X_EVENT_KEY_PRESS	2
# define	X_EVENT_KEY_RELEASE	3
# define	X_EVENT_KEY_EXIT	17
# define	WALL 1
# define	TREASURE 2
# define	GOAL 3
# define	OPENED_TREASURE 4
# ifdef __linux__
#  define	K_W		119
#  define	K_A		97
#  define	K_S		115
#  define	K_D		100
#  define 	K_ESC	65307
#  define	IS_LINUX 1
# else
#  define	K_W		13
#  define	K_A		0
#  define	K_S		1
#  define	K_D		2
#  define	K_ESC	53
#  define	IS_LINUX 0
void	mlx_destroy_display(void *ptr);
# endif

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		background_tex;
	t_img		wall_tex;
	t_img		opened_tresure_tex;
	t_img		tresure_tex;
	t_img		goal_tex;
	t_img		player_tex;
	int			**buf;
	int			**worldMap;
	int			map_height;
	int			map_width;
	int			screen_height;
	int			screen_width;
	double		posX;
	double		posY;
	double		moveSpeed;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_esc;
	int			prev_posX;
	int			prev_posY;
	int			move_cnt;
	int			num_of_treasure;
	int			collect_cnt;
	int			E_cnt;
	int			P_cnt;
	int			C_cnt;
}				t_info;

void	background(t_info *info);
int		main_loop(t_info *info);
void	end_game_without_info(int status, char *message);
void	end_game(t_info *info, int status, char *message);
void	set_back_colors(t_info *info);
void	set_wall_colors(t_info *info);
void	set_treasure_colors(t_info *info);
void	set_opened_treasure_colors(t_info *info);
void	set_goal_colors(t_info *info);
void	set_player_colors(t_info *info);
void	read_config(t_info *info, char *file_path);
int		handle_map(t_info *info, char *line, int *y);
void	check_map(t_info *info);
void	key_move(t_info *info);
void	key_update(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
void	get_tresure(t_info *info);
int		close_window(t_info *info);
void	move_cnt(t_info *info);
void	get_treasure(t_info *info);
void	check_goal_condition(t_info *info, int posX, int posY);
void	free_map(t_info *info);
void	free_info(t_info *info);
#endif