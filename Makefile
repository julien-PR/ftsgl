CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES_DIRECTORIES = includes
INCLUDES = $(addprefix -I, $(INCLUDES_DIRECTORIES))

LIBS = -lGL -lglfw -lGLEW

VPATH = sources
SRCS =	main.c ftsglWindow.c ftsglRenderer.c ftsglImage.c ftsglColor.c ftsglQuad.c ftsglVector.c ftsglShader.c ftsglBufferObject.c ftsglVao.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = libftsgl

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
