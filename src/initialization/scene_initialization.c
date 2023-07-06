/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:28:33 by ccamargo          #+#    #+#             */
/*   Updated: 2023/07/06 19:00:45 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	open_fd(t_scene *scene, char *map_path)
{
	scene->fd = open(map_path, O_RDONLY);
	if (scene->fd < 0)
	{
		throw_err(MAP_NONEXISTENT);
		return (0);
	}
	return (1);
}

static int	count_lines(t_scene *scene, char *map_path, int line_count)
{
	char	*gnl_line;

	if (!open_fd(scene, map_path))
		return (-1);
	gnl_line = get_next_line(scene->fd);
	while (gnl_line)
	{
		line_count++;
		ft_freethis(&gnl_line, NULL);
		gnl_line = get_next_line(scene->fd);
	}
	ft_freethis(&gnl_line, NULL);
	close(scene->fd);
	return (line_count);
}

static int	feed_scene_lines(t_scene *scene, char *map_path, int line_count)
{
	char	*treated_line;
	char	*gnl_line;

	if (!open_fd(scene, map_path))
		return (0);
	gnl_line = get_next_line(scene->fd);
	while (gnl_line)
	{
		if (ft_strrchr(gnl_line, '\n'))
		{
			treated_line = ft_substr(gnl_line, 0, ft_strrchr(gnl_line, '\n') \
			- gnl_line);
			ft_freethis(&gnl_line, NULL);
			scene->scene_lines[line_count] = treated_line;
		}
		else
			scene->scene_lines[line_count] = gnl_line;
		gnl_line = get_next_line(scene->fd);
		line_count++;
	}
	ft_freethis(&gnl_line, NULL);
	close(scene->fd);
	return (1);
}

int	initialize_scene(t_scene *scene, char *map_path)
{
	int		line_count;

	line_count = count_lines(scene, map_path, 0);
	if (line_count < 0)
		return (0);
	scene->scene_lines = (char **) ft_calloc(line_count + 1, sizeof(char *));
	if (!scene->scene_lines)
		return (0);
	if (!feed_scene_lines(scene, map_path, 0))
		return (0);
	scene->no = NULL;
	scene->so = NULL;
	scene->we = NULL;
	scene->ea = NULL;
	scene->f = -1;
	scene->c = -1;
	scene->map = NULL;
	return (1);
}
