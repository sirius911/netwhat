/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:46:18 by clorin            #+#    #+#             */
/*   Updated: 2020/10/04 15:49:15 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			zero;
	int			width;
	int			left;
	int			precision;

}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_set_flags(t_flags *flags, const char *format, va_list param);
int				ft_print_arg(const char *format, t_flags *flags, va_list param);
int				ft_len_nbr_base(long nbr, char *base);
int				ft_print_nbr_base(long nbr, char *base);
int				ft_putc(t_flags *flags, va_list param, char c);
int				ft_puts(t_flags *flags, va_list param);
int				ft_putdi(t_flags *flags, va_list param);
int				ft_putu(t_flags *flags, va_list param);
int				ft_putx(t_flags *flags, va_list param, char *base);
int				ft_putp(t_flags *flags, va_list param);

#endif
