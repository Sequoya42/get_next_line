/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:55:05 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/18 17:22:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char		*avant(char *s)
{
	size_t		i;
	char	*str;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strnew(i);
	ft_strncpy(str, s, i);
	str[i] = '\0';
	return (str);
}


char		*apres(char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strdup(&s[i + 1]);
	return (str);
	
}

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char *save;
	if (BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (save == NULL)
		save = ft_strnew(1);
	ret = 17;
	while (ret > 0 && (ft_strchr(save, '\n') == NULL))
	{
		ret = (read(fd, buff, BUFF_SIZE));
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';

}
