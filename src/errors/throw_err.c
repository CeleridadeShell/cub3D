/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:42:11 by ccamargo          #+#    #+#             */
/*   Updated: 2023/07/05 21:21:10 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
		ft_printf("One or more textures could not be found on specified path \
		or some file could not be open\n");
}
