/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:02:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/19 11:20:16 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define DECIMAL "0123456789"
# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_ptr(unsigned long ptr);
int	print_nbr(int nb);
int	print_unbr(unsigned int nb);
int	print_nbr_base(unsigned long nb, char *base);

#endif
