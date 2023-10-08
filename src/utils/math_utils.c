/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:52:22 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/07 20:55:06 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

float fix_ang(float ang)
{
	if ((int)a > 359.9)
		return (a - 360);
	if ((int)a < 0.9)
		return (a + 360);
	return (a);
}

float deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}
