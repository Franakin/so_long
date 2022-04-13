/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:31:20 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/07 17:28:35 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include <mlx.h>

void	put_image(t_vars *vars, void *img, int x, int y)
{
	int	i;
	int	yes;

	i = 0;
	yes = 1;
	while (i < 10)
	{
		if (img == vars->numb[i] || img == vars->moves || img == vars->black)
		{
			yes = 0;
			break ;
		}
		i++;
	}
	if (yes && vars->map.x <= 12)
		x += (384 - (vars->map.x * 32)) / 2;
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

static void	check_char(t_vars *vars, char c, int x, int y)
{
	if (c == '1')
		put_image(vars, vars->bedrock, x, y);
	else if (c == '0')
		put_image(vars, vars->stone, x, y);
	else if (c == 'C')
	{
		vars->nb_diam++;
		put_image(vars, vars->diamond, x, y);
	}
	else if (c == 'E')
	{
		put_image(vars, vars->dirt, x, y);
		put_image(vars, vars->ladder, x, y);
	}
	else
		error("Invalid character in map.", vars);
}

void	print_map(t_vars *vars)
{
	int	i;
	int	k;

	i = 0;
	vars->nb_diam = 0;
	while (vars->map_data[i])
	{
		k = 0;
		while (vars->map_data[i][k])
		{
			if (vars->map_data[i][k] == 'P')
			{
				vars->player.x = k;
				vars->player.y = i;
				put_image(vars, vars->steve, k * 32, i * 32);
				vars->map_data[i][k] = '0';
			}
			else
				check_char(vars, vars->map_data[i][k], k * 32, i * 32);
			k++;
		}
		i++;
	}
	put_image(vars, vars->moves, 32, vars->map.y * 32 + 11);
	put_image(vars, vars->numb[0], 240, vars->map.y * 32 + 11);
}
