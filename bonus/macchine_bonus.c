/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macchine_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:23:48 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:23:50 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

void	draw_macchine(t_vars *vars, int i, int x, int a)
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
	step_x = (vars->texture[8].wi / vars->sprite[i].pixdim) * (double)a;
	step_y = vars->texture[8].he / (lineH - lineO);
	if (j < 0)
		j = 0;
	while (j < lineH && j < vars->mappa.height)
	{
		if (leggipix(vars->texture[8],
				(int)step_x, (int)((j - lineO) * step_y)) >= 0)
			my_mlx_pixel_put(&vars->img, x, j, leggipix(vars->texture[8],
					(int)step_x, (int)((j - lineO) * step_y)));
		j++;
	}
}

int	init_macchine(t_vars *vars)
{
	vars->texture[8].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[8].path,
			&vars->texture[8].wi,
			&vars->texture[8].he);
	if (!vars->texture[8].img.img)
		return (0);
	vars->texture[8].img.addr = mlx_get_data_addr(vars->texture[8].img.img,
			&vars->texture[8].img.bits_per_pixel,
			&vars->texture[8].img.line_length,
			&vars->texture[8].img.endian);
	return (1);
}
