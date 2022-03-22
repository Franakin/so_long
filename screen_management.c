/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:31:20 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/22 17:54:31 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include <mlx.h>

void	put_image(t_vars *vars, void *img, int x, int y)
{
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
		error("Invalid map (print_map).", vars);
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
}

void	update(t_vars *vars, int *position, int direction)
{
	put_image(vars, vars->dirt, vars->player.x * 32, vars->player.y * 32);
	if (vars->map_data[vars->player.y][vars->player.x] == 'C')
	{
		vars->map_data[vars->player.y][vars->player.x] = '0';
		vars->nb_diam--;
	}
	else if (vars->map_data[vars->player.y][vars->player.x] == 'E')
		put_image(vars, vars->ladder, vars->player.x * 32, vars->player.y * 32);
	vars->move_count++;
	*position += direction;
	put_image(vars, vars->steve, vars->player.x * 32, vars->player.y * 32);
	put_image(vars, vars->dirt, vars->creep.x * 32, vars->creep.y * 32);
	if (vars->map_data[vars->creep.y][vars->creep.x] == 'C')
		put_image(vars, vars->diamond, vars->creep.x * 32, vars->creep.y * 32);
	else if (vars->map_data[vars->creep.y][vars->creep.x] == 'E')
		put_image(vars, vars->ladder, vars->creep.x * 32, vars->creep.y * 32);
	init_ai(vars);
	put_image(vars, vars->creeper, vars->creep.x * 32, vars->creep.y * 32);
}
