/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:40:26 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/24 19:17:51 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include <mlx.h>

static void	explode(t_vars *vars, int frame, int x, int y)
{
	int	i;
	int	k;

	k = y - 1;
	if (frame <= 12)
	{
		while (k <= y + 1)
		{
			i = x - 1;
			while (i <= x + 1)
			{
				put_image(vars, vars->dirt, i * 32, k * 32);
				put_image(vars, vars->expl[frame - 1], i * 32, k * 32);
				i++;
			}
			k++;
		}
	}
}

int	animate(t_vars *vars)
{
	static int	i = 0;
	static int	frame = 0;

	if (frame == 15)
		game_over(vars);
	else if (vars->game_over == 1 && (i == 1000 || frame == 0))
	{
		explode(vars, frame++, vars->creep.x, vars->creep.y);
		i = 0;
	}
	else if (i == 2500 && vars->move_count > 0 && !vars->game_over)
	{
		creeper_update(vars);
		i = 0;
	}
	if (i < 2500)
		i++;
	return (1);
}

int	collision(t_dum obj1, t_dum obj2)
{
	if ((obj1.x == obj2.x + 1 && obj1.y == obj2.y)
		|| (obj1.x == obj2.x - 1 && obj1.y == obj2.y)
		|| (obj1.x == obj2.x && obj1.y == obj2.y + 1)
		|| (obj1.x == obj2.x && obj1.y == obj2.y - 1)
		|| (obj1.x == obj2.x && obj1.y == obj2.y))
		return (1);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_window(vars);
	if (keycode == 13 && !vars->game_over
		&& vars->map_data[vars->player.y - 1][vars->player.x] != '1')
		player_update(vars, &vars->player.y, -1);
	if (keycode == 0 && !vars->game_over
		&& vars->map_data[vars->player.y][vars->player.x - 1] != '1')
		player_update(vars, &vars->player.x, -1);
	if (keycode == 1 && !vars->game_over
		&& vars->map_data[vars->player.y + 1][vars->player.x] != '1')
		player_update(vars, &vars->player.y, 1);
	if (keycode == 2 && !vars->game_over
		&& vars->map_data[vars->player.y][vars->player.x + 1] != '1')
		player_update(vars, &vars->player.x, 1);
	if (vars->map_data[vars->player.y][vars->player.x] == 'E'
		&& vars->nb_diam == 0)
	{
		vars->game_over = 2;
		game_over(vars);
	}
	if (collision(vars->creep, vars->player))
		vars->game_over = 1;
	return (0);
}
