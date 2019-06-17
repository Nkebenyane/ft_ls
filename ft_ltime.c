/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:53:10 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 13:29:38 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include "ft_ls.h"

static	int	is_directory(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void		ft_ltime(char *flag, char *file)
{
	struct dirent	*d;
	struct stat		t;
	DIR				*dir;
	char			*str;
	int				i;
	int				j;
	char			*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	dir = NULL;
	if (!flag)
		return ;
	if (file != NULL)
	{
		if (is_directory(file))
			dir = opendir(file);
		else if (!(is_directory(file)))
		{
			info(file);
			return ;
		}
	}
	else
		dir = opendir(".");
	while ((d = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(d->d_name, ".") == 0) || (ft_strcmp(d->d_name, "..") == 0))
			continue ;
		stat(d->d_name, &t);
		str = 4 + ctime(&t.st_mtime);
		while (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				|| (str[i] == ' ') || str[i] == ':')
			i++;
			while ((str[i] >= '0' && str[i] <= '9'))
			{
				tmp[j] = str[i];
				j++;
				i++;
				ft_putstr(&str[i]);
			}
	}
}
