/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:37:58 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/08 03:20:59 by mcarecho         ###   ########.fr       */
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

