/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vediamo_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:28:14 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:28:16 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

int	init_texture(t_vars *vars)
{
	init_texture_1(vars);
	init_texture_2(vars);
	init_texture_3(vars);
	init_texture_4(vars);
	init_sprite_1(vars);
	init_snacks(vars);
	init_macchine(vars);
	init_face(vars);
	init_face_2(vars);
	init_tar(vars);
	init_volt(vars);
	init_headless(vars);
	init_knight(vars);
	init_ghost(vars);
	init_clown(vars);
	init_sub(vars);
	return (1);
}

int	render(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx,
			vars->mappa.width, vars->mappa.height);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	check_sound(vars);
	setting(vars);
	check_distanza(vars);
	main_sprite(vars);
	draw_face(vars);
	if (vars->screen == 1)
	{
		screenshot(vars);
		exit (0);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	check_snacks_macchine(vars);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->face = 0;
	return (0);
}

int	mlx_and_move(t_vars vars)
{
	vars.mappa.distanze = malloc(vars.mappa.width * sizeof(double));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
			vars.mappa.width, vars.mappa.height, "Scooby Doo");
	if (!init_texture(&vars))
		return (0);
	if (vars.screen == 1)
		render(&vars);
	else
		system("afplay -v 0.50 bonus/corriscooby.mp3 &>/dev/null &");
	vars.face = 0;
	vars.movement.left = 0;
	vars.movement.right = 0;
	vars.movement.up = 0;
	vars.movement.down = 0;
	vars.gnam = 0;
	mlx_hook(vars.win, 2, 0L, onPress, &vars);
	mlx_hook(vars.win, 3, 0L, onRelease, &vars);
	mlx_hook(vars.win, 17, 0L, ft_finish, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	render(&vars);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	vars.screen = 0;
	fd = open((argv[1]), O_RDONLY);
	if (argc > 3 || argc < 2)
		fermagioco(3);
	if (ft_check_file(argv[1]) == 0)
		fermagioco(4);
	if (argc == 3 && !(ft_strcmp(argv[2], "--save")))
		fermagioco(5);
	else if (argc == 3)
		vars.screen = 1;
	init_backcolor(&vars);
	ft_parsing(&vars, fd);
	ft_numcolor(&vars);
	check_res(&vars);
	findplayer(&vars);
	readtwo(&vars);
	main_texture(&vars);
	assing_text(&vars);
	mlx_and_move(vars);
}
