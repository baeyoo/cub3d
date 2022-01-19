/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:33:14 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:33:15 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

void	horizontal(t_vars *vars, t_hit *hit)
{
	while (hit->dof < vars->mappa.mapX)
	{
		vars->rays.mx = (int)(vars->rays.rx) >> 6;
		vars->rays.my = (int)(vars->rays.ry) >> 6;
		vars->rays.mp = vars->rays.my * vars->mappa.mapX + vars->rays.mx;
		if (vars->rays.mp > 0 && vars->mappa.mappa[vars->rays.mp] == '1'
			&& vars->rays.mp < vars->mappa.mapX * vars->mappa.mapY)
		{
			hit->dof = vars->mappa.mapX;
			vars->distance.distH = calculate_distance(vars);
		}
		else
		{
			vars->rays.rx += hit->xo;
			vars->rays.ry += hit->yo;
			hit->dof += 1;
		}
	}
	vars->distance.hit = vars->rays.rx;
}

void	horizontal_hit(t_vars *vars, t_hit *hit)
{
	double	Tan;

	hit->dof = 0;
	vars->distance.distH = 10000000;
	Tan = 1.0 / tan(DegToRad(vars->rays.ra));
	if (sin(DegToRad(vars->rays.ra)) > 0.001)
	{
		vars->rays.ry = (((int)vars->stato.posy >> 6) << 6) - 0.0001;
		hit->yo = -64;
	}
	else if (sin(DegToRad(vars->rays.ra)) < -0.001)
	{
		vars->rays.ry = (((int)vars->stato.posy >> 6) << 6) + 64;
		hit->yo = 64;
	}
	else
	{
		vars->rays.rx = vars->stato.posx;
		vars->rays.ry = vars->stato.posy;
		hit->dof = vars->mappa.mapX;
	}
	vars->rays.rx = (vars->stato.posy - vars->rays.ry) * Tan + vars->stato.posx;
	hit->xo = -(hit->yo) * Tan;
	horizontal(vars, hit);
}

void	vertical(t_vars *vars, t_hit *hit)
{
	while (hit->dof < vars->mappa.mapX)
	{
		vars->rays.mx = (int)(vars->rays.rx) >> 6;
		vars->rays.my = (int)(vars->rays.ry) >> 6;
		vars->rays.mp = vars->rays.my * vars->mappa.mapX + vars->rays.mx;
		if (vars->rays.mp > 0 && vars->mappa.mappa[vars->rays.mp] == '1'
			&& vars->rays.mp < (vars->mappa.mapX * vars->mappa.mapY))
		{
			hit->dof = vars->mappa.mapX;
			vars->distance.distV = calculate_distance(vars);
		}
		else
		{
			vars->rays.rx += hit->xo;
			vars->rays.ry += hit->yo;
			hit->dof += 1;
		}
	}
	vars->distance.vx = vars->rays.rx;
	vars->distance.vy = vars->rays.ry;
}

void	vertical_hit(t_vars *vars, t_hit *hit)
{
	double	Tan;

	hit->dof = 0;
	vars->distance.distV = 10000000;
	Tan = tan(DegToRad(vars->rays.ra));
	if (cos(DegToRad(vars->rays.ra)) > 0.001)
	{
		vars->rays.rx = (((int)vars->stato.posx >> 6) << 6) + 64;
		hit->xo = 64;
	}
	else if (cos(DegToRad(vars->rays.ra)) < -0.001)
	{
		vars->rays.rx = (((int)vars->stato.posx >> 6) << 6) - 0.0001;
		hit->xo = -64;
	}
	else
	{
		vars->rays.rx = vars->stato.posx;
		vars->rays.ry = vars->stato.posy;
		hit->dof = vars->mappa.mapX;
	}
	vars->rays.ry = (vars->stato.posx - vars->rays.rx) * Tan + vars->stato.posy;
	hit->yo = -(hit->xo) * Tan;
	vertical(vars, hit);
}

void	check_distanza(t_vars *vars)
{
	t_hit	hit;
	int		r;

	r = 0;
	vars->rays.ra = FixAng(vars->stato.angle + 30);
	while (r < vars->mappa.width)
	{
		vertical_hit(vars, &hit);
		horizontal_hit(vars, &hit);
		if (vars->distance.distV < vars->distance.distH)
		{
			vars->rays.rx = vars->distance.vx;
			vars->rays.ry = vars->distance.vy;
			vars->distance.hit = vars->rays.ry;
			vars->distance.distH = vars->distance.distV;
		}
		groundsky(vars, r);
		vars->mappa.distanze[r] = vars->distance.distH;
		vars->rays.ra = FixAng(vars->rays.ra - (60 / vars->mappa.width));
		r++;
	}
}
