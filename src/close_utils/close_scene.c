/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:46:33 by ccamargo          #+#    #+#             */
/*   Updated: 2023/09/07 19:07:01 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	free_scene_lines(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->scene_lines[i])
	{
		ft_freethis(&scene->scene_lines[i], NULL);
		i++;
	}
	if (scene->scene_lines)
	{
		free(scene->scene_lines);
		scene->scene_lines = NULL;
	}
}

static void	free_map(t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->map)
	{
		while (scene->map[i])
		{
			ft_freethis(&scene->map[i], NULL);
			i++;
		}
		free(scene->map);
		scene->map = NULL;
	}
}

void	close_scene(t_scene *scene)
{
	free_scene_lines(scene);
	free_map(scene);
	ft_freethis(&scene->no, NULL);
	ft_freethis(&scene->so, NULL);
	ft_freethis(&scene->we, NULL);
	ft_freethis(&scene->ea, NULL);
}
