/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:33:27 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:33:29 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

void	ft_swap(t_vars *vars, int j)
{
	int		tempx;
	int		tempy;
	double	tempDist;

	tempx = vars->sprite[j].x;
	tempy = vars->sprite[j].y;
	tempDist = vars->sprite[j].distanza;
	vars->sprite[j].x = vars->sprite[j + 1].x;
	vars->sprite[j].y = vars->sprite[j + 1].y;
	vars->sprite[j].distanza = vars->sprite[j + 1].distanza;
	vars->sprite[j + 1].x = tempx;
	vars->sprite[j + 1].y = tempy;
	vars->sprite[j + 1].distanza = tempDist;
}

void	ft_bubble(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->ns - 1)
	{
		j = 0;
		while (j < vars->ns - i - 1)
		{
			if (vars->sprite[j].distanza < vars->sprite[j + 1].distanza)
				ft_swap(vars, j);
			j++;
		}
		i++;
	}
}

void	dibuja(t_vars *vars, int i, int x, int a)
{
	double			lineH;
	double			lineO;
	int				j;
	double			step_x;
	double			step_y;

	lineH = (MAPS * vars->mappa.height) / (vars->sprite[i].distanza
			* cos(DegToRad(vars->sprite[i].diffang)));
	lineO = (vars->mappa.height / 2) - (lineH / 2);
	lineH += lineO;
	j = lineO + 1;
	step_x = (vars->texture[4].wi / vars->sprite[i].pixdim) * (double)a;
	step_y = vars->texture[4].he / (lineH - lineO);
	if (j < 0)
		j = 0;
	while (j < lineH && j < vars->mappa.height)
	{
		if (leggipix(vars->texture[4],
				(int)step_x, (int)((j - lineO) * step_y)) >= 0)
			my_mlx_pixel_put(&vars->img, x, j, leggipix(vars->texture[4],
					(int)step_x, (int)((j - lineO) * step_y)));
		j++;
	}
}

void	draw_sprites(t_vars *vars)
{
	int	x;
	int	i;
	int	a;

	i = 0;
	while (i < vars->ns)
	{
		a = 0;
		x = (int)((vars->mappa.width / 2) + vars->sprite[i].center
				- (vars->sprite[i].pixdim / 2));
		if (vars->sprite[i].visibile == TRUE && vars->sprite[i].distanza > 1)
		{
			while (a < vars->sprite[i].pixdim && x < vars->mappa.width)
			{
				if (x >= 0 && ((vars->mappa.distanze[x] + 20)
						> (vars->sprite[i].distanza
							* cos(DegToRad(vars->sprite[i].diffang)))))
					ics(vars, i, x, a);
				a++;
				x++;
			}
		}
		i++;
	}
}

void	main_sprite(t_vars *vars)
{
	int		j;

	j = 0;
	ft_bubble(vars);
	while (j < (vars->ns))
	{
		ft_calc(vars, j);
		if (fabs(vars->sprite[j].diffang) < 60.00)
			vars->sprite[j].visibile = TRUE;
		else
			vars->sprite[j].visibile = FALSE;
		j++;
	}
	draw_sprites(vars);
	if (vars->screen == 1)
	{
		screenshot(vars);
		exit (0);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
