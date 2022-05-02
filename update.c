/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 18:34:38 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/02 18:23:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include "ft_printf/libft/libft.h"
#include <stdlib.h>

static void	update_movecount(t_vars *vars)
{
	char	*moves_str;
	int		i;

	i = 0;
	vars->move_count++;
	moves_str = ft_itoa(vars->move_count);
	put_image(vars, vars->black, 240, vars->map.y * 32 + 11);
	while (moves_str[i])
	{
		put_image(vars, vars->numb[moves_str[i] - '0'],
			240 + 34 * i, vars->map.y * 32 + 11);
		i++;
	}
	free(moves_str);
}

void	player_update(t_vars *vars, int *position, int direction)
{
	put_image(vars, vars->dirt, vars->player.x * 32, vars->player.y * 32);
	if (vars->map_data[vars->player.y][vars->player.x] == 'C')
	{
		vars->map_data[vars->player.y][vars->player.x] = '0';
		vars->nb_diam--;
	}
	else if (vars->map_data[vars->player.y][vars->player.x] == 'E')
		put_image(vars, vars->ladder, vars->player.x * 32, vars->player.y * 32);
	*position += direction;
	put_image(vars, vars->steve, vars->player.x * 32, vars->player.y * 32);
	update_movecount(vars);
}

void	creeper_update(t_vars *vars)
{
	put_image(vars, vars->dirt, vars->creep.x * 32, vars->creep.y * 32);
	if (vars->map_data[vars->creep.y][vars->creep.x] == 'C')
		put_image(vars, vars->diamond, vars->creep.x * 32, vars->creep.y * 32);
	else if (vars->map_data[vars->creep.y][vars->creep.x] == 'E')
		put_image(vars, vars->ladder, vars->creep.x * 32, vars->creep.y * 32);
	init_ai(vars);
	put_image(vars, vars->creeper, vars->creep.x * 32, vars->creep.y * 32);
}
