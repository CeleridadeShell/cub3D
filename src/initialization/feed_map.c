/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:38:44 by ccamargo          #+#    #+#             */
/*   Updated: 2023/08/30 19:02:52 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	is_map_last_element(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (scene->scene_lines[i])
		i++;
	i--;
	while (scene->scene_lines[i][j])
	{
		if (!ft_strchr(VALID_CHARS, scene->scene_lines[i][j]))
			return (0);
		j++;
	}
	return (1);
}

static void	extract_map(t_scene *scene)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (scene->scene_lines[i])
	{
		while (scene->scene_lines[i][j])
		{
			if (!ft_strchr(VALID_CHARS, scene->scene_lines[i][j]))
			{
				break ;
			}
			else
			{
				j++;
				if (!scene->scene_lines[i][j])
					flag = 1;
			}
		}
		if (flag == 1)
			break ;
		i++;
	}
	j = i;
	while (scene->scene_lines[j])
		j++;
	scene->map = (char **) ft_calloc(j - i, sizeof(char *));
	j = 0;
	while (scene->scene_lines[i])
	{
		scene->map[j] = ft_strdup(scene->scene_lines[i]);
		j++;
		i++;
	}
/* 	i = 0;
	while (scene->map[i])
	{
		ft_printf("%s\n", scene->map[i]);
		i++;
	} */
}

int	feed_scene_map(t_scene *scene)
{
	if (!is_map_last_element(scene))
	{
		throw_err(MAP_NOT_LAST);
		return (0);
	}
	extract_map(scene);
	return (1);
}
