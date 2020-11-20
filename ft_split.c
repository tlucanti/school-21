/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:16:40 by tlucanti          #+#    #+#             */
/*   Updated: 2020/11/16 16:02:03 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	arrlen;
	size_t	size;

	ret = (char **)ft_calloc(1, sizeof(char **));
	if (s == NULLPTR || ret == NULLPTR)
		return (NULLPTR);
	arrlen = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		size = 0;
		while (*s != c && *s)
		{
			size++;
			s++;
		}
		ret = ft_str_append_sized(ret, (char *)(s - size), size, arrlen++);
	}
	return (ft_error_test_ft_split(ret));
}

char	**ft_error_test_ft_split(char **ret)
{
	if (ret == NULLPTR)
		return (NULLPTR);
	if (*ret == NULLPTR)
		return (ret);
	if (!*ret)
		return (ft_str_append_sized(ret, (char *)ft_calloc(1, 1), 1, 0));
	return (ret);
}

char	**ft_str_append_sized(char **arr, char *str, size_t size, size_t arrlen)
{
	char	*new_s;

	new_s = (char *)malloc(size + 1);
	if (new_s == NULLPTR)
		return (0);
	ft_memcpy(new_s, str, size + 1);
	new_s[size] = 0;
	return (ft_push_back_char_ss(arr, new_s, arrlen));
}

char	**ft_push_back_char_ss(char **arr, char *new_s, size_t arrlen)
{
	char	**new_arr;
	char	**new_arr_ptr;
	char	**old_arr_ptr;

	if (arr == NULLPTR)
	{
		new_arr = (char **)malloc(sizeof(char *) * 2);
		if (new_arr == NULLPTR)
			return (NULLPTR);
		new_arr[0] = new_s;
		new_arr[1] = NULLPTR;
	}
	else
	{
		old_arr_ptr = arr;
		new_arr = (char **)malloc(sizeof(char *) * (arrlen + 2));
		new_arr_ptr = new_arr;
		while (*arr)
			*new_arr_ptr++ = *arr++;
		*new_arr_ptr++ = new_s;
		*new_arr_ptr = NULLPTR;
		free(old_arr_ptr);
	}
	return (new_arr);
}
