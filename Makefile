# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:33:41 by mcarter           #+#    #+#              #
#    Updated: 2019/08/05 11:36:34 by mcarter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCFLAGS = -Wall -Wextra -Werror
NAME = ft_ls
SRC = src/func/filter.c src/func/get_column_info.c src/func/get_elem_count.c \
		src/func/get_extra_char.c src/func/get_folder_count.c \
		src/func/get_folder_size.c src/func/get_line_info.c \
		src/func/get_slink_target.c src/func/get_time_str.c \
		src/func/parse_group.c src/func/parse_mode.c src/func/parse_user.c \
		src/func/set_attributes_long.c src/func/set_attributes_short.c \
		src/func/sort_cmp.c src/main/errors.c src/main/get_folder.c \
		src/main/main.c src/main/parse_args.c src/main/recursion.c \
		src/main/show_folder.c src/main/sort.c src/output/output_colour.c \
		src/output/output_columns.c src/output/output_lines.c src/output/pad.c
OFILES = bin/filter.o bin/get_column_info.o bin/get_elem_count.o \
		bin/get_extra_char.o bin/get_folder_count.o bin/get_folder_size.o \
		bin/get_line_info.o bin/get_slink_target.o bin/get_time_str.o \
		bin/parse_group.o bin/parse_mode.o bin/parse_user.o \
		bin/set_attributes_long.o bin/set_attributes_short.o bin/sort_cmp.o \
		bin/errors.o bin/get_folder.o bin/main.o bin/parse_args.o \
		bin/recursion.o bin/show_folder.o bin/sort.o bin/output_colour.o \
		bin/output_columns.o bin/output_lines.o bin/pad.o
HFILE = src/ft_ls.h
LFT = -L libft -lft
LFTA = libft/libft.a

all: $(NAME)

$(NAME): $(LFTA) $(OFILES) $(HFILE)
	gcc $(GCCFLAGS) $(OFILES) $(LFT) -o $(NAME)

$(LFTA):
	make -C libft

clean:
	rm -rf bin/
	rm -f $(NAME)

fclean: clean
	make -C libft fclean

re: fclean all

norm:
	norminette $(HFILE) $(SRC)

# Individual files

#  func/
bin/filter.o: $(HFILE) src/func/filter.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/filter.c -o bin/filter.o

bin/get_column_info.o: $(HFILE) src/func/get_column_info.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_column_info.c -o bin/get_column_info.o

bin/get_elem_count.o: $(HFILE) src/func/get_elem_count.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_elem_count.c -o bin/get_elem_count.o

bin/get_extra_char.o: $(HFILE) src/func/get_extra_char.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_extra_char.c -o bin/get_extra_char.o

bin/get_folder_count.o: $(HFILE) src/func/get_folder_count.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_folder_count.c -o bin/get_folder_count.o

bin/get_folder_size.o: $(HFILE) src/func/get_folder_size.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_folder_size.c -o bin/get_folder_size.o

bin/get_line_info.o: $(HFILE) src/func/get_line_info.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_line_info.c -o bin/get_line_info.o

bin/get_slink_target.o: $(HFILE) src/func/get_slink_target.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_slink_target.c -o bin/get_slink_target.o

bin/get_time_str.o: $(HFILE) src/func/get_time_str.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_time_str.c -o bin/get_time_str.o

bin/parse_group.o: $(HFILE) src/func/parse_group.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/parse_group.c -o bin/parse_group.o

bin/parse_mode.o: $(HFILE) src/func/parse_mode.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/parse_mode.c -o bin/parse_mode.o

bin/parse_user.o: $(HFILE) src/func/parse_user.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/parse_user.c -o bin/parse_user.o

bin/set_attributes_long.o: $(HFILE) src/func/set_attributes_long.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/set_attributes_long.c -o bin/set_attributes_long.o

bin/set_attributes_short.o: $(HFILE) src/func/set_attributes_short.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/set_attributes_short.c -o bin/set_attributes_short.o

bin/sort_cmp.o: $(HFILE) src/func/sort_cmp.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/sort_cmp.c -o bin/sort_cmp.o

#  main/
bin/errors.o: $(HFILE) src/main/errors.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/errors.c -o bin/errors.o

bin/get_folder.o: $(HFILE) src/main/get_folder.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/get_folder.c -o bin/get_folder.o

bin/main.o: $(HFILE) src/main/main.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/main.c -o bin/main.o

bin/parse_args.o: $(HFILE) src/main/parse_args.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/parse_args.c -o bin/parse_args.o

bin/recursion.o: $(HFILE) src/main/recursion.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/recursion.c -o bin/recursion.o

bin/show_folder.o: $(HFILE) src/main/show_folder.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/show_folder.c -o bin/show_folder.o

bin/sort.o: $(HFILE) src/main/sort.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/sort.c -o bin/sort.o

#  output/
bin/output_colour.o: $(HFILE) src/output/output_colour.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/output/output_colour.c -o bin/output_colour.o

bin/output_columns.o: $(HFILE) src/output/output_columns.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/output/output_columns.c -o bin/output_columns.o

bin/output_lines.o: $(HFILE) src/output/output_lines.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/output/output_lines.c -o bin/output_lines.o

bin/pad.o: $(HFILE) src/output/pad.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/output/pad.c -o bin/pad.o
