/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:08:04 by dnicki            #+#    #+#             */
/*   Updated: 2021/03/13 17:24:35 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define MAX_FD 1024
# define BUFFER_SIZE 1

char	*ft_strjoin_all_clear(char *s1, char *s2);
int		get_next_line(int fd, char **line);

#endif
