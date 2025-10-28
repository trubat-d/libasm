NAME 		:= libasm.a

NASM 		:= nasm
NASMFLAGS	:= -f elf64

GCC		:= gcc
GCCFLAGS	:= -Wall -Wextra -Werror
LIBS		:= -L. -lasm


AR		:= ar rcs
RM		:= rm -f
MKDIR		:= mkdir -p

SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= include

SRCS		:= ft_strlen.s \
		   ft_strcpy.s \
		   ft_strcmp.s \
		   ft_write.s \
		   ft_read.s \
		   ft_strdup.s

OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.s=.o))

MAIN_DIR	:= mains
PROG_DIR	:= prog

MAINS		:= ft_strlen_main.c \
		   ft_strcpy_main.c \
		   ft_strcmp_main.c \
		   ft_write_main.c \
		   ft_read_main.c \
		   ft_strdup_main.c


PROGS		:= $(addprefix $(PROG_DIR)/, $(MAINS:.c=.bin))
TXT_FILE	:= read.txt

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(NASM) $(NASMFLAGS) $< -o $@

$(PROG_DIR):
	@$(MKDIR) $(PROG_DIR)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(PROG_DIR)/%.bin: $(MAIN_DIR)/%.c | $(PROG_DIR)
	$(GCC) $(GCCFLAGS) $< $(LIBS) -I$(INC_DIR) -o $@ 

programs: $(NAME) $(PROGS)
	@echo -n "This is a test value" > $(PROG_DIR)/$(TXT_FILE)

clean: 
	$(RM) $(OBJS) $(PROGS) $(PROG_DIR)/*

fclean: clean
	$(RM) $(NAME)



re: fclean all

.PHONY: all clean fclean re
