/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:39:48 by christian         #+#    #+#             */
/*   Updated: 2023/10/07 21:31:32 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void loop(t_game *game)
{
	mlx_do_sync(game->mlx);
	mlx_hook(game->win, 2, 1L << 0, &key_pressed, game);
	mlx_hook(game->win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->win, 17, 0, &close_game, game);
	mlx_hook(game->win, 9, 1L << 21, &print_view, game);
	mlx_loop_hook(game->mlx, &print_view, game);
	mlx_loop(game->mlx);
}

void	run_game(t_scene *scene)
{
	t_game	game;

	init_game(&game, scene);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, MAP_X, MAP_Y, "Cub3D");
	if (!game.mlx || !game.win)
	{
		throw_err(MINILIB_FAILED_WINDOW);
		return ;
	}
	game->sprite = sprite_init(&game);
	if(game->sprite == NULL)
		return ;
	game.img = malloc(sizeof(t_img));
	game.img->sprite_img = mlx_new_image(game.mlx, MAP_X, MAP_Y);
	game.img->addr = mlx_get_data_addr(game.img->sprite_img, &game.img->bpp, &game.img->line_len, &game.img->endian);
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
