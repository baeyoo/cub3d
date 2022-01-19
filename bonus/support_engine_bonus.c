/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_engine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:19 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:27:21 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	support_diag(t_vars *vars)
{
	return (((int)(vars->stato.posy / 64)) * vars->mappa.mapX
		+ (int)(vars->stato.posx / 64));
}

int	check_diagonalw(t_vars *vars, char c, int mp)
{
	if (mp == support_diag(vars))
		return (0);
	if (ft_strcomp(c, "12 \n"))
		return (1);
	if (ft_strcomp(c, "034"))
	{
		if ((vars->stato.angle >= 0.00 && vars->stato.angle < 90.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 90.00 && vars->stato.angle < 180.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 180.00 && vars->stato.angle < 270.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 270.00 && vars->stato.angle < 360.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
	}
	return (0);
}

int	check_diagonals(t_vars *vars, char c, int mp)
{
	if (mp == support_diag(vars))
		return (0);
	if (ft_strcomp(c, "12 \n"))
		return (1);
	if (ft_strcomp(c, "034"))
	{
		if ((vars->stato.angle > 0.00 && vars->stato.angle < 90.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 90.00 && vars->stato.angle < 180.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 180.00 && vars->stato.angle < 270.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 270.00 && vars->stato.angle < 360.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
	}
	return (0);
}

int	check_diagonala(t_vars *vars, char c, int mp)
{
	if (mp == support_diag(vars))
		return (0);
	if (ft_strcomp(c, "12 \n"))
		return (1);
	if (ft_strcomp(c, "034"))
	{
		if ((vars->stato.angle > 0.00 && vars->stato.angle < 90.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 90.00 && vars->stato.angle < 180.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 180.00 && vars->stato.angle < 270.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 270.00 && vars->stato.angle < 360.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
	}
	return (0);
}

int	check_diagonald(t_vars *vars, char c, int mp)
{
	if (mp == support_diag(vars))
		return (0);
	if (ft_strcomp(c, "12 \n"))
		return (1);
	if (ft_strcomp(c, "034"))
	{
		if ((vars->stato.angle > 0.00 && vars->stato.angle < 90.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 90.00 && vars->stato.angle < 180.00)
			&& ft_strcomp(vars->mappa.mappa[mp - 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 180.00 && vars->stato.angle < 270.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp + vars->mappa.mapX], "12"))
			return (1);
		if ((vars->stato.angle > 270.00 && vars->stato.angle < 360.00)
			&& ft_strcomp(vars->mappa.mappa[mp + 1], "12")
			&& ft_strcomp(vars->mappa.mappa[mp - vars->mappa.mapX], "12"))
			return (1);
	}
	return (0);
}
