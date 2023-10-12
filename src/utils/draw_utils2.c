/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:57:00 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/08 07:27:18 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void verify_shade(t_ray *ray, t_ray_print *p_ray)
{
    p_ray->ty = p_ray->ty_off * p_ray->ty_step;
    if (p_ray->shade == 1)
    {
        p_ray->tx = (int)(ray->rx) % 64;
        if (ray->ra > 180)
            p_ray->tx = 63 - p_ray->tx;
    }
    else
    {
        p_ray->tx = (int)(ray->ry) % 64;
        if (ray->ra > 90 && ray->ra < 270)
            p_ray->tx = 63 - p_ray->tx;
    }
}

int    get_sprite_color(int pixel, char *sprite, int shade)
{
    return (create_trgb(shade, get_r((int)sprite[pixel + 2]),
            get_g((int)sprite[pixel + 1]),
            get_b((int)sprite[pixel])));
}
