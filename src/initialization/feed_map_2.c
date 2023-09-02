/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:00:17 by ccamargo          #+#    #+#             */
/*   Updated: 2023/09/02 14:05:34 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_horizontal_walls(t_scene *scene, int map_len)
{
	int	i;

	i = 0;
	while (scene->map[0][i])
	{
		if (scene->map[0][i] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (scene->map[map_len - 1][i])
	{
		if (scene->map[map_len - 1][i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_vertical_walls(t_scene *scene, int map_len)
{
	int	i;

	i = 1;
	while (i < map_len - 1)
	{
		if (scene->map[i][0] != '1' || \
		scene->map[i][ft_strlen(scene->map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_walled(t_scene *scene)
{
	int	map_len;

	map_len = 0;
	while (scene->map[map_len])
		map_len++;
	if (!check_horizontal_walls(scene, map_len))
		return (0);
	if (!check_vertical_walls(scene, map_len))
		return (0);
	return (1);
}
