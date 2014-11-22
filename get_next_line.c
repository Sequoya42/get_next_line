/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 19:45:13 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/22 12:44:34 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char		*ft_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strnew(i);
	ft_strncpy(str, s, i);
	str[i] = '\0';
	return (str);
}

static char		*ft_stock(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strdup(s + i + 1);
	ft_strdel(&s);
	return (str);
}

void			ft_norme(char **buff, char **line, char **save, int ret)
{
	ft_strdel(buff);
	*line = ft_line(*save);
	if (ret == 0)
		ft_strdel(save);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		*temp;
	static char	*save;
	char		*buff;

	buff = ft_strnew(BUFF_SIZE + 1);
	save = (save == NULL) ? ft_strnew(1) : save;
	if (buff == NULL || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	ret = 42;
	while ((ft_strchr(save, '\n') == NULL) && ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		temp = save;
		save = ft_strjoin(save, buff);
		ft_strdel(&temp);
		buff[ret] = '\0';
	}
	ft_norme(&buff, line, &save, ret);
	if (ret == 0)
		return (0);
	save = ft_stock(save);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	(void)argc;
	(void)argv;
//	fd = open(argv[1], O_RDONLY);
	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	return (0);
}
