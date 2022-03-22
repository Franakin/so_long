/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:02:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 15:02:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	convert_d(int i);
int	convert_u(unsigned int i);
int	convert_x(unsigned long i, char c);

#endif
