/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:21:16 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:21:20 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strutture_bonus.h"

int	leggipix_1(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	bitmap_data(t_vars *vars, int fd)
{
	int				i;
	int				j;
	int				color;
	unsigned char	buffer[4];

	i = vars->mappa.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < vars->mappa.width)
		{
			color = leggipix_1(&vars->img, j, i);
			buffer[0] = (unsigned char)(color & 0xFF);
			buffer[1] = (unsigned char)((color >> 8) & 0xFF);
			buffer[2] = (unsigned char)((color >> 16) & 0xFF);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			j++;
		}
		i--;
	}
}

void	bitmap_image(t_vars *vars, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = vars->mappa.width;
	header[4] = (unsigned char)(n & 0xFF);
	header[5] = (unsigned char)((n >> 8) & 0xFF);
	header[6] = (unsigned char)((n >> 16) & 0xFF);
	header[7] = (unsigned char)((n >> 24) & 0xFF);
	n = vars->mappa.height;
	header[8] = (unsigned char)(n & 0xFF);
	header[9] = (unsigned char)((n >> 8) & 0xFF);
	header[10] = (unsigned char)((n >> 16) & 0xFF);
	header[11] = (unsigned char)((n >> 24) & 0xFF);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	bitmap_file(t_vars *vars, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = vars->mappa.height * vars->mappa.width * 4 + 54;
	header[2] = (unsigned char)(n & 0xFF);
	header[3] = (unsigned char)((n >> 8) & 0xFF);
	header[4] = (unsigned char)((n >> 16) & 0xFF);
	header[5] = (unsigned char)((n >> 24) & 0xFF);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	screenshot(t_vars *vars)
{
	int		fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bitmap_file(vars, fd);
	bitmap_image(vars, fd);
	bitmap_data(vars, fd);
	close(fd);
	exit(0);
}
