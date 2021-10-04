/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:51:21 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:35:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_depart(t_recup *recup, char c, int i, int j)
{
	if (c == 'P')
	{
		if (recup->depart != 'x')
			recup->depart = 'B';
		else
			recup->depart = c;
		recup->coord_depart.x = i;
		recup->coord_depart.y = j;
		return (1);
	}
	return (0);
}

void	ft_copy_map(t_recup *recup, char *str)
{
	static int	i = 0;
	int			j;

	j = 0;
	recup->map[i] = malloc(sizeof(char) * (recup->sizeline + 1));
	if (!(recup->map[i]))
		ft_error(recup, "Error\nProblem with malloc\n");
	while (str[j] != '\0')
	{
		if (ft_depart(recup, str[j], i, j) == 1)
			recup->map[i][j] = '0';
		else if (ft_exit(recup, str[j], i, j) == 1)
			recup->map[i][j] = '0';
		else if (ft_collectible(recup, str[j], i, j) == 1)
			recup->map[i][j] = '0';
		else
			recup->map[i][j] = str[j];
		j++;
	}
	recup->map[i][j] = '\0';
	i++;
}

int	ft_is_map(t_recup *recup, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] != '0' && str[i] != '1' && str[i] != 'C'\
		&& str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
				recup->wrong_charac = 'B';
			if (str[i] == 'C')
				recup->nbr_coll++;
			if (str[i] == 'E')
				recup->nbr_exit++;
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(t_recup *recup, char *str)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = -1;

	i = 0;
	if (str[0] == '\0')
		recup->empty_line = 1;
	if (ft_is_map(recup, str) == 1)
	{
		i = ft_strlen(str);
		if (i > ssizeline && ssizeline == -1)
		{
			ssizeline = i;
			recup->sizeline = ssizeline;
		}
		else if (i != recup->sizeline)
			recup->line_len = -1;
		snblines = snblines + 1;
	}
	recup->nblines = snblines;
}
