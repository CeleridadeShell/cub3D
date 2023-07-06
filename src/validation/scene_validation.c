/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:47:18 by ccamargo          #+#    #+#             */
/*   Updated: 2023/07/06 19:18:42 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_scene_valid(char *map_path, t_scene *scene)
{
	if (!initialize_scene(scene, map_path))
		return (0);
	if (!feed_scene_textures(scene))
		return (0);
	return (1);
}
