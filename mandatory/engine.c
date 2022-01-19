/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:31:15 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:31:16 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture.h"

int	onPress(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == A_KEY)
		vars->movement.left = TRUE;
	if (keycode == S_KEY)
		vars->movement.down = TRUE;
	if (keycode == D_KEY)
		vars->movement.right = TRUE;
	if (keycode == W_KEY)
		vars->movement.up = TRUE;
	if (keycode == RIGHT_KEY)
		vars->movement.cam_right = TRUE;
	if (keycode == LEFT_KEY)
		vars->movement.cam_left = TRUE;
	return (0);
}

int	onRelease(int keycode, t_vars *vars)
{
	if (keycode == A_KEY)
		vars->movement.left = FALSE;
	if (keycode == S_KEY)
		vars->movement.down = FALSE;
	if (keycode == D_KEY)
		vars->movement.right = FALSE;
	if (keycode == W_KEY)
		vars->movement.up = FALSE;
	if (keycode == RIGHT_KEY)
		vars->movement.cam_right = FALSE;
	if (keycode == LEFT_KEY)
		vars->movement.cam_left = FALSE;
	return (0);
}

void	up_down(t_vars *vars, int mex, int mey, int mp)
{
	if (vars->movement.up == TRUE)
	{
		mex = (int)(vars->stato.posx + vars->stato.dex * 4) >> 6;
		mey = (int)(vars->stato.posy + vars->stato.dey * 4) >> 6;
		mp = mey * vars->mappa.mapX + mex;
		if (!(check_diagonalw(vars, vars->mappa.mappa[mp], mp)))
		{
			vars->stato.posx += vars->stato.dex * 4;
			vars->stato.posy += vars->stato.dey * 4;
		}
	}
	if (vars->movement.down == TRUE)
	{
		mex = (int)(vars->stato.posx - vars->stato.dex * 4) >> 6;
		mey = (int)(vars->stato.posy - vars->stato.dey * 4) >> 6;
		mp = mey * vars->mappa.mapX + mex;
		if (!(check_diagonals(vars, vars->mappa.mappa[mp], mp)))
		{
			vars->stato.posx -= vars->stato.dex * 4;
			vars->stato.posy -= vars->stato.dey * 4;
		}
	}
}

void	left_right(t_vars *vars, int mex, int mey, int mp)
{
	if (vars->movement.left == TRUE)
	{
		mex = (int)(vars->stato.posx + vars->stato.dey * 4) >> 6;
		mey = (int)(vars->stato.posy - vars->stato.dex * 4) >> 6;
		mp = mey * vars->mappa.mapX + mex;
		if (!(check_diagonala(vars, vars->mappa.mappa[mp], mp)))
		{
			vars->stato.posx += vars->stato.dey * 4;
			vars->stato.posy -= vars->stato.dex * 4;
		}
	}
	if (vars->movement.right == TRUE)
	{
		mex = (int)(vars->stato.posx - vars->stato.dey * 4) >> 6;
		mey = (int)(vars->stato.posy + vars->stato.dex * 4) >> 6;
		mp = mey * vars->mappa.mapX + mex;
		if (!(check_diagonald(vars, vars->mappa.mappa[mp], mp)))
		{
			vars->stato.posx -= vars->stato.dey * 4;
			vars->stato.posy += vars->stato.dex * 4;
		}
	}
	up_down(vars, mex, mey, mp);
}

int	setting(t_vars *vars)
{
	int	mex;
	int	mey;
	int	mp;

	mex = 0;
	mey = 0;
	mp = 0;
	if (vars->movement.cam_left == TRUE)
	{
		vars->stato.angle += 5;
		vars->stato.angle = FixAng(vars->stato.angle);
		vars->stato.dex = cos(DegToRad(vars->stato.angle));
		vars->stato.dey = -sin(DegToRad(vars->stato.angle));
	}
	if (vars->movement.cam_right == TRUE)
	{
		vars->stato.angle -= 5;
		vars->stato.angle = FixAng(vars->stato.angle);
		vars->stato.dex = cos(DegToRad(vars->stato.angle));
		vars->stato.dey = -sin(DegToRad(vars->stato.angle));
	}
	left_right(vars, mex, mey, mp);
	return (0);
}
