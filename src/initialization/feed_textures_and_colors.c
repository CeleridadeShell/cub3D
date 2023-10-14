/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_textures_and_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:56:45 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/13 15:57:41 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/*
Check if provided texture files exist in specified path.
*/

static int	check_textures_exist(t_scene *scene)
{
	scene->fd = open(scene->no, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	scene->fd = open(scene->so, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	scene->fd = open(scene->we, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	scene->fd = open(scene->ea, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	return (1);
}

/*
Scans for colors for floor and celling in .cub scene file.
Checks if there is only one color for possible locales.
Checks if there are colors for possible locales.
*/

int	feed_scene_floor_and_celling(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (scene->scene->s_l[i])
	{
		if (ft_strncmp(scene->scene->s_l[i], "F ", 2) == 0)
		{
			if (scene->f >> 30 == 0)
			{
				scene->f = pa_color(ft_substr(scene->scene->s_l[i],
						ft_strchr(scene->scene->s_l[i], ' ') - scene->scene->s_l[i] + 1, ft_strlen(scene->scene->s_l[i])));
				scene->f = (1 << 30 | scene->f);
			}
			else
			{
				throw_err(COLORS_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene->s_l[i], "C ", 2) == 0)
		{
			if (scene->c >> 30 == 0)
			{
				scene->c = p_color(ft_substr(scene->scene->s_l[i], ft_strchr(scene->scene->s_l[i], ' ') - scene->scene->s_l[i] + 1, ft_strlen(scene->scene->s_l[i])));
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

int feed_scene_textures(t_scene *scene)
{
	size_t i;

	i = 0;
	while (scene->scene->s_l[i])
	{
		if (ft_strncmp(scene->scene->s_l[i], "NO ", 3) == 0)
		{
			if (scene->no == NULL)
				scene->no = ft_substr(scene->scene->s_l[i], ft_strrchr(scene->scene->s_l[i], ' ') - scene->scene->s_l[i] + 1, ft_strlen(scene->scene->s_l[i]));
			else
			{
				throw_err(TEXTURES_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene->s_l[i], "SO ", 3) == 0)
		{
			if (scene->so == NULL)
				scene->so = ft_substr(scene->scene->s_l[i], ft_strrchr(scene->scene->s_l[i], ' ') - scene->scene->s_l[i] + 1, ft_strlen(scene->scene->s_l[i]));
			else
			{
				throw_err(TEXTURES_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene->s_l[i], "WE ", 3) == 0)
		{
			if (scene->we == NULL)
				scene->we = ft_substr(scene->scene->s_l[i], ft_strrchr(scene->scene->s_l[i], ' ') - scene->scene->s_l[i] + 1, ft_strlen(scene->scene->s_l[i]));
			else
			{
				throw_err(TEXTURES_INVALID);
				return (0);
			}
		}
		if (ft_strncmp(scene->scene->s_l[i], "EA ", 3) == 0)
		{
			if (scene->ea == NULL)
				scene->ea = ft_substr(scene->scene->s_l[i], ft_strrchr(scene->scene->s_l[i], ' ') - scene->scene->s_l[i] + 1, ft_strlen(scene->scene->s_l[i]));
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
	if (!check_textures_exist(scene))
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	return (1);
}
