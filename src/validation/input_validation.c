/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:41:00 by ccamargo          #+#    #+#             */
/*   Updated: 2023/06/26 22:41:34 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_param_valid(int argc, char **argv)
{
	char	*substr;

	if (argc != 2)
	{
		throw_err(NUM_PARAM);
		return (0);
	}
	substr = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strncmp(".cub", substr, 4))
	{
		throw_err(WRONG_FILE);
		ft_freethis(&substr, NULL);
		return (0);
	}
	ft_freethis(&substr, NULL);
	return (1);
}
