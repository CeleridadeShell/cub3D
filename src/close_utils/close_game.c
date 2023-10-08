/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:27:41 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/08 03:17:20 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites->no->sprite_img);
	mlx_destroy_image(game->mlx, game->sprites->so->sprite_img);
	mlx_destroy_image(game->mlx, game->sprites->we->sprite_img);
	mlx_destroy_image(game->mlx, game->sprites->ea->sprite_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	return (0);
}
