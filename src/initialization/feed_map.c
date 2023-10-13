/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:38:44 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/12 19:04:24 by mcarecho         ###   ########.fr       */
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

static void	find_beginning_of_map(t_scene *scene, int *i, int *j)
{
	int	found_beginning_of_map;

	found_beginning_of_map = 0;
	while (scene->scene_lines[*i])
	{
		*j = 0;
		while (scene->scene_lines[*i][*j])
		{
			if (!ft_strchr(VALID_CHARS, scene->scene_lines[*i][*j]))
				break ;
			else
			{
				(*j)++;
				if (!scene->scene_lines[*i][*j])
					found_beginning_of_map = 1;
			}
		}
		if (found_beginning_of_map == 1)
			break ;
		(*i)++;
	}
}

static void	extract_map(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	find_beginning_of_map(scene, &i, &j);
	j = i;
	while (scene->scene_lines[j])
		j++;
	scene->map = (char **) ft_calloc(j - i + 1, sizeof(char *));
	j = 0;
	while (scene->scene_lines[i])
	{
		scene->map[j] = ft_strdup(scene->scene_lines[i]);
		j++;
		i++;
	}
	scene->max_y = j;
	scene->max_x = ft_strlen(scene->map[0]);
}

int	feed_scene_map(t_scene *scene)
{
	if (!is_map_last_element(scene))
	{
		throw_err(MAP_NOT_LAST);
		return (0);
	}
	extract_map(scene);
	if (!is_map_walled(scene))
	{
		throw_err(MAP_NOT_WALLED);
		return (0);
	}
	if (!are_map_chars_valid(scene))
	{
		throw_err(MAP_CHARS_NOT_VALID);
		return (0);
	}
	if (!are_map_players_valid(scene))
	{
		throw_err(MAP_PLAYERS_NOT_VALID);
		return (0);
	}
	return (1);
}
