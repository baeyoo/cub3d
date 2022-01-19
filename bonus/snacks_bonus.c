/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snacks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:26:25 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:26:26 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

void	check_sound(t_vars *vars)
{
	if (vars->gnam == 1)
	{
		system("afplay bonus/biscottino.mp3 &>/dev/null &");
		vars->gnam = 0;
	}
}

void	set_snacks(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->ns)
	{
		if (vars->sprite[i].obj == 1)
			vars->sprite[i].pixdim = fabs((16 * vars->mappa.width)
					/ (vars->sprite[i].distanza));
		i++;
	}
}

void	check_snacks_macchine(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->ns)
	{
		if (vars->sprite[i].obj == 1 && vars->sprite[i].distanza < 15.00)
		{
			vars->gnam = 1;
			vars->sprite[i].obj = 2;
			vars->snacks--;
		}
		if ((vars->snacks == 0) && vars->sprite[i].obj == 3)
			vars->sprite[i].obj = 4;
		if (vars->sprite[i].obj == 4 && vars->sprite[i].distanza < 15.00)
		{
			system("killall afplay");
			system("afplay bonus/scooby_dooby_doo.mp3");
			fermagioco(10);
		}
		i++;
	}
}

void	draw_snacks(t_vars *vars, int i, int x, int a)
{
	double			lineH;
	double			lineO;
	int				j;
	double			step_x;
	double			step_y;

	lineH = (16.00 * vars->mappa.height) / (vars->sprite[i].distanza
			* cos(DegToRad(vars->sprite[i].diffang)));
	lineO = (vars->mappa.height / 2) + lineH;
	lineH += lineO;
	j = lineO + 1;
	step_x = (vars->texture[7].wi / vars->sprite[i].pixdim) * (double)a;
	step_y = vars->texture[7].he / (lineH - lineO);
	if (j < 0)
		j = 0;
	while (j < lineH && j < vars->mappa.height)
	{
		if (leggipix(vars->texture[7],
				(int)step_x, (int)((j - lineO) * step_y)) >= 0)
			my_mlx_pixel_put(&vars->img, x, j, leggipix(vars->texture[7],
					(int)step_x, (int)((j - lineO) * step_y)));
		j++;
	}
}

int	init_snacks(t_vars *vars)
{
	vars->texture[7].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[7].path,
			&vars->texture[7].wi,
			&vars->texture[7].he);
	if (!vars->texture[7].img.img)
		return (0);
	vars->texture[7].img.addr = mlx_get_data_addr(vars->texture[7].img.img,
			&vars->texture[7].img.bits_per_pixel,
			&vars->texture[7].img.line_length,
			&vars->texture[7].img.endian);
	return (1);
}
