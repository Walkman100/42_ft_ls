# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:33:41 by mcarter           #+#    #+#              #
#    Updated: 2019/07/22 13:37:42 by mcarter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCFLAGS = -Wall -Wextra -Werror
NAME = ft_ls
SRC = src/func/get_folder_count.c src/func/get_last_modified.c get_slink_target.c \
		src/func/parse_group.c src/func/parse_mode.c src/func/parse_user.c \
		src/main/get_folder_long.c src/main/get_folder_short.c src/main/main.c \
		src/main/parse_args.c src/main/show_folder src/main/sort.c \
		src/output/output_columns.c src/output/output_line.c src/output/pad.c
OFILES = bin/get_folder_count.o bin/get_last_modified.o bin/get_slink_target.o \
		bin/parse_group.o bin/parse_mode.o bin/parse_user.o bin/get_folder_long.o \
		bin/get_folder_short.o bin/main.o bin/parse_args.o bin/show_folder.o \
		bin/sort.o bin/output_columns.o bin/output_line.o bin/pad.o
HFILE = src/ft_ls.h
LFT = -L libft -lft
LFTA = libft/libft.a

all: $(NAME)

$(NAME): $(LFTA) $(OFILES) $(HFILE)
	gcc $(GCCFLAGS) $(LFT) $(OFILES) -o $(NAME)

$(LFTA):
	make -C libft

clean:
	rm -rf bin/
	rm -f $(NAME)

fclean: clean
	make -C libft fclean

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(HFILE) $(SRC) 2>/dev/null

# Individual files

#  func/
bin/get_folder_count.o: $(HFILE) src/func/get_folder_count.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_folder_count.c -o bin/get_folder_count.o

bin/get_last_modified.o: $(HFILE) src/func/get_last_modified.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_last_modified.c -o bin/get_last_modified.o

bin/get_slink_target.o: $(HFILE) src/func/get_slink_target.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_slink_target.c -o bin/get_slink_target.o

bin/parse_group.o: $(HFILE) src/func/parse_group.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/parse_group.c -o bin/parse_group.o

bin/parse_mode.o: $(HFILE) src/func/parse_mode.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/parse_mode.c -o bin/parse_mode.o

bin/parse_user.o: $(HFILE) src/func/parse_user.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/parse_user.c -o bin/parse_user.o

#  main/
bin/get_folder_long.o: $(HFILE) src/main/get_folder_long.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/get_folder_long.c -o bin/get_folder_long.o

bin/get_folder_short.o: $(HFILE) src/main/get_folder_short.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/get_folder_short.c -o bin/get_folder_short.o

bin/main.o: $(HFILE) src/main/main.c
	@mkdir -p main
	gcc $(GCCFLAGS) -c src/main/main.c -o bin/main.o

bin/parse_args.o: $(HFILE) src/main/parse_args.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/parse_args.c -o bin/parse_args.o

bin/show_folder.o: $(HFILE) src/main/show_folder.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/show_folder.c -o bin/show_folder.o

bin/sort.o: $(HFILE) src/main/sort.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/sort.c -o bin/sort.o

#  output/
bin/output_columns.o: $(HFILE) src/output/output_columns.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/output/output_columns.c -o bin/output_columns.o

bin/output_line.o: $(HFILE) src/output/output_line.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/output/output_line.c -o bin/output_line.o

bin/pad.o: $(HFILE) src/output/pad.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/output/pad.c -o bin/pad.o
