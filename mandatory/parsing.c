/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:33:03 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:33:05 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

int	ft_res(t_vars *vars, char *line)
{
	if (vars->nsew.res++ > 0)
		fermagioco(8);
	vars->nsew.res++;
	if (ft_paraculo(&line) == 0)
		fermagioco(8);
	while (*line >= '0' && *line <= '9')
	{
		vars->mappa.width = (vars->mappa.width * 10) + (*line - 48);
		line++;
	}
	if (ft_paraculo(&line) == 0)
		fermagioco(8);
	while (*line >= '0' && *line <= '9')
	{
		vars->mappa.height = (vars->mappa.height * 10) + (*line - 48);
		line++;
	}
	if (ft_paraculo(&line) == 1)
		fermagioco(8);
	return (1);
}

char	*ft_path(char *line, int i, t_vars *vars)
{
	while (*line == 32)
		line++;
	if (i == 0)
		vars->nsew.nord++;
	else if (i == 1)
		vars->nsew.sud++;
	else if (i == 2)
		vars->nsew.est++;
	else if (i == 3)
		vars->nsew.ovest++;
	else if (i == 4)
		vars->nsew.sprite++;
	return (ft_strdup(line));
}

int	ft_support_support_parsing(int i, t_vars *vars, char *line)
{
	if (line[0] == 'E' && line[1] == 'A')
	{
		vars->texture[3].path = ft_path(&line[2], 3, vars);
		i++;
	}
	else if (line[0] == 'S')
	{
		vars->texture[4].path = ft_path(&line[2], 4, vars);
		i++;
	}
	else if (line[0] == 'C')
	{
		init_color(vars, &line[1], 0);
		i++;
	}
	else if (line[0] == 'F')
	{
		init_color(vars, &line[1], 1);
		i++;
	}
	return (i);
}

int	ft_support_parsing(int i, t_vars *vars, char *line)
{
	ft_paraculo(&line);
	if (line[0] == 'R' && ft_strisdigit(&line[1]))
	{
		ft_res(vars, &line[1]);
		i++;
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		vars->texture[0].path = ft_path(&line[2], 0, vars);
		i++;
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		vars->texture[1].path = ft_path(&line[2], 1, vars);
		i++;
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		vars->texture[2].path = ft_path(&line[2], 2, vars);
		i++;
	}
	else
		i = ft_support_support_parsing(i, vars, line);
	return (i);
}

int	ft_parsing(t_vars *vars, int fd)
{
	int		i;
	char	*line;

	i = 0;
	vars->mappa.width = 0;
	vars->mappa.height = 0;
	line = NULL;
	init_nsew(vars);
	while (i < 8 && ((get_next_line(&line, fd)) > 0))
	{
		i = ft_support_parsing(i, vars, line);
		free (line);
		line = NULL;
	}
	free(line);
	check_input(vars);
	vars->mappa.mappa = malloc_next_line(fd, vars);
	sprite__(vars);
	return (1);
}
