/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:55:29 by kostya            #+#    #+#             */
/*   Updated: 2020/12/09 15:10:46 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_buffer		*buff[1024] = {0};
	size_t				end_ind;
	t_deque				*line_list;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	line_list = NULL;
	if (buff[fd] == NULL)
		buff[fd] = (t_buffer *)ft_calloc(1, sizeof(t_buffer));
	while ((end_ind = ft_find_end(buff[fd]->buffer + buff[fd]->start, buff[fd]->read_bytes - buff[fd]->start)) == (size_t)-1)
	{
		if (ft_lstpushfront(&line_list, buff[fd]->buffer + buff[fd]->start, buff[fd]->read_bytes - buff[fd]->start))
			return (ft_lstclear(line_list, buff, fd));
		if ((buff[fd]->read_bytes = read(fd, buff[fd]->buffer, BUFFER_SIZE)) == (size_t)-1)
			return (ft_lstclear(line_list, buff, fd));
		else if (buff[fd]->read_bytes == 0)
			return (ft_listmerge(line_list, line, fd, buff) == -1 ? -1 : ft_lstclear(line_list, buff, fd) + 1);
		buff[fd]->start = 0;
	}
	if (ft_lstpushfront(&line_list, buff[fd]->buffer + buff[fd]->start, end_ind))
		return (ft_lstclear(line_list, buff, fd));
	buff[fd]->start += end_ind;
	return (ft_listmerge(line_list, line, fd, buff) == -1 ? -1 : ft_lstclear(line_list, buff, -1) + 2);
}

size_t	ft_find_end(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size)
	{
		if (*str == 0 || *str == 0xa)
			return (i);
		str++;
	}
	return (-1);
}

int		ft_lstpushfront(t_deque **list, const char *str, size_t size)
{
	char	*new_str;
	t_deque	*new_lst;

	if (size-- == 0)
		return (0);
	if (str[size] != 0xa)
		size++;
	if ((new_str = (char *)malloc(size)) == NULL)
		return (1);
	new_lst = (t_deque *)malloc(sizeof(t_deque));
	new_lst->str = new_str;
	new_lst->size = size;
	new_lst->prev = NULL;
	ft_memcpy_fwd(new_str, (void *)str, size);
	new_lst->next = *list;
	if (*list != NULL)
		(*list)->prev = new_lst;
	*list = new_lst;
	return (0);
}

int		ft_lstclear(t_deque *lst, t_buffer **tbuff, int fd)
{
	t_deque	*next;
	size_t	size;

	while (lst)
	{
		next = lst->next;
		free(lst->str);
		free(lst);
		lst = next;
	}
	if (fd != -1)
	{
		size = 0;
		while (size < (size_t)BUFFER_SIZE)
			tbuff[fd]->buffer[size++] = 0;
		free(tbuff[fd]);
		tbuff[fd] = 0;
	}
	return (-1);
}

int		ft_listmerge(t_deque *list, char **line, int fd, t_buffer **tbuff)
{
	size_t	total_size;
	t_deque	*lst_ptr;
	char	*line_ptr;

	total_size = 0;
	lst_ptr = list;
	while (lst_ptr != NULL)
	{
		total_size += lst_ptr->size;
		if (lst_ptr->next == NULL)
			break;
		lst_ptr = lst_ptr->next;
	}
	if ((*line = (char *)malloc(total_size + 1)) == NULL)
		return (ft_lstclear(list, tbuff, fd));
	line_ptr = *line;
	while (lst_ptr)
	{
		line_ptr = ft_memcpy_fwd(line_ptr, lst_ptr->str, lst_ptr->size);
		lst_ptr = lst_ptr->prev;
	}
	*line_ptr = 0;
	return (0);
}

void	*ft_memcpy_fwd(void *dst, void *src, size_t size) {
	while (size--) {
		*(char *)dst++ = *(char *)src++;
	}
	return (dst);
}

void	*ft_calloc(size_t nmeb, size_t size) {
	char *arr;

	arr = (char *)malloc(nmeb * size);
	for (size_t i=0; i < size; i++) {
		arr[i] = 0;
	}
	return (arr);
}