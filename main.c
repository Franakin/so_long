/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 16:03:30 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/22 20:42:45 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>

static void	import_xpm(t_vars *vars)
{
	int	h;
	int	w;

	h = 32;
	w = 32;
	vars->dirt = mlx_xpm_file_to_image(vars->mlx, "xpm/dirt.xpm", &w, &h);
	vars->bedrock = mlx_xpm_file_to_image(vars->mlx, "xpm/bedrock.xpm", &w, &h);
	vars->steve = mlx_xpm_file_to_image(vars->mlx, "xpm/steve.xpm", &w, &h);
	vars->stone = mlx_xpm_file_to_image(vars->mlx, "xpm/stone.xpm", &w, &h);
	vars->diamond = mlx_xpm_file_to_image(vars->mlx, "xpm/diamond.xpm", &w, &h);
	vars->ladder = mlx_xpm_file_to_image(vars->mlx, "xpm/ladder.xpm", &w, &h);
	vars->creeper = mlx_xpm_file_to_image(vars->mlx, "xpm/creeper.xpm", &w, &h);
	vars->grass = mlx_xpm_file_to_image(vars->mlx, "xpm/grass.xpm", &w, &h);
}

int	main(int argc, char **map_name)
{
	t_vars	vars;
	int		fd;

	(void)argc;
	vars.move_count = 1;
	vars.mlx = mlx_init();
	fd = open(map_name[1], O_RDONLY);
	vars.map_data = convert_map(fd);
	close(fd);
	if (!vars.map_data)
		error("Map not loadable (main).", NULL);
	map_x(&vars);
	map_y(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.map.x * 32, (vars.map.y + 2) * 32, "MC2D");
	import_xpm(&vars);
	print_map(&vars);
	spawn_creeper(&vars);
	new_imap(&vars, &vars.path);
	vars.explorer = vars.map.x * vars.map.y / 20;
	vars.locked_i = 0;
	mlx_do_key_autorepeatoff(vars.mlx);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
