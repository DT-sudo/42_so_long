# Vars
CC = gcc
CFLAGS = -Wall -Werror -Wextra
# LIBS = -lmlx -lXext -lX11 -lm  # Add appropriate graphics libraries

# Executable file name
NAME = so_long

# Dirs
UTILSDIR = utils
SRCDIR = src
OBJSDIR = obj

# Source files
UTIL_SRC = ft_itoa.c ft_print_hex.c ft_print_ptr.c \
           ft_print_unsigned.c ft_printf_utils.c ft_putchar_fd.c \
           ft_strdup.c ft_strlen.c ft_strrchr.c \
           get_next_line_utils.c get_next_line.c ft_strcmp.c

SRC = collectibles_exit.c creat_map.c main.c utils.c validate_arguments.c validate_map.c

# Object files
UTIL_OBJ = $(addprefix $(OBJSDIR)/, $(UTIL_SRC:.c=.o))
SRCS_OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))
OBJS = $(SRCS_OBJ) $(UTIL_OBJ)

# Default target
all: $(NAME)

# Link the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Compile source objects from src/
$(OBJSDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile utils objects from utils/
$(OBJSDIR)/%.o: $(UTILSDIR)/%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJSDIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re




# # Vars
# CC       = gcc
# CFLAGS   = -Wall -Werror -Wextra

# # Executable file name
# NAME     = so_long

# # Dirs
# UTILSDIR = utils
# SRCDIR   = src
# OBJSDIR  = obj

# # Source files
# UTIL_SRC = ft_itoa.c ft_print_hex.c ft_print_ptr.c \
#            ft_print_unsigned.c ft_printf_utils.c ft_putchar_fd.c \
# 		   ft_strdup.c ft_strlen.c ft_strrchr.c \
#            get_next_line_utils.c get_next_line.c

# SRC      = collectibles_exit.c creat_map.c main.c utils.c validate_arguments.c validate_map.c

# # Object files
# UTIL_OBJ = $(addprefix $(OBJSDIR)/, $(UTIL_SRC:.c=.o))
# SRCS_OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))
# OBJS     = $(SRCS_OBJ) $(UTIL_OBJ)

# # Full paths to source files (used in rules)
# UTIL_SRC_PATHS = $(addprefix $(UTILSDIR)/, $(UTIL_SRC))
# SRC_PATHS      = $(addprefix $(SRCDIR)/, $(SRC))

# # Default target
# all: $(NAME)

# # Link the final executable
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# # Compile source objects from src/
# $(OBJSDIR)/%.o: $(SRCDIR)/%.c
# 	mkdir -p $(OBJSDIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Compile utils objects from utils/
# $(OBJSDIR)/%.o: $(UTILSDIR)/%.c
# 	mkdir -p $(OBJSDIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean object files
# clean:
# 	rm -rf $(OBJSDIR)

# # Clean everything
# fclean: clean
# 	rm -f $(NAME)

# # Rebuild everything
# re: fclean all

# .PHONY: all clean fclean re