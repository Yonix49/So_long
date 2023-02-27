/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:09:58 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/27 13:31:05 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

typedef struct cord
{
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			lig;
	int			col;
}				cord;

typedef struct s_player
{
	int			player_x;
	int			player_y;
}				t_player;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	void		*mlx;
	void		*img_mur;
	void		*img_exit;
	void		*img_conso;
	void		*img_perso;
	void		*win_ptr;
	void		*img_back;
	int			width;
	int			height;
	int			x;
	int			y;
	t_player	t_player;
	cord		cord;
}				t_data;
// typedef struct s_data_img
// {
// 	void			*img;
// 	char			*addr;
// 	int				bpp;
// 	int				line_l;
// 	int				endian;
// }					t_data_img;

// typedef struct s_data_engine
// {
// 	t_data_img		*img;
// 	t_data_img		*tmp;
// 	t_element		*element;
// 	t_init			*init;
// 	t_map			*map;
// 	t_player		*player;
// 	t_monster		**monster;
// 	struct timeval	tv;
// 	int				nb_monster;
// 	int				nb_coup;
// }					t_data_engine;

// # include "../minilibx-linux/mlx.h"
// # include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
int				ft_strlen(const char *s);

char			*ft_strdup(char *src);

size_t			ft_verification(int start, size_t len, char *s);

char			*ft_substr(char *s, unsigned int start, size_t len);

void			ft_scotch(char *dest, char *ss1, char *ss2);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

char			**ft_split(char *s, char c);

int				verif_bords(char **map);

int				verif_map(char **map);

int				verif_elem(char **map);
struct cord		get_map_ligne(char **map, struct cord cord);

struct cord		get_map_col(char **map, struct cord cord);

struct cord		cord_start(char **map, struct cord cord);

struct cord		cord_exit(char **map, struct cord cord);

struct cord		cord_all(char **map, struct cord pos);

int				is_valid_path_exit(char **map, struct cord pos);
char			*ft_strjoin1(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				verif_namearg(int argc, char **argv);
char			*ft_strjoin_1(char *s1, char *s2);
int				verifall(char **map);
void			ft_free_double(char **map, char **tmp);
void			ft_free(char **map);
int				verif_open(char **argv);
int				is_char_sett(char *map);
t_data			init_image(t_data img, char **map);
void			set_display(t_data img, char **map);
void			display_window(t_data img, char **map);
char			**get_map(char **map, char **argv);
char			**copy_map(char **map, t_data img);
void			move_char(t_data img);
int				key_hook(int key_code, t_data img, char **map);
t_data			get_cord_player(t_data img, char **map);
int				verif_co(char **map);
// unsigned int		get_color_pixel(t_data_engine *engine, void *img, int y,
// 						int x);

// void				my_mlx_pixel_put(t_data_engine *data, int x, int y,
// 						int color);

// void				put_pixel(t_data_engine *engine, void *img, int y, int x);

// void				set_element_on_display(t_data_engine *engine);

// void				display_map(t_data_engine *engine);
#endif