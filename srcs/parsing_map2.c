/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:32:58 by user42            #+#    #+#             */
/*   Updated: 2021/10/01 16:34:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_top(t_recup *recup, int i, int j)
{
	int	k;

	k = 0;
	while (k < i)
	{
		if (recup->map[k][j] == '1')
			return (0);
		k++;
	}
	return (1);
}

int	ft_check_bottom(t_recup *recup, int i, int j)
{
	int	k;

	k = i;
	while (k < recup->nblines)
	{
		if (recup->map[k][j] == '1')
			return (0);
		k++;
	}
	return (1);
}

int	ft_check(t_recup *recup, int i, int j)
{
	while (recup->map[i][j])
	{
		if (recup->map[i][j] == '1')
			j++;
		else if (recup->map[i][j] == '0')
		{
			if (ft_check_top(recup, i, j) == 1)
				return (1);
			if (ft_check_bottom(recup, i, j) == 1)
				return (1);
			j++;
		}
		else
			j++;
	}
	return (0);
}

int	ft_surround(t_recup *recup)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	while (i < recup->nblines)
	{
		j = 0;
		check = ft_check(recup, i, j);
		if (check == 1)
			return (1);
		else
			i++;
	}
	return (0);
}

void	ft_malloc(t_recup *recup)
{
	recup->map = malloc(sizeof(char *) * recup->nblines);
	if (!(recup->map))
		ft_error(recup, "Error\nProblem with malloc\n");
	recup->coord_coll = malloc(sizeof(*(recup->coord_coll)) * recup->nbr_coll);
	if (!(recup->coord_coll))
		ft_error(recup, "Error\nProblem with malloc\n");
	recup->coord_exit = malloc(sizeof(*(recup->coord_exit)) * recup->nbr_exit);
	if (!(recup->coord_exit))
		ft_error(recup, "Error\nProblem with malloc\n");
}
