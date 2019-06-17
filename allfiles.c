/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 00:40:40 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 14:48:34 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_directory(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void		info(char *file)
{
	struct stat error;

	if (stat(file, &error) == -1)
		perror(file);
	else
		ft_putendl(file);
}

void		ft_a(char *flag, char *directory)
{
	struct dirent	*d;
	DIR				*dir;

	if (!flag)
		return ;
	dir = NULL;
	if (directory != NULL)
	{
		if (is_directory(directory))
			dir = opendir(directory);
		else if (!(is_directory(directory)))
		{
			info(directory);
			return ;
		}
	}
	else
		dir = opendir(".");
	while ((d = readdir(dir)) != NULL)
		ft_putendl(d->d_name);
	closedir(dir);
}

void		help2(char *flag, char *directory)
{
	struct dirent	*d;
	DIR				*dir;

	if (!flag)
		return ;
	dir = NULL;
	if (directory != NULL)
	{
		if (is_directory(directory))
			dir = opendir(directory);
		else if (!(is_directory(directory)))
		{
			dostat(directory);
			return ;
		}
	}
	else
		dir = opendir(".");
	while ((d = readdir(dir)) != NULL)
		dostat(d->d_name);
	closedir(dir);
}

void		ft_la(char *flag, char *directory)
{
	struct dirent	*d;
	struct stat		blk;
	DIR				*dir;
	int				t;

	if (!flag)
		return ;
	t = 0;
	dir = opendir(".");
	while ((d = readdir(dir)) != NULL)
		(stat(d->d_name, &blk) == -1) ? perror(d->d_name) :
			(t = t + blk.st_blocks);
	ft_putstr("total ");
	ft_putnbr(t);
	ft_putchar('\n');
	help2(flag, directory);
	closedir(dir);
}
