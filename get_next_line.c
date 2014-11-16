/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:55:05 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/16 19:53:55 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*
 Le premier paramètre est le descripteur de fichier depuis lequel lire.
• Le second paramètre est l’adresse d’un pointeur sur caractère qui servira à stocker
la ligne lue sur le descripteur de fichier.
• la valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est terminée ou bien qu’une erreur est survenue respectivement.
• Votre fonction get_next_line doit renvoyer son resultat sans le ’\n’.
• Un appel en boucle à votre fonction get_next_line permettra donc de lire le texte
disponible sur un descripteur de fichier une ligne à la fois jusqu’à la fin du texte.
• Assurez-vous que votre fonction se comporte bien lorsqu’elle lit depuis un fichier, depuis l’entrée standard, depuis une redirection, etc.*/

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
	static char *save;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	

}


int		main(int argc, char **argv)
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
			while((ret = get_next_line(fd, &line)) != 0)
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





  /*static char     *next_line(char *str)
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
  */
