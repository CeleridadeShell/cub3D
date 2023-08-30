/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_initialization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:56:45 by ccamargo          #+#    #+#             */
/*   Updated: 2023/08/30 16:27:07 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/*
Scans for colors for floor and celling in .cub scene file.
Checks if there is only one color for possible locales.
Checks if there are colors for possible locales.
*/

int	feed_scene_floor_and_celling(t_scene *scene)
{
	size_t		i;

	i = 0;
	while (scene->scene_lines[i])
	{
		if (ft_strncmp(scene->scene_lines[i], "F ", 2) == 0)
		{
			if (scene->f >> 30 == 0)
			{
				scene->f = parse_color(ft_substr(scene->scene_lines[i], ft_strchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i])));
				scene->f = (1 << 30 | scene->f);
			}
			else
			{
				throw_err(COLORS_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene_lines[i], "C ", 2) == 0)
		{
			if (scene->c >> 30 == 0)
			{
				scene->c = parse_color(ft_substr(scene->scene_lines[i], ft_strchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i])));
				scene->c = (1 << 30 | scene->c);
			}
			else
			{
				throw_err(COLORS_INVALID);
				return (0);
			}
		}
		i++;
	}
	if (scene->f >> 31 == 1 || scene->c >> 31 == 1)
	{
		throw_err(COLORS_INVALID);
		return (0);
	}
	return (1);
}

/*
Scans for textures path in .cub scene file.
Checks if there is only one texture per cardinal direction.
Checks if there are textures for all cardinal directions.
*/

int	feed_scene_textures(t_scene *scene)
{
	size_t		i;

	i = 0;
	while (scene->scene_lines[i])
	{
		if (ft_strncmp(scene->scene_lines[i], "NO ", 3) == 0)
		{
			if (scene->no == NULL)
				scene->no = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
			else
			{
				throw_err(TEXTURES_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene_lines[i], "SO ", 3) == 0)
		{
			if (scene->so == NULL)
				scene->so = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
			else
			{
				throw_err(TEXTURES_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene_lines[i], "WE ", 3) == 0)
		{
			if (scene->we == NULL)
				scene->we = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
			else
			{
				throw_err(TEXTURES_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene_lines[i], "EA ", 3) == 0)
		{
			if (scene->ea == NULL)
				scene->ea = ft_substr(scene->scene_lines[i], ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, ft_strlen(scene->scene_lines[i]));
			else
			{
				throw_err(TEXTURES_INVALID);
				return (0);
			}
		}
		i++;
	}
	if (!scene->no || !scene->so || !scene->we || !scene->ea)
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	return (1);
}
