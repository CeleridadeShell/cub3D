/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:46:33 by ccamargo          #+#    #+#             */
/*   Updated: 2023/07/05 22:43:10 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	close_scene(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->file_lines[i])
	{
		ft_freethis(&scene->file_lines[i], NULL);
		i++;
	}
	free(scene->file_lines);
	scene->file_lines = NULL;
}
