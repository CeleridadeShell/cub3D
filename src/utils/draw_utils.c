/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:37:58 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/08 02:11:44 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void square(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while(++i < 20)
	{
		j = -1;
		while (++j <20 )
		{
			if (i == 0 || i ==20)
				my_mlx_pixel_put(game->img, x + j, y + i, 0xfff);
			else if (j == 0 || j == 20)
				my_mlx_pixel_put(game->img, x + j, y + i, 0xfff);
			else
				my_mlx_pixel_put(game->img, x + j, y + i, color);
		}
	}

}

draw_floor_celing(t_game *game, t_ray *ray, t_ray_print *p_ray)
{
	draw_line(game, (int [2]{ray->r, 0}, (int [2]){ray->r, p_ray->line_off}, game->scene->c));
	draw_line(game, (int [2]{ray->r, p_ray->line_off + p_ray->line_h}, (int [2]){ray->r, MAP_Y}, game->scene->f));
}

draw_wall(t_game *game, t_ray *ray, t_ray_print *p_ray)
{
	int y;

	verify_shade(ray, draws);
	y = -1;
	while(+yy < draws->line_h)
	{
		p_ray->color = ((int)(p_ray->ty) * 64 + (int)(p_ray->tx)) * 4;
		if (ray->eye_h == 'N')
			p_ray->color = get_sprite_color(p_ray->color, game->scene->so->addr, p_ray->shade);
		if (ray->eye_h == 'E')
			p_ray->color = get_sprite_color(p_ray->color, game->scene->we->addr, p_ray->shade);
		if (ray->eye_h == 'W')
			p_ray->color = get_sprite_color(p_ray->color, game->scene->ea->addr, p_ray->shade);
		if (ray->eye_h == 'S')
			p_ray->color = get_sprite_color(p_ray->color, game->scene->no->addr, p_ray->shade);
		my_mlx_pixel_put(game->img, ray->r, p_ray->line_off + y, p_ray->color);
		p_ray->ty += p_ray->ty_step;
	}
}
