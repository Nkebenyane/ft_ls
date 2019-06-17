/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:14:52 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 17:25:11 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
void	ft_time(char *flag, char *file)
{
	DIR				*dir;
	struct dirent	*d;
    struct stat		time;
    time_t			latest;
	char			name[1025];

	if (!flag)
		return ;
	(void)file;

	latest = 0;
	dir = opendir(".");
    while ((d = readdir(dir)) != NULL)
	{
		ft_memset(&time, 0, sizeof(time));
		if (stat(d->d_name, &time) < 0) 
		{
			printf("Error getting info on file\n");
			continue;
		}
		if ((ft_strcmp(d->d_name, ".") == 0) || (ft_strcmp(d->d_name, "..") == 0))
			continue ;
		if (time.st_mtime > latest)
		{
			strcpy(name, d->d_name);
			latest = time.st_mtime;
		}
    }
    closedir(dir);
    printf("Most recently touched directory %s\n", name);
}
