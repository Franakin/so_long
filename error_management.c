/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:37:17 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/22 17:56:39 by fpurdom       ########   odam.nl         */
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

void	error(char *message, t_vars *vars)
{
	ft_printf("Error\n%s", message);
	close_window(vars);
}
