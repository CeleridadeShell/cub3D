/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:27:41 by ccamargo          #+#    #+#             */
/*   Updated: 2023/09/07 19:34:29 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->no.sprite_img);
	mlx_destroy_image(game->mlx, game->so.sprite_img);
	mlx_destroy_image(game->mlx, game->we.sprite_img);
	mlx_destroy_image(game->mlx, game->ea.sprite_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
}
