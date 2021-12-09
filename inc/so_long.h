#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "so_error.h"

# define SCRN_WIDTH 800
# define SCRN_HEIGHT 600
# define CHARSET "01CEP"

# define WHITE 0
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RED 0x00FF0000

# define PLAYER_SPRITE ./graphics/player.xpm
# define ITEM_SPRITE ./graphics/item.xpm

typedef struct s_dot
{
	int	width;
	int	height;
}		t_dot;

typedef struct s_fpos
{
	float	width;
	float	height;
}		t_fpos;

typedef t_dot t_pos;

/*
** Map
*/
typedef struct s_map
{
	char	*layout;
	int	width;
	int	height;
}		t_map;

/*
** ft_str_utils
*/
int	ft_str_countc(char *str, char c);
t_bool	ft_strchr_set(char *str, char *set);
char	*ft_str_fusion(char *s1, char *s2);

/*
** ft_check_map
*/

int	ft_check_row(char *line, int width);
int	ft_exit_map(t_map *map, int fd, int errnb);

/*
** ft_load_map
*/

int	ft_map_init(t_map *map, int fd);
int	ft_add_row(t_map *map, char *line);
int	ft_load_layout(t_map *map, int fd);
int	ft_load_map(t_map *map, char *filename);

/*
** ft_load_img
*/

/*
** ft_load_tiles
*/

/*
** ft_load_mobile_elem
*/

typedef struct	s_img
{
	void		*id;
	int		*layout;
	int		width;
	int		height;
}		t_img;

typedef struct	s_scrn
{
	void	*id;
	t_img	img;
}		t_scrn;

typedef struct	s_mlx
{
	void	*id;
	t_scrn	scrn;
}		t_mlx;

typedef struct	s_sprite
{
	t_img	img;
	t_fpos	pos;
}		t_sprite;

typedef struct s_player
{
	t_img	img;
	t_fpos	pos;
}		t_player;

typedef	struct t_tiles
{
	char	*charset;
	t_img	*img;
}		t_tiles;

typedef struct s_env
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_tiles		tiles;
	t_list		*item_ls;
}		t_env;

/*
** Renderer
*/

#endif
