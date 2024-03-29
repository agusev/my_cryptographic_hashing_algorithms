/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 23:56:32 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 23:56:38 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000

typedef struct	s_fpt
{
	int			fd;
	char		*buf;
}				t_fpt;

int				get_next_line(const int fd, char **line);

#endif
