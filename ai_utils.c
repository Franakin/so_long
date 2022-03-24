/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ai_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/19 18:05:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/24 15:41:26 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static void	update_path(t_vars *vars, int r, int dir, int mem)
{
	if (r == 1 || r == 2)
	{
		vars->path.i_map[vars->creep.y
			* vars->map.x + vars->creep.x + dir] = mem;
		vars->creep.x += dir;
	}
	else if (r == 0 || r == 3)
	{
		vars->path.i_map[(vars->creep.y + dir)
			* vars->map.x + vars->creep.x] = mem;
		vars->creep.y += dir;
	}
}

void	crt_path_var(t_path *path, t_dum *obj1, t_dum *obj2)
{
	path->x_dir = 1;
	path->y_dir = 1;
	path->x_diff = obj2->x - obj1->x;
	path->y_diff = obj2->y - obj1->y;
	if (path->x_diff < 0)
	{
		path->x_dir = -1;
		path->x_diff *= -1;
	}
	if (path->y_diff < 0)
	{
		path->y_dir = -1;
		path->y_diff *= -1;
	}
}

int	*crt_mvbl_tiles(t_vars *vars, t_dum *obj, t_path *path)
{
	int	*tl;

	tl = (int *)malloc(4 * sizeof(int));
	if (!tl)
		error(strerror(errno), vars);
	tl[0] = path->i_map[(obj->y + path->y_dir) * vars->map.x + obj->x];
	tl[1] = path->i_map[obj->y * vars->map.x + obj->x + path->x_dir];
	tl[2] = path->i_map[obj->y * vars->map.x + obj->x - path->x_dir];
	tl[3] = path->i_map[(obj->y - path->y_dir) * vars->map.x + obj->x];
	return (tl);
}

void	select_rand_tile(t_vars *vars, int *tl, int is_mvbl, int mem)
{
	int	r;
	int	i;

	r = rand() % 4;
	i = 0;
	while (tl[r] != is_mvbl)
		r = rand() % 4;
	if (r == 0)
		update_path(vars, r, vars->path.y_dir, mem);
	else if (r == 1)
		update_path(vars, r, vars->path.x_dir, mem);
	else if (r == 2)
		update_path(vars, r, -vars->path.x_dir, mem);
	else if (r == 3)
		update_path(vars, r, -vars->path.y_dir, mem);
}

int	check_path(t_vars *vars, t_dum *dummy, t_path *path)
{
	t_path	dummy_path;
	int		*tl;

	while (!(dummy->y == vars->player.y && dummy->x == vars->player.x))
	{
		crt_path_var(&dummy_path, dummy, &vars->player);
		tl = crt_mvbl_tiles(vars, dummy, path);
		if (dummy_path.y_diff > dummy_path.x_diff && tl[0])
			dummy->y += dummy_path.y_dir;
		else if (dummy_path.y_diff <= dummy_path.x_diff && tl[1])
			dummy->x += dummy_path.x_dir;
		else
		{
			free(tl);
			return (0);
		}
		free(tl);
	}
	return (1);
}
