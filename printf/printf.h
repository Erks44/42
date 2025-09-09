/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:55:40 by egjika            #+#    #+#             */
/*   Updated: 2025/09/09 20:55:40 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int a);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_unsigned(unsigned int a);
int	ft_puthex(unsigned long a);
int	ft_puthexa(unsigned long a);
int	ft_putptr(void *ptr);

#endif
