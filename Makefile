NAME = miniRT

MAIN = main.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIRS = . ./colors ./figures ./intersections ./list ./scene ./vectors ./utils ./libft\
			./gnl ./parser ./screen ./main

HEADERS_DIR = ./headers

OBJS_DIR = ./objs

SRCS = $(wildcard $(addsuffix /*.c, $(SRCS_DIRS)))

OBJS = $(addprefix objs/, $(notdir $(patsubst %.c, %.o, $(SRCS))))

VPATH = $(SRCS_DIRS)

HEADERS = $(wildcard $(addsuffix /*.h, $(HEADERS_DIR)))

$(OBJS_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx  -c $< -o $@

all: $(NAME)

$(NAME):  dir_create $(HEADERS_DIR) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

dir_create:
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(MAKEDEPS)
