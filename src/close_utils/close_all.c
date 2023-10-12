/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:27:41 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/12 19:47:33 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	clean_all(t_game *game)
{
	free_ptr((void **)&game->scene->no);
	free_ptr((void **)&game->scene->so);
	free_ptr((void **)&game->scene->we);
	free_ptr((void **)&game->scene->ea);
	free_ptr((void **)&game->scene->player);
	while (game->scene->map != NULL && --game->scene->max_y > 0)
		free_ptr((void **)&game->scene->map[game->scene->max_y - 1]);
	free_ptr((void **)&game->scene->map);
	free_ptr((void **)&game->scene);
	if (game->mlx != NULL)
	{
		mlx_destroy_image(game->mlx, game->img->sprite_img);
		mlx_destroy_image(game->mlx, game->sprite->ea->sprite_img);
		mlx_destroy_image(game->mlx, game->sprite->no->sprite_img);
		mlx_destroy_image(game->mlx, game->sprite->so->sprite_img);
		mlx_destroy_image(game->mlx, game->sprite->we->sprite_img);
		free_ptr((void **)&game->sprite->ea);
		free_ptr((void **)&game->sprite->so);
		free_ptr((void **)&game->sprite->we);
		free_ptr((void **)&game->sprite->no);
		free_ptr((void **)&game->move);
		free_ptr((void **)&game->sprite);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free_ptr((void **)&game->mlx);
		free_ptr((void **)&game);
	}
	exit(0);
	return 1;
}
