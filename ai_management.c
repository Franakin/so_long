/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ai_management.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 18:27:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/24 20:23:05 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

static void	move_randomly(t_vars *vars, t_path *path)
{
	int	*tl;
	int	i;

	i = 1;
	tl = crt_mvbl_tiles(vars, &vars->creep, path);
	while (i <= vars->explorer)
	{
		if (tl[0] == i || tl[1] == i || tl[2] == i || tl[3] == i)
		{
			select_rand_tile(vars, tl, i, i + 1);
			break ;
		}
		i++;
	}
	if (i == vars->explorer && tl[0] && tl[1] && tl[2] && tl[3])
		select_rand_tile(vars, tl, i, i);
	free(tl);
}

static void	move_towards_player(t_vars *vars, t_path *path)
{
	if (path->y_diff > path->x_diff)
		vars->creep.y += path->y_dir;
	else
		vars->creep.x += path->x_dir;
	vars->locked_dum.x = vars->player.x;
	vars->locked_dum.y = vars->player.y;
	if (path->y_diff + path->x_diff > 10)
		vars->locked_i = 10;
	else
		vars->locked_i = path->y_diff + path->x_diff - 1;
}

void	init_ai(t_vars *vars)
{
	t_dum	dummy;

	dummy.x = vars->creep.x;
	dummy.y = vars->creep.y;
	crt_path_var(&vars->path, &vars->creep, &vars->player);
	if (check_path(vars, &dummy, &vars->path))
		move_towards_player(vars, &vars->path);
	else if (vars->locked_i > 0)
	{
		crt_path_var(&vars->locked_path, &vars->creep, &vars->locked_dum);
		if (vars->locked_path.y_diff > vars->locked_path.x_diff)
			vars->creep.y += vars->locked_path.y_dir;
		else
			vars->creep.x += vars->locked_path.x_dir;
		vars->locked_i--;
	}
	else
		move_randomly(vars, &vars->path);
	if (collision(vars->creep, vars->player))
		vars->game_over = 1;
}

void	spawn_creeper(t_vars *vars)
{
	int	height;
	int	lenght;

	vars->creep.x = rand() % vars->map.x;
	vars->creep.y = rand() % vars->map.y;
	height = vars->creep.y - vars->player.y;
	lenght = vars->creep.x - vars->player.x;
	while (vars->map_data[vars->creep.y][vars->creep.x] == '1'
		|| sqrt(height * height + lenght * lenght) < 3)
	{
		vars->creep.x = rand() % vars->map.x;
		vars->creep.y = rand() % vars->map.y;
		height = vars->creep.y - vars->player.y;
		lenght = vars->creep.x - vars->player.x;
	}
	put_image(vars, vars->creeper, vars->creep.x * 32, vars->creep.y * 32);
}
