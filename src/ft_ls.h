/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:02:44 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/24 16:21:58 by mcarter          ###   ########.fr       */
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

# ifdef __linux__
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
	char	long_list : 1;
	char	all : 2;
	char	noowner : 1;
	char	no_recurse : 1;
	char	recursive : 1;
	char	no_sort : 1;
	char	reverse_sort : 1;
	char	sort_time : 1;
	char	sort_access : 1;
	char	colour : 1;
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

typedef struct	s_colinfo
{
	size_t	cols;
	size_t	lines;
	size_t	elem_count;
	size_t	maxwidth;
}				t_colinfo;

void			parse_args(t_args *args, char *arg_str);
void			show_folder(char *path, t_args args);

t_elem			*get_folder_short(char *path, t_args args);
void			output_columns(t_elem *elems, t_args args);
t_colinfo		get_column_info(t_elem *elems);
size_t			get_elem_count(t_elem *elems);

t_elem			*get_folder_long(char *path, t_args args);
MAXUNBR			get_folder_count(char *path, char all);
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
