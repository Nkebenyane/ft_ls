/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lreverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:49:36 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 16:39:18 by mnkebeny         ###   ########.fr       */
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

void		lreverse(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
		dostat(str[i--]);
}

void		fix(DIR *dir, struct dirent **d, char **s)
{
	char			*tmp;
	char			*tmp1;
	int				i;
	struct stat		blk;

	i = 0;
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
		stat((*d)->d_name, &blk);
		i = i + blk.st_blocks;
	}
	ft_putstr("total ");
	ft_putnbr(i);
	ft_putchar('\n');
}

void		ft_lrev(char *flag, char *file)
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
			dostat(file);
			return ;
		}
	}
	else
		dir = opendir(".");
	fix(dir, &d, &s);
	closedir(dir);
	str = ft_strsplit(s, ' ');
	lreverse(str);
	exit(0);
}
