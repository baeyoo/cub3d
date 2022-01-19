/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:26:44 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:26:45 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

void	ft_swap(t_vars *vars, int j)
{
	int		tempx;
	int		tempy;
	int		tempobj;
	int		temptext;
	double	tempDist;

	tempx = vars->sprite[j].x;
	tempy = vars->sprite[j].y;
	tempobj = vars->sprite[j].obj;
	temptext = vars->sprite[j].text;
	tempDist = vars->sprite[j].distanza;
	vars->sprite[j].x = vars->sprite[j + 1].x;
	vars->sprite[j].y = vars->sprite[j + 1].y;
	vars->sprite[j].obj = vars->sprite[j + 1].obj;
	vars->sprite[j].text = vars->sprite[j + 1].text;
	vars->sprite[j].distanza = vars->sprite[j + 1].distanza;
	vars->sprite[j + 1].x = tempx;
	vars->sprite[j + 1].y = tempy;
	vars->sprite[j + 1].obj = tempobj;
	vars->sprite[j + 1].text = temptext;
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
	step_x = (vars->texture[vars->sprite[i].text].wi / vars->sprite[i].pixdim)
		* (double)a;
	step_y = vars->texture[vars->sprite[i].text].he / (lineH - lineO);
	if (j < 0)
		j = 0;
	while (j < lineH && j < vars->mappa.height)
	{
		if (leggipix(vars->texture[vars->sprite[i].text],
				(int)step_x, (int)((j - lineO) * step_y)) >= 0)
			my_mlx_pixel_put(&vars->img, x, j,
				leggipix(vars->texture[vars->sprite[i].text],
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
	set_snacks(vars);
	draw_sprites(vars);
}
