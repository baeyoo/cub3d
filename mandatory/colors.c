/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:31:06 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:31:08 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

void	init_backcolor(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		vars->sfondo[i].r = -1;
		vars->sfondo[i].g = -1;
		vars->sfondo[i].b = -1;
		i++;
	}
}

void	init_color(t_vars *vars, char *line, int i)
{
	if (vars->sfondo[i].r == -1 && vars->sfondo[i].g == -1
		&& vars->sfondo[i].b == -1)
	{
		vars->sfondo[i].r = 0;
		vars->sfondo[i].g = 0;
		vars->sfondo[i].b = 0;
	}
	else
		fermagioco(9);
	ft_color(vars, line, i);
}

int	ft_color(t_vars *vars, char *line, int i)
{
	if (ft_paraculo(&line) == 0)
		fermagioco(9);
	while (*line >= '0' && *line <= '9')
	{
		vars->sfondo[i].r = (vars->sfondo[i].r * 10) + (*line - 48);
		line++;
	}
	if (ft_paraparaculo(&line) == 0)
		fermagioco(9);
	while (*line >= '0' && *line <= '9')
	{
		vars->sfondo[i].g = (vars->sfondo[i].g * 10) + (*line - 48);
		line++;
	}
	if (ft_paraparaculo(&line) == 0)
		fermagioco(9);
	while (*line >= '0' && *line <= '9')
	{
		vars->sfondo[i].b = (vars->sfondo[i].b * 10) + (*line - 48);
		line++;
	}
	if (ft_paraculo(&line) == 1)
		fermagioco(9);
	return (1);
}

void	ft_numcolor(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (vars->sfondo[i].r < 0 || vars->sfondo[i].r > 255)
			fermagioco(9);
		if (vars->sfondo[i].g < 0 || vars->sfondo[i].g > 255)
			fermagioco(9);
		if (vars->sfondo[i].b < 0 || vars->sfondo[i].b > 255)
			fermagioco(9);
		vars->sfondo[i].color = create_trgb(0, vars->sfondo[i].r,
				vars->sfondo[i].g, vars->sfondo[i].b);
		i++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
