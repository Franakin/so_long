/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_management.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:24:25 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/19 18:14:12 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

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

char	**convert_map(int fd)
{
	int		bytes_read;
	char	*buffer;
	char	**map_data;
	char	*map_as_string;
	char	*temp;

	map_as_string = (char *)malloc(1);
	buffer = (char *)malloc(2);
	if (!buffer || !map_as_string)
		return (NULL);
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
	map_data = ft_split(map_as_string, '\n');
	free(map_as_string);
	return (map_data);
}

void	map_y(t_vars *vars)
{
	while (vars->map_data[vars->map.y])
		vars->map.y++;
}

void	map_x(t_vars *vars)
{
	int	save;

	vars->map.y = 0;
	save = -1;
	while (vars->map_data[vars->map.y])
	{
		vars->map.x = 0;
		while (vars->map_data[vars->map.y][vars->map.x])
			vars->map.x++;
		if (vars->map.y == 0)
			save = vars->map.x;
		else if (vars->map.x != save)
			error("Invalid map (map.x).", vars);
		vars->map.y++;
	}
}
