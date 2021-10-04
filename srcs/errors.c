/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:16:10 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:38:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing_errors(t_recup *recup)
{
	if (recup->empty_line == 1)
		ft_error(recup, "Error\nEmpty line in the map\n");
	if (recup->line_len == -1)
		ft_error(recup, "Error\nMap isn't rectangular");
}

void	ft_parsing_errors2(t_recup *recup)
{
	if (recup->depart == 'x')
		ft_error(recup, "Error\nNo player in the map\n");
	if (recup->depart == 'B')
		ft_error(recup, "Too many players in the map\n");
	if (recup->wrong_charac == 'B')
		ft_error(recup, "Bad character in the map\n");
	if (recup->coll == 'x')
		ft_error(recup, "Error\nNo collectible in the map\n");
	if (recup->exit == 'x')
		ft_error(recup, "Error\nNo exit in the map\n");
	if (recup->line_len == -1)
		ft_error(recup, "Error\nMap isn't rectangular\n");
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
/*
void	ft_error2(t_recup *recup, char *str, char *str2)
{
	int	i;

	i = 0;
	write(1, str, ft_strlen(str));
	if (str2 != NULL)
	{
		free(str2);
		str2 = NULL;
	}
	ft_free(recup);
	exit(0);
}
*/
