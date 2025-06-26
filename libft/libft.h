/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:45:30 by egjika            #+#    #+#             */
/*   Updated: 2025/06/27 01:36:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t s);

#endif
