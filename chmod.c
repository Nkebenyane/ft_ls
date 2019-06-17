/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chmod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:37:09 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/29 16:53:35 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*uid_to_name(uid_t uid)
{
	struct passwd	*pw_ptr;
	static char		numstr[10];

	if ((pw_ptr = getpwuid(uid)) == NULL)
		return (numstr);
	else
		return (pw_ptr->pw_name);
}

char	*gid_to_name(gid_t gid)
{
	struct group	*grp_ptr;
	static char		numstr[10];

	if ((grp_ptr = getgrgid(gid)) == NULL)
		return (numstr);
	else
		return (grp_ptr->gr_name);
}

void	mode_to_letters(int mode, char *str)
{
	ft_strcpy(str, "----------");
	if (S_ISDIR(mode))
		str[0] = 'd';
	if (S_ISCHR(mode))
		str[0] = 'c';
	if (S_ISBLK(mode))
		str[0] = 'b';
	if (mode & S_IRUSR)
		str[1] = 'r';
	if (mode & S_IWUSR)
		str[2] = 'w';
	if (mode & S_IXUSR)
		str[3] = 'x';
	if (mode & S_IRGRP)
		str[4] = 'r';
	if (mode & S_IWGRP)
		str[5] = 'w';
	if (mode & S_IXGRP)
		str[6] = 'x';
	if (mode & S_IROTH)
		str[7] = 'r';
	if (mode & S_IWOTH)
		str[8] = 'w';
	if (mode & S_IXOTH)
		str[9] = 'x';
}

void	show_file_info(char *filename, struct stat *info_p)
{
	char modestr[11];

	mode_to_letters(info_p->st_mode, modestr);
	printf("%s ", modestr);
	printf("%4d ", (int)info_p->st_nlink);
	printf("%-8s ", uid_to_name(info_p->st_uid));
	printf("%-8s ", gid_to_name(info_p->st_gid));
	printf("%8ld ", (long)info_p->st_size);
	printf("%.12s ", 4 + ctime(&info_p->st_mtime));
	printf("%s\n", filename);
}

void	dostat(char *filename)
{
	struct stat info;

	if (stat(filename, &info) == -1)
		perror(filename);
	else
		show_file_info(filename, &info);
}
