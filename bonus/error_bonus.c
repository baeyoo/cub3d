/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:22:11 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:22:48 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	fermagioco(int i)
{
	if (i == 0)
		printf("Error:\nthere are more players!\n");
	if (i == 1)
		printf("Error:\nthe map is open!\n");
	if (i == 2)
		printf("Error:\ncharacters not allowed in lines!\n");
	if (i == 3)
		printf("Error:\nnumber of arguments not valid in the map!\n");
	if (i == 4)
		printf("Error:\nfile extension not valid!\n");
	if (i == 5)
		printf("Error:\nthird arguement not valid! :c\n");
	if (i == 6)
		printf("Error:\nplayer doesn't exist >:c\n");
	if (i == 7)
		printf("Error:\ntextures path are incorrect, repeated or missing! :S\n");
	if (i == 8)
		printf("Error:\ncheck again the resolution D:\n");
	if (i == 9)
		printf("Error:\ninvalid colors for the background :-/\n");
	if (i == 10)
		printf("Brav*!\nHai vinto!!!! :D");
	exit (0);
}

int	ft_finish(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	system("killall afplay");
	exit(0);
	return (0);
}
