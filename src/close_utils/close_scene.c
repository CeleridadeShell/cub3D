/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:46:33 by ccamargo          #+#    #+#             */
/*   Updated: 2023/08/30 19:06:03 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	close_scene(t_scene *scene)
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
	ft_freethis(&scene->no, NULL);
	ft_freethis(&scene->so, NULL);
	ft_freethis(&scene->we, NULL);
	ft_freethis(&scene->ea, NULL);
}
