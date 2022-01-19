/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:23:08 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:23:10 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	init_face(t_vars *vars)
{
	vars->texture[5].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[5].path,
			&vars->texture[5].wi,
			&vars->texture[5].he);
	if (!vars->texture[5].img.img)
		return (0);
	vars->texture[5].img.addr = mlx_get_data_addr(vars->texture[5].img.img,
			&vars->texture[5].img.bits_per_pixel,
			&vars->texture[5].img.line_length,
			&vars->texture[5].img.endian);
	return (1);
}

int	init_face_2(t_vars *vars)
{
	vars->texture[6].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[6].path,
			&vars->texture[6].wi,
			&vars->texture[6].he);
	if (!vars->texture[5].img.img)
		return (0);
	vars->texture[6].img.addr = mlx_get_data_addr(vars->texture[6].img.img,
			&vars->texture[6].img.bits_per_pixel,
			&vars->texture[6].img.line_length,
			&vars->texture[6].img.endian);
	return (1);
}

void	support_face(t_vars *vars, int i)
{
	vars->faces.sizex = (vars->mappa.width / 1080) * 200;
	vars->faces.sizey = (vars->mappa.height / 720) * 200;
	vars->faces.startx = (vars->mappa.width / 2) - (vars->faces.sizex / 2);
	vars->faces.starty = vars->mappa.height - vars->faces.sizey - 1;
	vars->faces.stepx = vars->texture[i].wi / vars->faces.sizex;
	vars->faces.stepy = vars->texture[i].he / vars->faces.sizey;
}

void	draw_face(t_vars *vars)
{
	int		i;
	int		pix;
	double	x;
	double	y;

	i = 5;
	if (vars->face == 1)
		i = 6;
	support_face(vars, i);
	x = 0;
	while (x < vars->faces.sizex)
	{
		y = 0;
		while (y < vars->faces.sizey)
		{
			pix = leggipix(vars->texture[i], (int)(x * vars->faces.stepx),
					(int)(y * vars->faces.stepy));
			if (pix >= 0)
				my_mlx_pixel_put(&vars->img, vars->faces.startx
					+ (int)x, vars->faces.starty + (int)y, pix);
			y++;
		}
		x++;
	}
}
