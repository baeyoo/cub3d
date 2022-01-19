/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:32:33 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:32:35 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

double	FixAng(double a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

double	DegToRad(double a)
{
	return (a * (PI / 180.0));
}

double	calculate_distance(t_vars *vars)
{
	return (cos(DegToRad(vars->rays.ra)) * (vars->rays.rx - vars->stato.posx)
		- sin(DegToRad(vars->rays.ra)) * (vars->rays.ry - vars->stato.posy));
}
