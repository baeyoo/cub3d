/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monster_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:23:30 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:23:32 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	init_tar(t_vars *vars)
{
	vars->texture[9].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[9].path,
			&vars->texture[9].wi,
			&vars->texture[9].he);
	if (!vars->texture[9].img.img)
		return (0);
	vars->texture[9].img.addr = mlx_get_data_addr(vars->texture[9].img.img,
			&vars->texture[9].img.bits_per_pixel,
			&vars->texture[9].img.line_length,
			&vars->texture[9].img.endian);
	return (1);
}

int	init_volt(t_vars *vars)
{
	vars->texture[10].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[10].path,
			&vars->texture[10].wi,
			&vars->texture[10].he);
	if (!vars->texture[10].img.img)
		return (0);
	vars->texture[10].img.addr = mlx_get_data_addr(vars->texture[10].img.img,
			&vars->texture[10].img.bits_per_pixel,
			&vars->texture[10].img.line_length,
			&vars->texture[10].img.endian);
	return (1);
}

int	init_headless(t_vars *vars)
{
	vars->texture[11].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[11].path,
			&vars->texture[11].wi,
			&vars->texture[11].he);
	if (!vars->texture[11].img.img)
		return (0);
	vars->texture[11].img.addr = mlx_get_data_addr(vars->texture[11].img.img,
			&vars->texture[11].img.bits_per_pixel,
			&vars->texture[11].img.line_length,
			&vars->texture[11].img.endian);
	return (1);
}

int	init_knight(t_vars *vars)
{
	vars->texture[12].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[12].path,
			&vars->texture[12].wi,
			&vars->texture[12].he);
	if (!vars->texture[12].img.img)
		return (0);
	vars->texture[12].img.addr = mlx_get_data_addr(vars->texture[12].img.img,
			&vars->texture[12].img.bits_per_pixel,
			&vars->texture[12].img.line_length,
			&vars->texture[12].img.endian);
	return (1);
}

int	init_ghost(t_vars *vars)
{
	vars->texture[13].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[13].path,
			&vars->texture[13].wi,
			&vars->texture[13].he);
	if (!vars->texture[13].img.img)
		return (0);
	vars->texture[13].img.addr = mlx_get_data_addr(vars->texture[13].img.img,
			&vars->texture[13].img.bits_per_pixel,
			&vars->texture[13].img.line_length,
			&vars->texture[13].img.endian);
	return (1);
}
