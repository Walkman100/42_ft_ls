/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:02:44 by mcarter           #+#    #+#             */
/*   Updated: 2020/01/24 11:21:57 by mcarter          ###   ########.fr       */
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
# ifndef __ANDROID__
#  include <sys/acl.h>
# endif
# include <time.h>
# include <stdlib.h>
# include <stdio.h>

# ifdef __linux__
#  include <linux/uuid.h>
#  include <sys/sysmacros.h>
#  ifndef __ANDROID__
#   include <acl/libacl.h>
#  endif
# else
#  include <uuid/uuid.h>
# endif

/*
** on linux, strerror needs string.h...
*/
# include <string.h>
# include "../libft/libft.h"

/*
** all:
** 0 = false
** 1 = true
** 2 = no . and ..
**
** columns:
** 0 = off
** 1 = on
** 2 = auto
*/

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct group	t_group;
typedef struct passwd	t_passwd;

typedef struct	s_args
{
	unsigned char	columns : 2;
	char			long_list : 1;
	unsigned char	all : 2;
	char			no_recurse : 1;
	char			recursive : 1;
	char			no_sort : 1;
	char			reverse_sort : 1;
	char			sort_time : 1;
	char			sort_access : 1;
	char			sort_size : 1;
	char			colour : 1;
	char			show_owner : 1;
	char			show_group : 1;
	char			num_ids : 1;
}				t_args;

typedef struct	s_elem
{
	time_t		atime;
	long		atimenano;
	time_t		mtime;
	long		mtimenano;
	blkcnt_t	blocks;
	char		type;
	char		*perms;
	nlink_t		inodes;
	char		*user;
	char		*group;
	off_t		fsize;
	char		*date;
	char		*name;
	char		*ln_target;
}				t_elem;

typedef struct	s_colinfo
{
	MAXUNBR	cols;
	MAXUNBR	lines;
	MAXUNBR	elem_count;
	MAXUNBR	maxwidth;
}				t_colinfo;

typedef struct	s_lineinfo
{
	MAXUNBR	elem_count;
	MAXUNBR	inodew;
	MAXUNBR	userw;
	MAXUNBR	groupw;
	MAXUNBR	fsizew;
}				t_lineinfo;

t_args			parse_args(int *count, int argc, char **argv);
void			sort_str_array(char **arr, t_args args);
void			add_file(char **files, char *path);
void			show_file(char *file, t_args args);
void			show_files(char **files, t_args args);
void			show_folders(char **folders, t_args args, char forceshow);
MAXUNBR			str_arr_len(char **arr);
void			show_folder(char *path, t_args args);
t_elem			*get_folder(char *path, t_args args);
MAXUNBR			get_folder_count(char *path, unsigned char all);
int				filter(unsigned char all, char *name);
void			sort_elem_array(t_elem *arr, t_args args);
long			cmp_name(t_elem elem1, t_elem elem2);
long			cmp_modified(t_elem elem1, t_elem elem2);
long			cmp_access(t_elem elem1, t_elem elem2);
long			cmp_size(t_elem elem1, t_elem elem2);
void			show_folder_subfolders(char *path, t_args args, t_elem *items);
void			free_items(t_elem **items);

void			set_time(t_elem *elem, t_stat stat_s);
int				set_attributes_short(char *path, t_elem *item);
void			output_columns(t_elem *elems, t_args args);
t_colinfo		get_column_info(t_elem *elems);
MAXUNBR			get_elem_count(t_elem *elems);

int				set_attributes_long(char *path, t_elem *item, t_args args);
void			parse_mode(mode_t mode, char *type, char **perms);
char			get_extra_char(char *path);
char			*parse_user(uid_t uid, char noparse);
char			*parse_group(gid_t gid, char noparse);
char			*get_time_str(time_t seconds);
char			*get_slink_target(char *path, MAXUNBR tlen);
MAXUNBR			get_folder_size(t_elem *elems);
void			output_lines(t_elem *elems, t_args args);
t_lineinfo		get_line_info(t_elem *elems);

void			putnbr_padl(MAXUNBR n, MAXUNBR total_len);
void			putstr_padr(char *s, MAXUNBR total_len);
void			putstr_padr_c(char *s, char *clr, MAXUNBR total_len);
void			output_colour(char type, char *perms);
int				put_error(int errno_l, char *dbg, const char *caller_name);
void			exit_e(int errno_l, char *dbg, const char *caller_name);
int				put_error_path(int errno_l, char *path, char *dbg, \
													const char *caller_name);
void			exit_path(int errno_l, char *path, char *dbg, \
													const char *caller_name);
#endif
