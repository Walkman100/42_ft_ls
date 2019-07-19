# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:33:41 by mcarter           #+#    #+#              #
#    Updated: 2019/07/18 08:56:15 by mcarter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCFLAGS = -Wall -Wextra -Werror
NAME = ft_ls
SRC = src/func/get_last_modified.c src/func/parse_group.c src/func/parse_mode.c \
		src/func/parse_user.c src/main/get_folder_long.c src/main/get_folder_short.c \
		src/main/output_folder.c src/main/parse_args.c src/main/sort.c \
		src/output/output_columns.c src/output/output_line.c src/output/pad.c
OFILES = bin/get_last_modified.o bin/parse_group.o bin/parse_mode.o bin/parse_user.o \
		bin/get_folder_long.o bin/get_folder_short.o bin/output_folder.o bin/parse_args.o \
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
bin/get_last_modified.o: $(HFILE) src/func/get_last_modified.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_last_modified.c -o bin/get_last_modified.o

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

bin/output_folder.o: $(HFILE) src/main/output_folder.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/output_folder.c -o bin/output_folder.o

bin/parse_args.o: $(HFILE) src/main/parse_args.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/parse_args.c -o bin/parse_args.o

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

