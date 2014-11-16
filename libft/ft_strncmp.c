/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:26:16 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/15 13:47:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	if ((!s1 && !s2) || n < 1)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (ft_strlen(s1) - ft_strlen(s2));
	while (s1[i] && i < n)
	{
		diff = (s1[i] - s2[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
