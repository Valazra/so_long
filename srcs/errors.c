/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:16:10 by user42            #+#    #+#             */
/*   Updated: 2021/10/01 16:19:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing_errors(t_recup *recup)
{
	if (recup->depart == 'x')
		ft_error(recup, "Error\nNo player in the map\n");
	if (recup->coll == 'x')
		ft_error(recup, "Error\nNo collectible in the map\n");
	if (recup->exit == 'x')
		ft_error(recup, "Error\nNo exit in the map\n");
	if (ft_emptyline(recup) == 1)
		ft_error(recup, "Error\nEmpty line in the map\n");
	if (ft_rectangular(recup) == 1)
		ft_error(recup, "Error\nMap isn't rectangular\n");
	if (ft_surround(recup) == 1)
		ft_error(recup, "Error\nProblem with surround\n");
	if (ft_first_last_carac(recup) == 1)
		ft_error(recup, "Error\nProblem with surround\n");
}

void	ft_error(t_recup *recup, char *str)
{
	int	i;

	i = 0;
	write(1, str, ft_strlen(str));
	ft_free(recup);
	exit(0);
}
