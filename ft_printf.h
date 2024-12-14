/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:46:01 by salmou            #+#    #+#             */
/*   Updated: 2024/12/13 03:13:52 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <limits.h>
///////// ATTENTION C'EST PAS TA LIBFT //////////
char	*ft_utoa(ssize_t num);
char	*num_to_hex(ssize_t num, int up, char format);
int		ft_isupercase(char c);
char	*char_to_str(int c);
int		ft_printf(const char *s, ...);
#endif
