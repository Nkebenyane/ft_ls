/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:11:19 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 11:54:40 by mnkebeny         ###   ########.fr       */
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

void		listdir(const char *name, int indent)
{
	DIR				*dir;
	struct dirent	*entry;

	if (!(dir = opendir(name)))
		return ;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
			if (ft_strcmp(entry->d_name, ".") == 0 ||
					ft_strcmp(entry->d_name, "..") == 0)
				continue;
			listdir(name, indent + 2);
		}
		else
			ft_putendl(entry->d_name);
	}
	closedir(dir);
}

void		ft_recursive(char *flag, char *file)
{
	struct dirent	*d;
	DIR				*dir;

	dir = NULL;
	(void)flag;
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
	while ((d = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(d->d_name, ".") == 0) ||
				(ft_strcmp(d->d_name, "..") == 0))
			continue ;
		ft_putendl(d->d_name);
	}
	closedir(dir);
	helper(flag, file);
}
