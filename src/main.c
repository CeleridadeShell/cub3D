/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:39:48 by christian         #+#    #+#             */
/*   Updated: 2023/09/08 18:52:12 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>


void drawplayer(void *mlx, void *win, float x, float y)
{
	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
}

int	img_init(char *file_path, void *mlx, t_img *img)
{
	img->sprite_img = mlx_xpm_file_to_image(mlx, file_path, &img->width, &img->height);
	if (img->sprite_img == NULL || img->width != 64 || img->height != 64)
	{
		throw_err(MINILIB_FAILED_SPRITE);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->sprite_img, &img->bpp, &img->line_len, &img->endian);
	return (1);
}


void trace_path()
{
	drawplayer(game.mlx, game.win, game.player.x, game.player.y);
}

void	run_game(t_scene *scene)
{
	t_game	game;

	init_game(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 800, 600, "Cub3D");
	if (!game.mlx || !game.win)
	{
		throw_err(MINILIB_FAILED_WINDOW);
		return ;
	}
	if (!img_init(scene->no, game.mlx, &game.no) || !img_init(scene->so, game.mlx, &game.so) || !img_init(scene->we, game.mlx, &game.we) || !img_init(scene->ea, game.mlx, &game.ea))
		return ;
	mlx_loop_hook(mlx, trace_path, &game);
	close_game(&game);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (!is_param_valid(argc, argv) || !is_scene_valid(argv[1], &scene))
	{
		close_scene(&scene);
		exit(1);
	}
	run_game(&scene);
	close_scene(&scene);
	return (0);
}
