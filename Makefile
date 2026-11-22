CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBS_DIR = libs
JPR_LIB_DIR = $(LIBS_DIR)/JPR

JPR_LIBMEM_DIR = $(JPR_LIB_DIR)/libmem
JPR_LIBMEM = $(JPR_LIBMEM_DIR)/libmem.h

JPR_LIBSTR_DIR = $(JPR_LIB_DIR)/libstr
JPR_LIBSTR = $(JPR_LIBSTR_DIR)/libstr.h

JPR_LIBFILE_DIR = $(JPR_LIB_DIR)/libfile
JPR_LIBFILE = $(JPR_LIBFILE_DIR)/libfile.h

INCLUDES_DIRECTORIES = includes $(JPR_LIBMEM_DIR) $(JPR_LIBSTR_DIR) $(JPR_LIBFILE_DIR)
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

$(OBJDIR)/%.o : %.c | $(OBJDIR) $(JPR_LIBSTR) $(JPR_LIBMEM) $(JPR_LIBFILE)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBS_DIR) :
	mkdir -p $@

$(JPR_LIB_DIR) : | $(LIBS_DIR)
	rm -rf $(JPR_LIB_DIR)
	git clone https://github.com/julien-PR/JPR.git $@

$(JPR_LIBSTR) :
	rm -rf $(JPR_LIB_DIR)
	$(MAKE) $(JPR_LIB_DIR)

$(JPR_LIBMEM) :
	rm -rf $(JPR_LIB_DIR)
	$(MAKE) $(JPR_LIB_DIR)

$(JPR_LIBFILE) :
	rm -rf $(JPR_LIB_DIR)
	$(MAKE) $(JPR_LIB_DIR)

$(OBJDIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
