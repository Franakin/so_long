/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameover.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:37:17 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/29 16:29:42 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <mlx.h>

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	game_over(t_vars *vars)
{
	if (vars->game_over == 1)
		put_image(vars, vars->defeat,
			vars->map.x * 16 - 131, vars->map.y * 16 - 17);
	else if (vars->game_over == 2)
		put_image(vars, vars->victory,
			vars->map.x * 16 - 100, vars->map.y * 16 - 17);
}

void	error(char *message, t_vars *vars)
{
	ft_printf("Error\n%s", message);
	close_window(vars);
}
