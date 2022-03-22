/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:40:26 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/22 17:55:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	end_game(t_vars *vars)
{
	close_window(vars);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_window(vars);
	if (keycode == 13
		&& vars->map_data[vars->player.y - 1][vars->player.x] != '1')
		update(vars, &vars->player.y, -1);
	if (keycode == 0
		&& vars->map_data[vars->player.y][vars->player.x - 1] != '1')
		update(vars, &vars->player.x, -1);
	if (keycode == 1
		&& vars->map_data[vars->player.y + 1][vars->player.x] != '1')
		update(vars, &vars->player.y, 1);
	if (keycode == 2
		&& vars->map_data[vars->player.y][vars->player.x + 1] != '1')
		update(vars, &vars->player.x, 1);
	if (vars->map_data[vars->player.y][vars->player.x] == 'E'
		&& vars->nb_diam == 0)
		end_game(vars);
	if (vars->player.x == vars->creep.x && vars->player.y == vars->creep.y)
		end_game(vars);
	return (0);
}
