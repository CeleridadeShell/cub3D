/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_initialization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:56:45 by ccamargo          #+#    #+#             */
/*   Updated: 2023/07/06 19:20:30 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	feed_scene_textures(t_scene *scene)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(scene->scene_lines[i], "NO", 2) == 0)
			scene->no = ft_substr(scene->scene_lines[0], ft_strrchr(scene->scene_lines[0], ' ') - scene->scene_lines[0] + 1, ft_strlen(scene->scene_lines[0]));
		if (ft_strncmp(scene->scene_lines[i], "SO", 2) == 0)
			scene->so = ft_substr(scene->scene_lines[1], ft_strrchr(scene->scene_lines[1], ' ') - scene->scene_lines[1] + 1, ft_strlen(scene->scene_lines[1]));
		if (ft_strncmp(scene->scene_lines[i], "WE", 2) == 0)
			scene->we = ft_substr(scene->scene_lines[2], ft_strrchr(scene->scene_lines[2], ' ') - scene->scene_lines[2] + 1, ft_strlen(scene->scene_lines[2]));
		if (ft_strncmp(scene->scene_lines[i], "EA", 2) == 0)
			scene->ea = ft_substr(scene->scene_lines[3], ft_strrchr(scene->scene_lines[3], ' ') - scene->scene_lines[3] + 1, ft_strlen(scene->scene_lines[3]));
		i++;
	}
	if (!scene->no || !scene->so || !scene->we || !scene->ea)
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	return (1);
}
