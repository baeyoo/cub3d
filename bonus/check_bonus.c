/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:21:30 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:21:32 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

void	check_res(t_vars *vars)
{
	int	W;
	int	H;

	mlx_get_screen_size(vars->mlx, &W, &H);
	if ((int)vars->mappa.width > W)
		vars->mappa.width = (double)(W - 1);
	if ((int)vars->mappa.height > H)
		vars->mappa.height = (double)(H - 1);
	if (vars->mappa.height <= 0 || vars->mappa.width <= 0)
		fermagioco(8);
}

int	ft_check_xpm(char *file)
{
	while (*file)
	{
		if (*file == '.' && *(file + 1) == 'x' && \
		*(file + 2) == 'p' && *(file + 3) == 'm' && \
		*(file + 4) == '\0')
			return (1);
		file++;
	}
	return (0);
}

int	ft_check_file(char *file)
{
	while (*file)
	{
		if (*file == '.' && *(file + 1) == 'c' && \
		*(file + 2) == 'u' && *(file + 3) == 'b' && \
		*(file + 4) == '\0')
			return (1);
		file++;
	}
	return (0);
}

void	check_input(t_vars *vars)
{
	if (vars->nsew.nord != 1 || vars->nsew.sud != 1
		|| vars->nsew.est != 1 || vars->nsew.ovest != 1
		|| vars->nsew.sprite != 1)
		fermagioco(7);
}
