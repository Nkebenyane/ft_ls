/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 00:26:53 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 13:45:41 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flags(char *str, char *dir)
{
	if (!((ft_strcmp(str, "-a") == 0) || (ft_strcmp(str, "-l") == 0)
				|| (ft_strcmp(str, "-R") == 0) ||
				(ft_strcmp(str, "-r") == 0) || (ft_strcmp(str, "-t") == 0)))
	{
		ft_putstr("ft_ls: illegal option: -");
		ft_putstr(str);
		return ;
	}
	else
	{
		if (ft_strcmp(str, "-a") == 0)
			ft_a(str, dir);
		if (ft_strcmp(str, "-l") == 0)
			ft_l(str, dir);
		if (ft_strcmp(str, "-R") == 0)
			ft_recursive(str, dir);
		if (ft_strcmp(str, "-r") == 0)
			ft_rev(str, dir);
		if (ft_strcmp(str, "-t") == 0)
			ft_time(str, dir);
	}
}

void	flags_2(char *str, char *dir)
{
	if (!((ft_strcmp(str, "-la") == 0) || (ft_strcmp(str, "-lR") == 0) ||
				(ft_strcmp(str, "-lr") == 0) ||
				(ft_strcmp(str, "-lt") == 0)))
	{
		ft_putstr("ft_ls: illegal option: -");
		ft_putstr(str);
		return ;
	}
	else
	{
		if (ft_strcmp(str, "-la") == 0)
			ft_la(str, dir);
		if (ft_strcmp(str, "-lR") == 0)
			ft_lrecursive(str, dir);
		if (ft_strcmp(str, "-lr") == 0)
			ft_lrev(str, dir);
		if (ft_strcmp(str, "-lt") == 0)
			ft_ltime(str, dir);
	}
}
