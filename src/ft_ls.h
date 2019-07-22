/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:02:44 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 11:37:13 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define _DARWIN_USE_64_BIT_INODE 1

# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# ifdef linux
#  include <linux/uuid.h>
# else
#  include <uuid/uuid.h>
# endif

/*
** on linux, strerror needs string.h...
*/
# include <string.h>
# include "../libft/libft.h"

typedef struct	s_args
{
	char	long_list;
	char	all;
	char	noowner;
	char	no_recurse;
	char	recursive;
	char	no_sort;
	char	reverse_sort;
	char	sort_time;
	char	sort_access;
	char	colour;
}				t_args;

typedef struct	s_elem
{
	time_t	atime;
	time_t	mtime;
	char	type;
	char	*perms;
	nlink_t	inodes;
	char	*user;
	char	*group;
	off_t	fsize;
	char	*date;
	char	*name;
	char	*ln_target;
}				t_elem;

void			parse_args(t_args *args, char *arg_str);
void			show_folder(char *path, t_args args);

t_elem			*get_folder_short(char *path, t_args args);
void			output_columns(t_elem *elems, t_args args);

t_elem			*get_folder_long(char *path, t_args args);
MAXUNBR			get_item_count(char *path, char all);
char			get_type(mode_t mode);
char			*get_perms(mode_t mode);
char			*parse_user(uid_t uid);
char			*parse_group(gid_t gid);
char			*get_last_modified(struct timespec tspec);
char			*get_slink_target(char *path, MAXUNBR tlen);
void			sort_elem_array(t_elem *arr, t_args args);
void			output_line(t_elem elem, t_args args);
void			putnbr_padl(MAXUNBR n, MAXUNBR total_len);
void			putstr_padr(char *s, MAXUNBR total_len);
#endif
