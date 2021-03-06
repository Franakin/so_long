/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_management.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:24:25 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/05 13:56:22 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include "ft_printf/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static void	map_validity(t_vars *vars, int *parts)
{
	int	xy[2];

	xy[1] = 0;
	while (vars->map_data[xy[1]])
	{
		xy[0] = 0;
		while (vars->map_data[xy[1]][xy[0]])
		{
			if (vars->map_data[xy[1]][xy[0]] != '1' && (xy[0] == 0 || xy[1] == 0
				|| xy[0] == vars->map.x - 1 || xy[1] == vars->map.y - 1))
				error("Invalid surrounding walls.", vars);
			if (vars->map_data[xy[1]][xy[0]] == 'P')
			{
				parts[0]++;
				if (parts[0] > 1)
					vars->map_data[xy[1]][xy[0]] = '0';
			}
			else if (vars->map_data[xy[1]][xy[0]] == 'C')
				parts[1] = 1;
			else if (vars->map_data[xy[1]][xy[0]] == 'E')
				parts[2] = 1;
			xy[0]++;
		}
		xy[1]++;
	}
}

void	new_imap(t_vars *vars, t_path *path)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	path->i_map = (int *)malloc(vars->map.x * vars->map.y * sizeof(int));
	if (!path->i_map)
		error(strerror(errno), vars);
	while (vars->map_data[i])
	{
		k = 0;
		while (vars->map_data[i][k])
		{
			if (vars->map_data[i][k] == '1')
				path->i_map[j] = 0;
			else
				path->i_map[j] = 1;
			j++;
			k++;
		}
	i++;
	}
}

char	**convert_map(int fd, t_vars *vars)
{
	int		bytes_read;
	char	*buffer;
	char	**map_data;
	char	*map_as_string;
	char	*temp;

	map_as_string = (char *)malloc(1);
	buffer = (char *)malloc(2);
	if (!buffer || !map_as_string)
		error(strerror(errno), vars);
	map_as_string[0] = '\0';
	buffer[1] = '\0';
	bytes_read = 1;
	while (bytes_read != 0)
	{
		temp = map_as_string;
		map_as_string = ft_strjoin(map_as_string, buffer);
		free(temp);
		bytes_read = read(fd, buffer, 1);
		buffer[bytes_read] = '\0';
	}
	free(buffer);
	map_data = ft_modded_split(map_as_string, '\n');
	free(map_as_string);
	return (map_data);
}

void	map_size(t_vars *vars)
{
	int		save;
	int		parts[3];

	parts[0] = 0;
	parts[1] = 0;
	parts[2] = 0;
	vars->map.y = 0;
	while (vars->map_data[vars->map.y])
	{
		vars->map.x = 0;
		while (vars->map_data[vars->map.y][vars->map.x])
			vars->map.x++;
		if (vars->map.y == 0)
			save = vars->map.x;
		else if (vars->map.x != save)
			error("Invalid map dimensions.", vars);
		vars->map.y++;
	}
	map_validity(vars, parts);
	if (!parts[0] || !parts[1] || !parts[2])
		error("Map config error.", vars);
}
