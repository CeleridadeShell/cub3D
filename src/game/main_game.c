/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:32:42 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/07 21:59:10 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void draw_mini_map(t_game *game, int a, int b, int y)
{
	int x;

	a = game->player->y - 5;

	while(a++ < game->player->y + 4)
	{
		x = 10;
		b = game->player->x - 5;
		while(a>=0 && a < game->player->y && b++ < game->player->x + 4)
		{
			if(b >= 0 && b < (int)ft_strlen(game->scene->map[a]))
			{
				if (game->player->y == a && game->player->x == b)
					square(game, x, y, 0x00FF00);
				else if (game->scene->map[a][b] == '1')
					square(game, x, y, 0x000000);
				else if (game->scene->map[a][b] == ' ')
					square(game, x, y, 0x000000);
				else
					square(game, x, y, 0xAFAFAF);
			}
			x += 22;
		}
		y += 22;
	}

}


int print_view(t_game *game)
{
	draw_mini_map(game, 10, 10, 10);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
