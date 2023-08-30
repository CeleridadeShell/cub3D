/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:42:11 by ccamargo          #+#    #+#             */
/*   Updated: 2023/08/30 16:22:55 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	print_model_colors(void)
{
	ft_printf("One or more colors could not be parsed correctly!\n");
	ft_printf("Only values from 0 to 255 are valid!\n");
	ft_printf("Only one color for the floor and one for the celling is \
valid!\n");
	ft_printf("Colors must be specified as follows:\n");
	ft_printf("F 255,255,0\n");
	ft_printf("C 0,255,255\n");
}

static void	print_model_textures(void)
{
	ft_printf("One or more textures could not be found on specified path, \
some file could not be open or there is more than one texture per \
position!\n\n");
	ft_printf("Textures must be specified as follows:\n");
	ft_printf("NO ./path_to_the_north_texture\n");
	ft_printf("SO ./path_to_the_south_texture\n");
	ft_printf("WE ./path_to_the_west_texture\n");
	ft_printf("EA ./path_to_the_east_texture\n");
}

void	throw_err(int err)
{
	ft_printf("Error\n");
	if (err == NUM_PARAM)
		ft_printf("Cub3D only accepts one parameter!\n");
	if (err == WRONG_FILE)
		ft_printf("Cub3D only accepts files of .cub type!\n");
	if (err == MAP_NONEXISTENT)
		ft_printf("Could not find scene file on specified path or file failed \
to open!\n");
	if (err == TEXTURES_INVALID)
		print_model_textures();
	if (err == COLORS_INVALID)
		print_model_colors();
}
