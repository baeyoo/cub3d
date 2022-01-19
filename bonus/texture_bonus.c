/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:33 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:27:38 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	init_texture_1(t_vars *vars)
{
	if (ft_check_xpm(vars->texture[0].path) == 0)
		fermagioco(6);
	if (open(vars->texture[0].path, O_RDONLY) == -1)
		fermagioco(7);
	vars->texture[0].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[0].path,
			&vars->texture[0].wi, &vars->texture[0].he);
	if (!vars->texture[0].img.img)
		return (0);
	vars->texture[0].img.addr = mlx_get_data_addr(vars->texture[0].img.img,
			&vars->texture[0].img.bits_per_pixel,
			&vars->texture[0].img.line_length,
			&vars->texture[0].img.endian);
	return (1);
}

int	init_texture_2(t_vars *vars)
{
	if (ft_check_xpm(vars->texture[1].path) == 0)
		fermagioco(6);
	if (open(vars->texture[1].path, O_RDONLY) == -1)
		fermagioco(7);
	vars->texture[1].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[1].path,
			&vars->texture[1].wi,
			&vars->texture[1].he);
	if (!vars->texture[1].img.img)
		return (0);
	vars->texture[1].img.addr = mlx_get_data_addr(vars->texture[1].img.img,
			&vars->texture[1].img.bits_per_pixel,
			&vars->texture[1].img.line_length,
			&vars->texture[1].img.endian);
	return (1);
}

int	init_texture_3(t_vars *vars)
{
	if (ft_check_xpm(vars->texture[2].path) == 0)
		fermagioco(6);
	if (open(vars->texture[2].path, O_RDONLY) == -1)
		fermagioco(7);
	vars->texture[2].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[2].path,
			&vars->texture[2].wi,
			&vars->texture[2].he);
	if (!vars->texture[2].img.img)
		return (0);
	vars->texture[2].img.addr = mlx_get_data_addr(vars->texture[2].img.img,
			&vars->texture[2].img.bits_per_pixel,
			&vars->texture[2].img.line_length,
			&vars->texture[2].img.endian);
	return (1);
}

int	init_texture_4(t_vars *vars)
{
	if (ft_check_xpm(vars->texture[3].path) == 0)
		fermagioco(6);
	if (open(vars->texture[3].path, O_RDONLY) == -1)
		fermagioco(7);
	vars->texture[3].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[3].path,
			&vars->texture[3].wi,
			&vars->texture[3].he);
	if (!vars->texture[3].img.img)
		return (0);
	vars->texture[3].img.addr = mlx_get_data_addr(vars->texture[3].img.img,
			&vars->texture[3].img.bits_per_pixel,
			&vars->texture[3].img.line_length,
			&vars->texture[3].img.endian);
	return (1);
}

int	init_sprite_1(t_vars *vars)
{
	if (ft_check_xpm(vars->texture[4].path) == 0)
		fermagioco(6);
	if (open(vars->texture[4].path, O_RDONLY) == -1)
		fermagioco(7);
	vars->texture[4].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[4].path,
			&vars->texture[4].wi,
			&vars->texture[4].he);
	if (!vars->texture[4].img.img)
		return (0);
	vars->texture[4].img.addr = mlx_get_data_addr(vars->texture[4].img.img,
			&vars->texture[4].img.bits_per_pixel,
			&vars->texture[4].img.line_length,
			&vars->texture[4].img.endian);
	return (1);
}
