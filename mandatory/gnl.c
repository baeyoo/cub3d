/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:31:31 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:31:33 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*rslt;
	int		i;

	i = 0;
	rslt = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	while (*str1)
		rslt[i++] = *str1++;
	while (*str2)
		rslt[i++] = *str2++;
	rslt[i] = 0;
	return (rslt);
}

int	ft_strchr(char c, char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == c)
			return (ret);
		ret++;
	}
	return (-1);
}

char	*ft_support_get_n_line(char *total, char string[2])
{
	char	*safe;

	if (!total)
		total = ft_strdup(string);
	else
	{
		safe = total;
		total = ft_strjoin(total, string);
		free(safe);
	}
	return (total);
}

int	get_next_line(char **line, int fd)
{
	char	string[2];
	char	*total;

	total = 0;
	while (read(fd, string, 1) > 0)
	{
		string[1] = 0;
		total = ft_support_get_n_line(total, string);
		if (ft_strchr('\n', total) >= 0)
		{
			total[ft_strchr('\n', total)] = 0;
			*line = total;
			return (1);
		}
	}
	if (total)
		*line = total;
	else
		*line = ft_strdup("");
	return (0);
}
