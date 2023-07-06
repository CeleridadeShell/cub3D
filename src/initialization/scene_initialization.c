/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:28:33 by ccamargo          #+#    #+#             */
/*   Updated: 2023/07/05 22:43:37 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	initialize_scene(t_scene *scene, char *map_path)
{
	char	*gnl_line;
	char	*treated_line;
	int		line_count;

	line_count = 0;
	gnl_line = get_next_line(scene->fd);
	while (gnl_line)
	{
		line_count++;
		ft_freethis(&gnl_line, NULL);
		gnl_line = get_next_line(scene->fd);
	}
	ft_freethis(&gnl_line, NULL);
	close(scene->fd);
	scene->file_lines = (char **) ft_calloc(line_count + 1, sizeof(char *));
	scene->fd = open(map_path, O_RDONLY);
	if (scene->fd < 0)
	{
		throw_err(MAP_NONEXISTENT);
		return ;
	}
	line_count = 0;
	gnl_line = get_next_line(scene->fd);
	while (gnl_line)
	{
		if (ft_strrchr(gnl_line, '\n'))
		{
			treated_line = ft_substr(gnl_line, 0, ft_strrchr(gnl_line, '\n') \
			- gnl_line);
			ft_freethis(&gnl_line, NULL);
			scene->file_lines[line_count] = treated_line;
		}
		else
			scene->file_lines[line_count] = gnl_line;
		gnl_line = get_next_line(scene->fd);
		line_count++;
	}
	ft_freethis(&gnl_line, NULL);
}
