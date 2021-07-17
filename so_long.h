#ifndef SO_LONG_H
# define	SO_LONG_H
# include	"mlx.h"
# include	"libft.h"
# include	"get_next_line.h"
# include	<math.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# define	SCREEN_WIDTH			320
# define	SCREEN_HEIGHT		320

# ifdef __linux__
#  define	K_W		119
#  define	K_A		97
#  define	K_S		115
#  define	K_D		100
#  define 	K_AR_L	65361
#  define	K_AR_R	65363
#  define 	K_ESC	65307
#  define	IS_LINUX 1
# else
#  define	K_W		13
#  define	K_A		0
#  define	K_S		1
#  define	K_D		2
#  define	K_AR_L	123
#  define	K_AR_R	124
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
	t_img		tresure_tex;
	t_img		goal_tex;
	t_img		character_tex[4];
	int			buf[SCREEN_HEIGHT][SCREEN_WIDTH];
	double		zBuffer[SCREEN_WIDTH];
}				t_info;

void	background(t_info *info);
int		main_loop(t_info *info);
void	end_game_without_info(int status, char *message);
void	end_game(t_info *info, int status, char *message);
void	set_back_colors(t_info *info);
void	set_wall_colors(t_info *info);
#endif