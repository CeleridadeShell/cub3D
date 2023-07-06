/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:37:56 by mcarecho          #+#    #+#             */
/*   Updated: 2023/07/05 22:42:34 by ccamargo         ###   ########.fr       */
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

/* Define */

# define NUM_PARAM 1
# define WRONG_FILE 2
# define MAP_NONEXISTENT 3
# define TEXTURES_INVALID 4
# define VALID_CHARS "10NSEW"

/* Structs */

typedef struct s_scene
{
	int		fd;
	char	**file_lines;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	char	**map;
}			t_scene;

/* Functions */
void	throw_err(int err);
int		is_param_valid(int argc, char **argv);
int		is_scene_valid(char *map_path);
void	initialize_scene(t_scene *scene, char *map_path);
void	close_scene(t_scene *scene);

#endif
