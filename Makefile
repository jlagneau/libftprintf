#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 08:29:58 by jlagneau          #+#    #+#              #
#    Updated: 2017/04/23 11:39:45 by jlagneau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#
# Variables
#

# Name of the library
NAME       = libftprintf.a
DEB_NAME   = libftprintf_debug.a

# Exec
CC        ?= gcc
AR         = ar
RM         = rm -rf

# Directories
LIB_PATH   = libft/
LIBH_PATH  = libft/include/

SRCS_PATH  = src/
HEAD_PATH  = include/

OBJS_PATH  = .obj/
DEPS_PATH  = .dep/

# Flags
CFLAGS    += -Wall -Wextra -Werror
CPPFLAGS  += -I$(HEAD_PATH) -I$(LIBH_PATH) -DFT_PRINTF_INTERNAL
DEPSFLAGS  = -MMD -MF"$(DEPS_PATH)$(notdir $(@:.o=.d))"
ARFLAGS    = rcsT

# Files
SRCS      := $(shell find src -type f)

OBJS       = $(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))
DEPS       = $(addprefix $(DEPS_PATH), $(notdir $(SRCS:.c=.d)))

DEB_OBJS   = $(OBJS:.o=_debug.o)
DEB_DEPS   = $(DEPS:.d=_debug.d)

# Detect OS
UNAME_S   := $(shell uname -s)

#
# Rules
#

# Phony.
.PHONY: all clean fclean norme re redebug

# Link the main executable.
$(NAME): CFLAGS += -O3
$(NAME): LDFLAGS += -lft
$(NAME): $(OBJS)
	@-git submodule update --init --recursive
	@make -C $(LIB_PATH)
ifeq ($(UNAME_S),Linux)
	$(AR) $(ARFLAGS) $@ $(LIB_PATH)libft.a $^
	@echo -e "create $(NAME)\naddlib $(NAME)\nsave\nend" | $(AR) -M
else
	libtool -static -o $(NAME) $(LIB_PATH)libft.a $^
endif
	ranlib $@

# Link the debug executable.
$(DEB_NAME): CFLAGS += -g3
$(DEB_NAME): LDFLAGS += -lft_debug
$(DEB_NAME): $(DEB_OBJS)
	@-git submodule update --init --recursive
	@make -C $(LIB_PATH) debug
ifeq ($(UNAME_S),Linux)
	$(AR) $(ARFLAGS) $@ $(LIB_PATH)libft_debug.a $^
	@echo -e "create $(DEB_NAME)\naddlib $(DEB_NAME)\nsave\nend" | $(AR) -M
else
	libtool -static -o $@ $(LIB_PATH)libft_debug.a $^
endif
	ranlib $@

# Compile the objects.
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH) $(DEPS_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) -c $< -o $@

# Compile the debug objects.
$(OBJS_PATH)%_debug.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH) $(DEPS_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) -c $< -o $@

# Make debug
debug: $(DEB_NAME)

# Make tests
test: $(NAME)
	@make -C tests
	@ln -sf tests/test test

# Make all.
all: $(NAME)

# Remove the objects and dependencies files.
clean:
	$(RM) $(OBJS_PATH) $(DEPS_PATH)
	@make -C tests clean
	@make -C $(LIB_PATH) clean

# Remove the object, dependencies and executables files.
fclean:
	$(RM) $(OBJS_PATH) $(DEPS_PATH)
	$(RM) $(NAME) $(DEB_NAME) test
	@make -C tests fclean
	@make -C $(LIB_PATH) fclean

# Clean and rebuild the executable.
re: fclean all

# Clean and rebuild the debug executable.
redebug: fclean $(DEB_NAME)

# Include dependencies for objects.
-include $(DEPS)
-include $(DEB_DEPS)
