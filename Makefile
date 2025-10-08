CC = cc
<<<<<<< HEAD
CFLAGS = -Wall -Wextra -Werror
=======
CFLAGS = -Wall -Wextra -Werror -g 
>>>>>>> 24080d2 (change_init_solver)

TARGET = bsq

INCLUDES = -Iincludes

SRCDIR = srcs
SRCFILES =	main.c \
			file_io.c \
			ft_atoi.c \
			ft_mem.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strcmp.c \
			ft_strlen.c \
			map_parser.c \
			map_utils.c \
			map_utils2.c \
			ft_putchar.c \
			solver.c \
			ft_strlcpy.c

####
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

SUFFIXES ?= .c .o
.SUFFIXES: $(SUFFIXES) .

OBJS = $(SRCS:.c=.o)

.DEFAULT_GOAL := all

####

COLOUR_GOLD=\033[1;33m
COLOUR_BOLD=\033[1m
COLOUR_END=\033[0m

####
all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "[$(COLOUR_GOLD)BSQ$(COLOUR_END)] 🔗​ $(COLOUR_BOLD)Linking binary...$(COLOUR_END)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	@echo "[$(COLOUR_GOLD)BSQ$(COLOUR_END)] 🔨 Compiling $^ ..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	@echo "[$(COLOUR_GOLD)BSQ$(COLOUR_END)] 🧹 Cleaning temporary files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "[$(COLOUR_GOLD)BSQ$(COLOUR_END)] 🧹 Cleaning binary..."
	@rm -f $(TARGET)

re: fclean all

debug: CFLAGS += -g
debug: all

.PHONY: all clean fclean re debug
