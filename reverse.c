/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:29:47 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 16:37:25 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int	is_directory(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void		min(DIR *dir, struct dirent **d, char **s)
{
	char	*tmp;
	char	*tmp1;

	while ((*d = readdir(dir)) != NULL)
	{
		if ((ft_strcmp((*d)->d_name, ".") == 0) ||
				(ft_strcmp((*d)->d_name, "..") == 0))
			continue ;
		tmp = ft_strjoin((*d)->d_name, " ");
		if (!(*s))
			*s = tmp;
		else
		{
			tmp1 = tmp;
			tmp = *s;
			*s = ft_strjoin(tmp, tmp1);
			free(tmp1);
			free(tmp);
		}
	}
}

void		reverse(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
		ft_putendl(str[i--]);
}

void		ft_rev(char *flag, char *file)
{
	struct dirent	*d;
	DIR				*dir;
	char			**str;
	char			*s;

	s = NULL;
	dir = NULL;
	if (!flag)
		return ;
	if (file != NULL)
	{
		(is_directory(file)) ? dir = opendir(file) : 0;
		if (!(is_directory(file)))
		{
			info(file);
			return ;
		}
	}
	else
		dir = opendir(".");
	min(dir, &d, &s);
	closedir(dir);
	str = ft_strsplit(s, ' ');
	reverse(str);
	exit(0);
}
