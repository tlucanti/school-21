//
// Created by kostya on 11/24/20.
//

#ifndef SCHOOL21_GET_NEXT_LINE_H
#define SCHOOL21_GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef	struct		s_deque
{
	char			*str;
	size_t			size;
	struct s_deque	*next;
	struct s_deque	*prev;
}					t_deque;

typedef struct		s_buffer
{
	char			buffer[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
	size_t 			start;
	size_t			read_bytes;
}					t_buffer;

int		get_next_line(int fd, char **line);
size_t	ft_find_end(char *str, size_t size);
int		ft_lstpushfront(t_deque **list, const char *str, size_t size);
int		ft_lstclear(t_deque *lst, t_buffer **tbuff, int fd);
int		ft_listmerge(t_deque *list, char **line, int fd, t_buffer **tbuff);
void	*ft_memcpy_fwd(void *dst, void *src, size_t size);
void	*ft_calloc(size_t nmeb, size_t size);

#endif //SCHOOL21_GET_NEXT_LINE_H
