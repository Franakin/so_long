/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 16:03:30 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/29 16:43:44 by fpurdom       ########   odam.nl         */
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

	vars->dirt = mlx_xpm_file_to_image(vars->mlx, "xpm/dirt.xpm", &w, &h);
	vars->bedrock = mlx_xpm_file_to_image(vars->mlx, "xpm/bedrock.xpm", &w, &h);
	vars->steve = mlx_xpm_file_to_image(vars->mlx, "xpm/steve.xpm", &w, &h);
	vars->stone = mlx_xpm_file_to_image(vars->mlx, "xpm/stone.xpm", &w, &h);
	vars->diamond = mlx_xpm_file_to_image(vars->mlx, "xpm/diamond.xpm", &w, &h);
	vars->ladder = mlx_xpm_file_to_image(vars->mlx, "xpm/ladder.xpm", &w, &h);
	vars->creeper = mlx_xpm_file_to_image(vars->mlx, "xpm/creeper.xpm", &w, &h);
	vars->grass = mlx_xpm_file_to_image(vars->mlx, "xpm/grass.xpm", &w, &h);
	vars->expl[0] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f1.xpm", &w, &h);
	vars->expl[1] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f2.xpm", &w, &h);
	vars->expl[2] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f3.xpm", &w, &h);
	vars->expl[3] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f4.xpm", &w, &h);
	vars->expl[4] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f5.xpm", &w, &h);
	vars->expl[5] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f6.xpm", &w, &h);
	vars->expl[6] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f7.xpm", &w, &h);
	vars->expl[7] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f8.xpm", &w, &h);
	vars->expl[8] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f9.xpm", &w, &h);
	vars->expl[9] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f10.xpm", &w, &h);
	vars->expl[10] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f11.xpm", &w, &h);
	vars->expl[11] = mlx_xpm_file_to_image(vars->mlx, "xpm/e_f12.xpm", &w, &h);
}

static void	import_numbers(t_vars *vars)
{
	int	h;
	int	w;

	0[vars->numb] = mlx_xpm_file_to_image(vars->mlx, "xpm/0.xpm", &w, &h);
	vars->numb[1] = mlx_xpm_file_to_image(vars->mlx, "xpm/1.xpm", &w, &h);
	vars->numb[2] = mlx_xpm_file_to_image(vars->mlx, "xpm/2.xpm", &w, &h);
	vars->numb[3] = mlx_xpm_file_to_image(vars->mlx, "xpm/3.xpm", &w, &h);
	vars->numb[4] = mlx_xpm_file_to_image(vars->mlx, "xpm/4.xpm", &w, &h);
	vars->numb[5] = mlx_xpm_file_to_image(vars->mlx, "xpm/5.xpm", &w, &h);
	vars->numb[6] = mlx_xpm_file_to_image(vars->mlx, "xpm/6.xpm", &w, &h);
	vars->numb[7] = mlx_xpm_file_to_image(vars->mlx, "xpm/7.xpm", &w, &h);
	vars->numb[8] = mlx_xpm_file_to_image(vars->mlx, "xpm/8.xpm", &w, &h);
	vars->numb[9] = mlx_xpm_file_to_image(vars->mlx, "xpm/9.xpm", &w, &h);
	vars->moves = mlx_xpm_file_to_image(vars->mlx, "xpm/moves.xpm", &w, &h);
	vars->black = mlx_xpm_file_to_image(vars->mlx, "xpm/black.xpm", &w, &h);
	vars->defeat = mlx_xpm_file_to_image(vars->mlx, "xpm/gameover.xpm", &w, &h);
	vars->victory = mlx_xpm_file_to_image(vars->mlx, "xpm/youwin.xpm", &w, &h);
}

static void	init_vars(t_vars *vars, char *map_name)
{
	int	fd;
	int	win_len;

	vars->move_count = 0;
	vars->game_over = 0;
	vars->mlx = mlx_init();
	fd = open(map_name, O_RDONLY);
	vars->map_data = convert_map(fd, vars);
	if (!vars->map_data)
		error("Map not loadable (main).", NULL);
	close(fd);
	map_x(vars);
	map_y(vars);
	if (vars->map.x > 12)
		win_len = vars->map.x * 32;
	else
		win_len = 384;
	vars->win = mlx_new_window(vars->mlx, win_len,
			(vars->map.y + 2) * 32, "MC2D");
	vars->explorer = vars->map.x * vars->map.y / 20;
	vars->locked_i = 0;
}

int	main(int argc, char **map_name)
{
	t_vars	vars;

	(void)argc;
	init_vars(&vars, map_name[1]);
	import_xpm(&vars);
	import_numbers(&vars);
	print_map(&vars);
	spawn_creeper(&vars);
	new_imap(&vars, &vars.path);
	mlx_do_key_autorepeatoff(vars.mlx);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_loop_hook(vars.mlx, animate, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
