NAME_BASE	:= delivery_rush
MODE		?= TEXT
NAME		:= $(NAME_BASE)_$(shell echo $(MODE) | tr A-Z a-z)

CC			:= cc

# CFLAGS	:= -Wall -Wextra -Werror
CPPFLAGS	:= -Iinclude

SRC_DIR		:= src
OBJ_DIR		:= obj/$(MODE)

SRCS		:= $(wildcard $(SRC_DIR)/*.c)
SRCS		+= $(wildcard $(SRC_DIR)/menus/*.c)

HEADERS		:= $(wildcard include/*.h)

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS		:= -lmenu -lncursesw

ifeq ($(MODE),EMOJI)
	CFLAGS += -DMODE_EMOJI
else
	CFLAGS += -DMODE_TEXT
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME) ($(MODE) mode)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "Compiling $< ($(MODE))"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME_BASE)_text
	rm -f $(NAME_BASE)_emoji

re: fclean all

text:
	$(MAKE) MODE=TEXT

emoji:
	$(MAKE) MODE=EMOJI

.PHONY: all clean fclean re text emoji