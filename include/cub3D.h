/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:37:56 by mcarecho          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:05 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Native libraries

# include <stdlib.h>
# include <math.h>

// Non-native libraries

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

// Define

# define NUM_PARAM 1
# define WRONG_FILE 2

// Structs

// Functions
void	throw_err(int err);
int		is_param_valid(int argc, char **argv);

#endif
