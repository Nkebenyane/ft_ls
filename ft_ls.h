/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:08:30 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 13:46:06 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
# define FT_LS_H


#include "libft/libft.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

void    just_ls();
void	ft_sort();
void	flags(char *str, char *dir);
void	flags_2(char *str, char *dir);
void	listdir(const char *name, int indent);
void    sort_d(struct stat *tab, char *filename);

void	ft_rev(char *flag, char *dir);
void    ft_a(char *flag, char *dir);
void    ft_l(char *flag, char *dir);
void	ft_recursive(char *flag, char *dir);
void	ft_time(char *flag, char *file);


void	llistdir(const char *name, int indent);
void	ft_lrev(char *flag, char *dir);
void	sort(char *f);
void    ft_la(char *flag, char *dir);
void	ft_lrecursive(char *flag, char *dir);
void	ft_ltime(char *file, char *dir);

char	*gid_to_name(gid_t gid);
char	*uid_to_name(uid_t uid);
void	mode_to_letters(int mode, char *str);
void	show_file_info(char *filename, struct stat *info_p);

void	dostat(char *filename);
void	ldostat(char *filename);

void	info(char *f);
void	helper(char *flag, char *file);
void	reverse(char **str);


#endif
