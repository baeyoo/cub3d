/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:34:13 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:34:15 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*rslt;

	i = 0;
	rslt = malloc(ft_strlen(str) + 1);
	while (*str)
		rslt[i++] = *str++;
	rslt[i] = 0;
	return (rslt);
}

int	ft_strcomp(char c, char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == c)
			return (ret + 1);
		ret++;
	}
	return (0);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == 32)
		i++;
	if (str[i] != '\n')
		return (1);
	return (0);
}

int	ft_paraculo(char **line)
{
	while (**line == ' ')
		(*line)++;
	if (**line == '\0')
		return (0);
	return (1);
}

int	ft_paraparaculo(char **line)
{
	if (**line == ',')
	{
		(*line)++;
		while (**line == ' ')
			(*line)++;
	}
	if (**line >= '0' && **line <= '9')
		return (1);
	return (0);
}
