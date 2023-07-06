/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:47:18 by ccamargo          #+#    #+#             */
/*   Updated: 2023/07/05 22:42:51 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/* static int are_textures_valid(t_scene *scene)
{
	throw_err(TEXTURES_INVALID);
	return (1);
} */

int	is_scene_valid(char *map_path)
{
	t_scene	scene;

	scene.fd = open(map_path, O_RDONLY);
	if (scene.fd < 0)
	{
		throw_err(MAP_NONEXISTENT);
		return (0);
	}
	initialize_scene(&scene, map_path);
	//if (!are_textures_valid(&scene))
	//    return (0);
	close(scene.fd);
	close_scene(&scene);
	return (1);
}
