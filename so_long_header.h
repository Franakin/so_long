/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_header.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:25:03 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/29 16:40:07 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H

typedef struct s_dum
{
	int				x;
	int				y;
}				t_dum;

typedef struct s_path
{
	int	x_diff;
	int	y_diff;
	int	x_dir;
	int	y_dir;
	int	*i_map;
}				t_path;

typedef struct s_vars
{
	char			**map_data;
	void			*mlx;
	void			*win;
	void			*grass;
	void			*dirt;
	void			*diamond;
	void			*stone;
	void			*bedrock;
	void			*steve;
	void			*ladder;
	void			*creeper;
	void			*moves;
	void			*black;
	void			*victory;
	void			*defeat;
	int				nb_diam;
	int				explorer;
	int				locked_i;
	int				move_count;
	int				game_over;
	t_dum			player;
	t_dum			creep;
	t_dum			map;
	t_dum			locked_dum;
	t_path			locked_path;
	t_path			path;
	unsigned long	*expl[12];
	unsigned long	*numb[10];
}				t_vars;

//map management
void	new_imap(t_vars *vars, t_path *path);
char	**convert_map(int fd, t_vars *vars);
void	map_y(t_vars *vars);
void	map_x(t_vars *vars);
//event management
int		animate(t_vars *vars);
int		collision(t_dum obj1, t_dum obj2);
int		key_press(int keycode, t_vars *vars);
//screen management
void	put_image(t_vars *vars, void *img, int x, int y);
void	print_map(t_vars *vars);
//pathfinding stuff
void	init_ai(t_vars *vars);
void	spawn_creeper(t_vars *vars);
void	crt_path_var(t_path *path, t_dum *obj1, t_dum *obj2);
int		*crt_mvbl_tiles(t_vars *vars, t_dum *obj, t_path *path);
void	select_rand_tile(t_vars *vars, int *tl, int is_mvbl, int mem);
int		check_path(t_vars *vars, t_dum *dummy, t_path *path);
//updates
void	player_update(t_vars *vars, int *position, int direction);
void	creeper_update(t_vars *vars);
//game ending
int		close_window(t_vars *vars);
void	game_over(t_vars *vars);
void	error(char *message, t_vars *vars);

#endif
