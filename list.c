/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:30:19 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/27 14:28:56 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int	is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void		help(char *flag, char *file, struct dirent	*d)
{
	DIR				*dir;

	dir = NULL;
	if (!flag)
		return ;
	if (file != NULL)
	{
		if (is_directory(file))
			dir = opendir(file);
		else if (!(is_directory(file)))
		{
			dostat(file);
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
		dostat(d->d_name);
	}
	closedir(dir);
}

void		ft_l(char *flag, char *file)
{
	struct dirent	*d;
	struct stat		blk;
	DIR				*dir;
	int				ret;

	ret = 0;
	if (!flag)
		return ;
	dir = opendir(".");
	while ((d = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(d->d_name, ".") == 0) ||
				(ft_strcmp(d->d_name, "..") == 0))
			continue ;
		if (stat(d->d_name, &blk) == -1)
			perror(d->d_name);
		else
			ret = ret + blk.st_blocks;
	}
	ft_putstr("total ");
	ft_putnbr(ret);
	ft_putchar('\n');
	closedir(dir);
	help(flag, file, d);
	exit(0);
}
