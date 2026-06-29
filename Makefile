NAME_BASE   := delivery_rush
NAME        := $(NAME_BASE)_$(shell echo $(MODE) | tr A-Z a-z)

CC          := cc

# CFLAGS      := -Wall -Wextra -Werror  TODO: Add later
CPPFLAGS    := -Iinclude

MODE        ?= TEXT

SRC_DIR     := src
OBJ_DIR     := obj/$(MODE)

SRC := \
	src/main.c \
	src/update.c \
	src/render.c \
	src/coordinates.c

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS := -lmenu -lncursesw  # Order matters menu >> ncursesw

ifeq ($(MODE),EMOJI)
	CFLAGS += -DMODE_EMOJI
else
	CFLAGS += -DMODE_TEXT
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME) ($(MODE) mode)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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