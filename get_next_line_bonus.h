/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:31:33 by zhassna           #+#    #+#             */
/*   Updated: 2025/01/07 21:44:23 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_get_next(char *buf);
char	*ft_get_line(char *buf);
char	*ft_read_file(int fd, char *reminder);

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s1);
char	*ft_search_nl(char *str, char c);
void	ft_bzero(void *s, size_t n);
char	*ft_calloc(size_t count, size_t size);
#endif
