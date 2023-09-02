/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:37:56 by mcarecho          #+#    #+#             */
/*   Updated: 2023/09/02 14:34:41 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* MiniLibX Library */
//# include <mlx.h>

/* Native libraries */

# include <stdlib.h>
# include <math.h>

/* open() function includes */
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* read() and close() include */
# include <unistd.h>

/* Libft */

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

/* MiniLibX */

# include <mlx.h>

/* Define */

# define NUM_PARAM 1
# define WRONG_FILE 2
# define MAP_NONEXISTENT 3
# define TEXTURES_INVALID 4
# define COLORS_INVALID 5
# define MAP_NOT_LAST 6
# define MAP_NOT_WALLED 7
# define MAP_CHARS_NOT_VALID 8
# define MAP_PLAYERS_NOT_VALID 9
# define VALID_CHARS "10NSEW "
# define VALID_PLAYER_CHARS "NSEW"

/* Structs */

typedef struct s_scene
{
	int					fd;
	char				**scene_lines;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	unsigned int		f;
	unsigned int		c;
	char				**map;
}			t_scene;

/* Functions */
void			throw_err(int err);
int				is_param_valid(int argc, char **argv);
int				is_scene_valid(char *map_path, t_scene *scene);
int				initialize_scene(t_scene *scene, char *map_path);
int				feed_scene_textures(t_scene *scene);
int				feed_scene_floor_and_celling(t_scene *scene);
void			close_scene(t_scene *scene);
int				create_rgb(int r, int g, int b);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);
unsigned int	parse_color(char *RGB);
int				feed_scene_map(t_scene *scene);
int				is_map_walled(t_scene *scene);
int				are_map_chars_valid(t_scene *scene);
int				are_map_players_valid(t_scene *scene);

#endif
