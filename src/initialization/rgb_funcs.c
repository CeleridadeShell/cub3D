/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:11:21 by ccamargo          #+#    #+#             */
/*   Updated: 2023/08/28 18:22:50 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

int	get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}

unsigned int	parse_color(char *RGB)
{
	char			*r;
	char			*g;
	char			*b;
	unsigned int	color;

	r = ft_substr(RGB, 0, ft_strchr(RGB, ',') - RGB);
	g = ft_substr(RGB, ft_strchr(RGB, ',') - RGB + 1, (ft_strrchr(RGB, ',') - \
	RGB) - (ft_strchr(RGB, ',') - RGB + 1));
	b = ft_substr(RGB, ft_strrchr(RGB, ',') - RGB + 1, ft_strlen(RGB));
	color = create_rgb(ft_atoi(r), ft_atoi(g), ft_atoi(b));
	ft_freethis(&RGB, NULL);
	return (color);
}
