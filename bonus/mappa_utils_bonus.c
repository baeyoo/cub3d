/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappa_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:24:18 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:24:20 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

void	init_nsew(t_vars *vars)
{
	vars->nsew.nord = 0;
	vars->nsew.sud = 0;
	vars->nsew.est = 0;
	vars->nsew.ovest = 0;
	vars->nsew.sprite = 0;
	vars->nsew.res = 0;
}

void	find_nsew(t_vars *vars, int i, int j)
{
	if (vars->mappa.mappa[i * vars->mappa.mapX + j] == 'N' \
	|| vars->mappa.mappa[i * vars->mappa.mapX + j] == 'S' \
	|| vars->mappa.mappa[i * vars->mappa.mapX + j] == 'E' \
	|| vars->mappa.mappa[i * vars->mappa.mapX + j] == 'W')
	{
		if (vars->stato.init == 1)
			fermagioco(0);
		vars->stato.posx = (j * 64 + 32);
		vars->stato.posy = (i * 64 + 32);
		if (vars->mappa.mappa[i * vars->mappa.mapX + j] == 'N')
			vars->stato.angle = 90;
		else if (vars->mappa.mappa[i * vars->mappa.mapX + j] == 'S')
			vars->stato.angle = 270;
		else if (vars->mappa.mappa[i * vars->mappa.mapX + j] == 'E')
			vars->stato.angle = 0;
		else
			vars->stato.angle = 180;
		vars->stato.dex = cos(DegToRad(vars->stato.angle));
		vars->stato.dey = -sin(DegToRad(vars->stato.angle));
		vars->mappa.mappa[i * vars->mappa.mapX + j] = 0;
		vars->stato.init = 1;
	}
}

void	findplayer(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->stato.init = 0;
	while (i < vars->mappa.mapY)
	{
		j = 0;
		while (j < vars->mappa.mapX)
		{
			find_nsew(vars, i, j);
			j++;
		}
		i++;
	}
	if (vars->stato.init == 0)
		fermagioco(6);
}

void	checkresult2(int *str, int i, int k)
{
	if (ft_strcomp(str[i], "0234"))
	{
		if (!(ft_strcomp(str[i + 1], "01234NSEW") && \
		ft_strcomp(str[i - 1], "01234NSEW") && \
		ft_strcomp(str[i - k], "01234NSEW") && \
		ft_strcomp(str[i + k], "01234NSEW")))
		{
			if (!(ft_strcomp(str[i + 1], "01234NSEW"))
				|| !(ft_strcomp(str[i + k], "01234NSEW")))
				fermagioco(2);
			else
				fermagioco(1);
		}
	}
}

int	checkresult(int *str, t_vars *vars, int j)
{
	int	i;
	int	k;

	k = vars->mappa.mapX;
	i = 0;
	while (i < j && ft_strcomp(str[i], "01234NSEW\n "))
	{
		if (ft_strcomp(str[i], "234"))
			vars->ns++;
		if (str[i] == '3')
			vars->snacks++;
		if (i >= k && i < (j - k))
			checkresult2(str, i, k);
		else
		{
			if (!(ft_strcomp(str[i], "1\n ")))
				return (0);
		}
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}
