/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:46:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 14:35:16 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define WALL_PATH "./assets/wall.xpm"
# define FLOOR_PATH "./assets/floor.xpm"
# define ITEM_PATH "./assets/key.xpm"
# define EXIT_PATH "./assets/trapdoor_closed.xpm"
# define EXIT_OPEN_PATH "./assets/trapdoor_opened.xpm"
# define PLAYER_UP_PATH "./assets/player_up.xpm"
# define PLAYER_DOWN_PATH "./assets/player_down.xpm"
# define PLAYER_LEFT_PATH "./assets/player_left.xpm"
# define PLAYER_RIGHT_PATH "./assets/player_right.xpm"

typedef struct s_material {
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*exit_open;
	void	*player;
}			t_material;

typedef struct s_character {
	int		posx;
	int		posy;
	int		width;
	int		height;
	int		moves;
	int		items;
}				t_character;

typedef struct s_mlx {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_material	img;
	t_character	player;
}				t_mlx;

/* args */
int		check_args(int ac, char **av);
/* character */
void	move_player(int keycode, t_mlx *mlx);
/* game */
int		closewindow(t_mlx *mlx);
int		key_pressed(int key, t_mlx *mlx);
/* map */
void	check_mapdata(char **map);
void	init_map(char **map, t_mlx *mlx);
char	**parse_map(char *file);
int		get_map_size(char **map);
int		get_map_height(char **map);
int		get_map_width(char **map);
/* sprites */
void	init_sprites(t_mlx *mlx);
void	set_wall(t_mlx *mlx, int x, int y);
void	set_floor(t_mlx *mlx, int x, int y);
void	set_player(t_mlx *mlx, int x, int y);
void	set_collectible(t_mlx *mlx, int x, int y);
void	set_exit(t_mlx *mlx, int x, int y);
/* utils */
int		ft_strlen(char *str);
void	free_map(char **map);
int		print_error(char *str);
void	exit_error(char *str);

#endif
