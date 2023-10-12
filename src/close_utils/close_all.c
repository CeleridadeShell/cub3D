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
	while (game->scene->map != NULL && --game->scene->max_y >= 0)
		free_ptr((void **)&game->scene->map[game->scene->max_y]);
	free_ptr((void **)&game->scene->map);
	if (game->mlx != NULL)
	{
		mlx_destroy_image(game->mlx, game->img->sprite_img);
		mlx_destroy_image(game->mlx, game->sprites->ea->sprite_img);
		mlx_destroy_image(game->mlx, game->sprites->no->sprite_img);
		mlx_destroy_image(game->mlx, game->sprites->so->sprite_img);
		mlx_destroy_image(game->mlx, game->sprites->we->sprite_img);
		free_ptr((void **)&game->sprites->ea);
		free_ptr((void **)&game->sprites->so);
		free_ptr((void **)&game->sprites->we);
		free_ptr((void **)&game->sprites->no);
		free_ptr((void **)&game->sprites);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free_ptr((void **)&game->mlx);
	}
	exit(0);
	return 1;
}
