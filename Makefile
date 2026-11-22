CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = includes

LIBS = -lGL -lglfw -lGLEW

VPATH = sources
SRCS =	main.c ftsglWindow.c ftsglRenderer.c ftsglImage.c ftsglColor.c ftsglQuad.c ftsglVector.c ftsglShader.c ftsglBufferObject.c ftsglVao.c utils.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = libftsgl

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(OBJDIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
