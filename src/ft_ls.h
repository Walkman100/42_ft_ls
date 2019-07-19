/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:02:44 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/18 16:41:42 by mcarter          ###   ########.fr       */
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
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
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
	char	*perms;
	nlink_t	inodes;
	char	*user;
	char	*group;
	off_t	fsize;
	char	*date;
	char	*name;
	char	*ln_target;
}				t_elem;

t_args			parse_args(char *arg_str);
void			show_folder(char *path, t_args args);

t_elem			*get_folder_short(char *path, t_args args);
void			output_columns(t_args args, t_elem *elems);

t_elem			*get_folder_long(char *path, t_args args);
char			*parse_mode(mode_t mode);
char			*parse_user(uid_t uid);
char			*parse_group(gid_t gid);
char			*get_last_modified(struct timespec tspec);
void			sort_elem_array(t_elem *arr);
void			output_line(t_args args, t_elem elem);
void			putnbr_padl(MAXUNBR n, MAXUNBR total_len);
void			putstr_padr(char *s, MAXUNBR total_len);
#endif
