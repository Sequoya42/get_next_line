/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 12:04:18 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/18 16:33:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
// GNL de remi

static char     *ft_read_line(char *str, char c)
{
    size_t      i;
    char        *line;

    i = 0;
    while (str[i] != c)
		i++;
    line = ft_strnew(i);
    ft_strncpy(line, str, i);
    line[i] = '\0';
    return (line);
}

static char     *next_line(char *str)
{
    char        *n_str;
    int         i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if ((str[i] && !str[i + 1]) || !str[i])
    {
        ft_strdel(&str);
        return (NULL);
    }
    n_str = ft_strdup(str + i + 1);
    ft_strdel(&str);
    return (n_str);
}

int             get_next_line(int const fd, char **line)
{
    int         ret;
    char        buff[BUFF_SIZE + 1];
    static char *save;

    if (BUFF_SIZE <= 0 || line == NULL)
		return (-1);
    if (save == NULL)
		save = ft_strnew(1);
    ret = 2;
    while (ft_strchr(save, '\n') == NULL && ret != 0)
    {
        ret = read(fd, buff, BUFF_SIZE);
        if (ret == -1)
            return (-1);
        buff[ret] = '\0';
        save = ft_strjoin(save, buff);
    }
    *line = (ret > 0) ? ft_read_line(save, '\n') : ft_read_line(save, '\0');
    if (ret == 0)
        return (0);
    save = next_line(save);
    return (1);
}

int     main(int argc, char **argv)
{
    int fd;
    int ret;
    char *line;

    if (argc != 2)
        ft_putstr("Error: File name missing!\n");
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            ft_putstr("Error: Can't open file!\n");
        else
        {
            while((ret = get_next_line(fd, &line)) > 0)
            {
                ft_putstr(line);
                ft_putstr("\n");
            }
            ft_putstr(line);
            ft_putstr("\n");
            return (close(fd));
        }
    }
    return (0);
}
