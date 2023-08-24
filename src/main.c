/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:39:48 by christian         #+#    #+#             */
/*   Updated: 2023/08/24 03:22:15 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// int	main(int argc, char **argv)
// {
// 	t_scene	scene;

// 	if (!is_param_valid(argc, argv) || !is_scene_valid(argv[1], &scene))
// 	{
// 		close_scene(&scene);
// 		exit(1);
// 	}
// 	close_scene(&scene);
// 	return (0);
// }

#include <mlx.h>

int	main(void)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
}