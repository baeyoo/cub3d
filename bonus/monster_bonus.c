/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:25:42 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:25:45 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	init_clown(t_vars *vars)
{
	vars->texture[14].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[14].path,
			&vars->texture[14].wi,
			&vars->texture[14].he);
	if (!vars->texture[14].img.img)
		return (0);
	vars->texture[14].img.addr = mlx_get_data_addr(vars->texture[14].img.img,
			&vars->texture[14].img.bits_per_pixel,
			&vars->texture[14].img.line_length,
			&vars->texture[14].img.endian);
	return (1);
}

int	init_sub(t_vars *vars)
{
	vars->texture[15].img.img = mlx_xpm_file_to_image(vars->mlx,
			vars->texture[15].path,
			&vars->texture[15].wi,
			&vars->texture[15].he);
	if (!vars->texture[15].img.img)
		return (0);
	vars->texture[15].img.addr = mlx_get_data_addr(vars->texture[15].img.img,
			&vars->texture[15].img.bits_per_pixel,
			&vars->texture[15].img.line_length,
			&vars->texture[15].img.endian);
	return (1);
}

void	assing_text_2(t_vars *vars, int i, int j)
{
	if (j % 8 == 5)
		vars->sprite[i].text = 13;
	else if (j % 8 == 6)
		vars->sprite[i].text = 14;
	else if (j % 8 == 7)
		vars->sprite[i].text = 15;
}

void	assing_text(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < vars->ns)
	{
		if (vars->sprite[i].obj == 0)
		{
			if (j % 8 == 0)
				vars->sprite[i].text = 4;
			else if (j % 8 == 1)
				vars->sprite[i].text = 9;
			else if (j % 8 == 2)
				vars->sprite[i].text = 10;
			else if (j % 8 == 3)
				vars->sprite[i].text = 11;
			else if (j % 8 == 4)
				vars->sprite[i].text = 12;
			else
				assing_text_2(vars, i, j);
			j++;
		}
		i++;
	}
}
