/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:15:50 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/15 16:57:00 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content = ft_memalloc(content_size);
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
