/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 09:27:20 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 17:10:24 by mnkebeny         ###   ########.fr       */
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

void		just_ls(char *directory)
{
	DIR				*d;
	struct dirent	*dir;

	dir = NULL;
	if (directory != NULL)
	{
		if (is_directory(directory))
			d = opendir(directory);
		else
		{
			info(directory);
			return ;
		}
	}
	else
		d = opendir(".");
	while ((dir = readdir(d)) != NULL)
	{
		if (ft_strcmp(dir->d_name, ".") == 0 ||
				ft_strcmp(dir->d_name, "..") == 0)
			continue ;
		ft_putendl(dir->d_name);
	}
	closedir(d);
}

int			main(int ac, char **av)
{
	char *flag;
	char *directory;

	flag = av[1];
	directory = av[2];
	if (ac == 1)
	{
		just_ls(flag);
		return (0);
	}
	if ((ac == 1 || ac == 2) && (av[1][0] != '-'))
	{
		just_ls(flag);
		return (0);
	}
	if (ft_strlen(flag) == 2)
		flags(flag, directory);
	else
		flags_2(flag, directory);
	return (0);
}
