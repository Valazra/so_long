/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:56:01 by user42            #+#    #+#             */
/*   Updated: 2021/09/21 14:56:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			s2[j] = s[i];
			j++;
		}
		i++;
	}
	s2[j] = '\0';
	return (s2);
}
