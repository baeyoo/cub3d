/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappa_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:24:01 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:24:03 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

char	*fillmalloc2(char *str, int ck)
{
	if (ck == 0)
	{
		while (*str == '\n')
			str++;
	}
	if (ck == 1)
	{
		if (*str && *str == '\n' && str[1] == '\n')
			fermagioco(1);
		if (*str && *str == '\n')
			str++;
	}
	return (str);
}

int	num(const char *str, t_vars *vars)
{
	int	n;
	int	m;

	m = 0;
	n = 0;
	str = (const char *)fillmalloc2((char *)str, 0);
	while (*str)
	{
		while (*str != '\n' && *str != '\0')
		{	
			n++;
			str++;
		}
		if (n > m)
			m = n;
		if (*str != '\0')
		{
			str++;
			vars->mappa.mapY++;
		}
		n = 0;
	}
	vars->mappa.mapY += 1;
	vars->mappa.mapX = m + 1;
	return ((vars->mappa.mapX) * (vars->mappa.mapY));
}

int	*fillmalloc(char *str, int *s, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	str = fillmalloc2(str, 0);
	while (i < vars->mappa.mapY)
	{
		j = 0;
		while (*str && *str != '\n')
		{
			s[i * vars->mappa.mapX + j] = *str++;
			j++;
		}
		str = fillmalloc2(str, 1);
		while (j < (vars->mappa.mapX - 1))
		{
			s[i * vars->mappa.mapX + j] = 32;
			j++;
		}
		s[i * vars->mappa.mapX + j] = '\n';
		i++;
	}
	return (s);
}

int	*malloc_next_line(int fd, t_vars *vars)
{
	char			string[1024];
	int				*total;
	int				*result;
	int				size;

	vars->ns = 0;
	vars->snacks = 0;
	vars->mappa.mapY = 0;
	string[1023] = 0;
	read(fd, string, 1024);
	size = num(string, vars);
	total = (int *)malloc(sizeof(int) * size);
	result = fillmalloc(string, total, vars);
	if (checkresult(result, vars, size) == 0)
		fermagioco(2);
	return (result);
}

void	main_texture(t_vars *vars)
{
	vars->texture[5].path = ft_path("bonus/texture/faccia.xpm", 5, vars);
	vars->texture[6].path = ft_path("bonus/texture/scaryface.xpm", 5, vars);
	vars->texture[7].path = ft_path("bonus/texture/snacks.xpm", 5, vars);
	vars->texture[8].path = ft_path("bonus/texture/macchine.xpm", 5, vars);
	vars->texture[9].path = ft_path("bonus/texture/tar.xpm", 5, vars);
	vars->texture[10].path = ft_path("bonus/texture/volts.xpm", 5, vars);
	vars->texture[11].path = ft_path("bonus/texture/headless.xpm", 5, vars);
	vars->texture[12].path = ft_path("bonus/texture/knight.xpm", 5, vars);
	vars->texture[13].path = ft_path("bonus/texture/ghost.xpm", 5, vars);
	vars->texture[14].path = ft_path("bonus/texture/clown.xpm", 5, vars);
	vars->texture[15].path = ft_path("bonus/texture/sub.xpm", 5, vars);
}
