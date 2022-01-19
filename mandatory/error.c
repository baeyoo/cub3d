/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:31:23 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:31:25 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

int	fermagioco(int i)
{
	if (i == 0)
		printf("Error: there are more players!\n");
	if (i == 1)
		printf("Error: the map is open!\n");
	if (i == 2)
		printf("Error: characters not allowed in lines!\n");
	if (i == 3)
		printf("Error: number of arguments not valid in the map!\n");
	if (i == 4)
		printf("Error: file extension not valid!\n");
	if (i == 5)
		printf("Error: third arguement not valid! :c\n");
	if (i == 6)
		printf("Error: player doesn't exist >:c\n");
	if (i == 7)
		printf("Error: textures path are incorrect, repeated or missing! :S\n");
	if (i == 8)
		printf("Error: check again the resolution D:\n");
	if (i == 9)
		printf("Error: invalid colors for the background :-/\n");
	if (i == 10)
		printf("Error:  :-/\n");
	exit (0);
	return (0);
}

int	ft_finish(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
