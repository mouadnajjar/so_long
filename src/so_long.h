/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:20:54 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/20 19:24:00 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

//------------------Includes--------------------//
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include "../ft_printf/ft_printf.h"
//----------------------------------------------//

//------------------structers-------------------/

typedef struct s_sprites
{
	void	*player;
	void	*coins;
	void	*floor;
	void	*exit;
	void	*wall;
	void	*open_door;
	void	*player_on_door;
}	t_sprites;

typedef struct s_map
{
	char		**map;
	int			width;
	void		*mlx;
	void		*window;
	int			height;
	int			player_x;
	int			player_y;
	int			moves;
	int			players;
	int			collectibles;
	int			exits;
	int			on_exit;
	t_sprites	sprites;
}	t_map;

//----------------------------------------------//

//------------------event utils-----------------//
int		close_window(t_map *game);
int		key_press(int keycode, t_map *game);
void	setup_hook(t_map *game);
void	init_game(t_map *game);
//----------------------------------------------//

//-----------------graphics--------------------//
void	frees_sprites(t_map *game);
void	load_textures(t_map *game);
void	render_map(t_map *game);
int		is_valid_move(t_map *game, int new_x, int new_y);
void	handle_exit(t_map *game, int new_x, int new_y);
void	update_map(t_map *game, int new_x, int new_y);
void	handle_collectibles(t_map *game, int new_x, int _new_y);
void	check_sprites(t_map *game);
void	init_sprites(t_map *game);
//---------------------------------------------//

//-----------------parsing---------------------//
int		get_map_height(char *filename);
char	**read_map(char *filename, int height);
int		validate_shape(char	**map, int height);
int		validate_map_walls(char **map, int width, int height);
int		is_ber_file(char	*filename);
t_map	*laoding_map(char *filename);
void	freed(t_map *game);
void	find_player(t_map *game);
char	**duplicated_map(t_map *game, int height);
void	free_map(char **map, int height);
int		check_path(t_map *game);
void	destroy_image(t_map *game, void *img);
void	check_win_size(t_map *game);
void	ft_putstr_fd(char *s, int fd);
void	is_valid_map(t_map *game);
//----------------------------------------------//

//-----------------helpers---------------------//
int		ft_strcmp(char *s1, char *s2);
void	ft_error(void);
char	*ft_strtrim(char const *s1, char const *set);
//---------------------------------------------//
#endif