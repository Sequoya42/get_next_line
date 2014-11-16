/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:18:58 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/15 18:25:25 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	if (*alst)
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
