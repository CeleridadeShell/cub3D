/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:23:51 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/07 21:30:03 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->input_keys.w = TRUE;
	if (keycode == KEY_S)
		game->input_keys.s =TRUE;
	if (keycode == KEY_D)
		game->input_keys.d = TRUE;
	if (keycode == KEY_A)
		game->input_keys.a = TRUE;
	if (keycode == KEY_RIGHT)
		game->input_keys.right = TRUE;
	if (keycode == KEY_LEFT)
		game->input_keys.left = TRUE;
	return (0);
}

int key_release(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_W)
		game->input_keys.w = TRUE;
	if (keycode == KEY_S)
		game->input_keys.s =TRUE;
	if (keycode == KEY_D)
		game->input_keys.d = TRUE;
	if (keycode == KEY_A)
		game->input_keys.a = TRUE;
	if (keycode == KEY_RIGHT)
		game->input_keys.right = TRUE;
	if (keycode == KEY_LEFT)
		game->input_keys.left = TRUE;
	return (0);
}
