/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:20:55 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:20:58 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	leggipix(t_texture tex, int x, int y)
{
	char	*dst;
	t_data	*data;

	data = &tex.img;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_walls(t_vars *vars, int r, int i, int j)
{
	unsigned int	pix;
	double			lineH;
	double			lineO;
	double			step_x;
	double			step_y;

	lineH = (MAPS * vars->mappa.height) / vars->distance.distH;
	lineO = (vars->mappa.height / 2) - (lineH / 2);
	lineH += lineO;
	j = lineO + 1;
	if (j < 0)
		j = 0;
	step_x = (vars->texture[i].wi / MAPS) * fmod(vars->distance.hit, MAPS);
	step_y = vars->texture[i].he / (lineH - lineO);
	while (j < lineH && j < vars->mappa.height)
	{
		pix = leggipix(vars->texture[i], (int)step_x,
				(int)((j - lineO) * step_y));
		my_mlx_pixel_put(&vars->img, r, j, pix);
		j++;
	}
}
//1 marmo 2 gres 0 parquet 2 granito | cos usato per fisheye

void	walls(t_vars *vars, int r)
{
	int		i;
	int		j;
	double	ca;

	j = 0;
	ca = FixAng(vars->stato.angle - vars->rays.ra);
	if (vars->distance.distH == vars->distance.distV)
	{
		i = 2;
		if (((vars->stato.posx - vars->rays.rx > 0)))
			i = 3;
	}
	else
	{
		i = 0;
		if (((vars->stato.posy - vars->rays.ry > 0)))
			i = 1;
	}
	vars->distance.distH = vars->distance.distH * cos(DegToRad(ca));
	draw_walls(vars, r, i, j);
}
//nei cicli prima il cielo, poi il pavimento

void	groundsky(t_vars *vars, int r)
{
	int	j;
	int	stop;

	j = 0;
	stop = (vars->mappa.height / 2);
	while (j < stop)
	{
		my_mlx_pixel_put(&vars->img, r, j, vars->sfondo[0].color);
		j++;
	}
	while (j < vars->mappa.height)
	{
		my_mlx_pixel_put(&vars->img, r, j, vars->sfondo[1].color);
		j++;
	}
	walls(vars, r);
}
