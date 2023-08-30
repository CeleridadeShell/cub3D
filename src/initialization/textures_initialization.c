/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_initialization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:56:45 by ccamargo          #+#    #+#             */
/*   Updated: 2023/08/29 22:52:25 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	feed_scene_floor_and_celling(t_scene *scene)
{
	size_t		i;

	i = 0;
	while (scene->scene_lines[i])
	{
		if (ft_strncmp(scene->scene_lines[i], "F", 1) == 0)
			scene->f = parse_color(ft_substr(scene->scene_lines[i], ft_strchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i])));
		if (ft_strncmp(scene->scene_lines[i], "C", 1) == 0)
			scene->c = parse_color(ft_substr(scene->scene_lines[i], ft_strchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i])));
		i++;
	}
	if (scene->f >> 31 == 1 || scene->c >> 31 == 1)
	{
		throw_err(COLORS_INVALID);
		return (0);
	}
	return (1);
}

int	feed_scene_textures(t_scene *scene)
{
	size_t		i;

	i = 0;
	while (scene->scene_lines[i])
	{
		if (ft_strncmp(scene->scene_lines[i], "NO", 2) == 0)
			scene->no = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
		if (ft_strncmp(scene->scene_lines[i], "SO", 2) == 0)
			scene->so = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
		if (ft_strncmp(scene->scene_lines[i], "WE", 2) == 0)
			scene->we = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
		if (ft_strncmp(scene->scene_lines[i], "EA", 2) == 0)
			scene->ea = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
		i++;
	}
	if (!scene->no || !scene->so || !scene->we || !scene->ea)
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	return (1);
}
