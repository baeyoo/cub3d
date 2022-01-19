/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:34:25 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:34:27 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

void	readtwo(t_vars *vars)
{
	int		i;
	int		j;
	double	vectX;
	double	vectY;

	i = 0;
	j = 0;
	while (i < (vars->mappa.mapX * vars->mappa.mapY))
	{
		if (vars->mappa.mappa[i] == '2')
		{
			vars->sprite[j].y = ((i / vars->mappa.mapX) * 64) + 32;
			vars->sprite[j].x = ((i % vars->mappa.mapX) * 64) + 32;
			vectX = vars->sprite[j].x - vars->stato.posx;
			vectY = -(vars->sprite[j].y - vars->stato.posy);
			vars->sprite[j].distanza = sqrt((vectX * vectX) + (vectY * vectY));
			j++;
		}
		i++;
	}
}

double	setang(double ang1, double ang2)
{
	double	diff;

	diff = ang1 - ang2;
	if (fabs(diff) < 180)
		return (diff);
	if (ang1 > ang2)
		diff = -((2 * 180 - ang1) + ang2);
	else
		diff = (2 * 180 - ang2) + ang1;
	return (diff);
}

void	ics(t_vars *vars, int i, int x, int a)
{
	if (x >= 0)
		dibuja(vars, i, x, a);
}

void	ft_calc(t_vars *vars, int j)
{
	double	q1;
	double	q2;
	double	vectX;
	double	vectY;

	vectX = vars->sprite[j].x - vars->stato.posx;
	vectY = -(vars->sprite[j].y - vars->stato.posy);
	q1 = (vectX) * (vectX);
	q2 = (vectY) * (vectY);
	vars->sprite[j].distanza = sqrt(q1 + q2);
	vars->sprite[j].angolo = FixAng(atan2(vectY, vectX) * 180 / PI);
	vars->sprite[j].diffang = setang(vars->stato.angle,
			vars->sprite[j].angolo);
	vars->sprite[j].pixdim = fabs((MAPS * vars->mappa.width)
			/ (vars->sprite[j].distanza));
	vars->sprite[j].center = (vars->mappa.width / 60.00)
		* ((vars->sprite[j].diffang));
}

void	sprite__(t_vars *vars)
{
	t_sprite	sprite;

	vars->sprite = malloc(vars->ns * sizeof(sprite));
}
