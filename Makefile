CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = includes

LIBDIR = libs
LIBS = -lGL -lglfw -lGLEW

LIBSTRDIR = $(LIBDIR)/libstr
LIBSTR = $(LIBSTRDIR)/libstr.h

LIBMEMDIR = $(LIBDIR)/libmem
LIBMEM = $(LIBMEMDIR)/libmem.h

VPATH = sources:sources/callbacks:sources/utils
SRCS =	main.c ftsglWindow.c ftsglRenderer.c ftsglImage.c ftsglColor.c ftsglQuad.c ftsglVector.c ftsglShader.c ftsglBufferObject.c ftsglVao.c utils.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = libftsgl

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o : %.c | $(OBJDIR) $(LIBSTR) $(LIBMEM)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(LIBSTRDIR) -I $(LIBMEMDIR)

$(LIBSTR) : | $(LIBSTRDIR)
	git clone https://github.com/julienPR86/libstr.git $(LIBSTRDIR)

$(LIBMEM) : | $(LIBMEMDIR)
	git clone https://github.com/julienPR86/libmem.git $(LIBMEMDIR)

$(LIBDIR) :
	mkdir -p $@

$(LIBSTRDIR) : | $(LIBDIR)
	mkdir -p $@

$(LIBMEMDIR) : | $(LIBDIR)
	mkdir -p $@

$(OBJDIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
