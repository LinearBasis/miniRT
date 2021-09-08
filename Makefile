NAME = miniRT

MAIN = main.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIRS = ./srcs/ ./srcs/colors ./srcs/figures ./srcs/intersections ./srcs/list ./srcs/scene ./srcs/vectors ./srcs/utils ./srcs/libft\
			./srcs/gnl ./srcs/parser ./srcs/screen ./srcs/main

SRCS = 

HEADERS_DIR = ./headers

OBJS_DIR = ./objs

SRCS = $(wildcard $(addsuffix /*.c, $(SRCS_DIRS)))

OBJS = $(addprefix objs/, $(notdir $(patsubst %.c, %.o, $(SRCS))))

VPATH = $(SRCS_DIRS)

HEADERS = $(wildcard $(addsuffix /*.h, $(HEADERS_DIR)))

$(OBJS_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx  -c $< -o $@

all: $(NAME)

$(NAME): $(HEADERS_DIR) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(MAKEDEPS)
