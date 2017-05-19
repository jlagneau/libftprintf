#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 08:29:58 by jlagneau          #+#    #+#              #
#    Updated: 2017/04/26 14:49:33 by jlagneau         ###   ########.fr        #
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
LIBFT_PATH = libft

SRCS_PATH  = src
OBJS_PATH  = build/obj
DEPS_PATH  = build/dep

HEADERS    = include $(LIBFT_PATH)/include

# Flags
CFLAGS    += -Wall -Wextra -Werror
CPPFLAGS  += $(addprefix -I, $(HEADERS)) -DFT_PRINTF_INTERNAL
DEPSFLAGS  = -MMD -MF"$(subst $(OBJS_PATH),$(DEPS_PATH),$(@:.o=.d))"
ARFLAGS    = rcsT

# Files
SRCS      := $(shell find src -type f)
SRCS_SUB  := $(subst $(SRCS_PATH),, $(shell find src -mindepth 1 -type d))

OBJS      := $(subst $(SRCS_PATH), $(OBJS_PATH), $(SRCS:.c=.o))
DEPS      := $(subst $(SRCS_PATH), $(DEPS_PATH), $(SRCS:.c=.d))

DEB_OBJS   = $(OBJS:.o=_debug.o)
DEB_DEPS   = $(DEPS:.d=_debug.d)

# Detect OS
UNAME_S   := $(shell uname -s)

#
# Macro
#

define CREATE_BUILD_DIR
@mkdir -p $(OBJS_PATH) $(addprefix $(OBJS_PATH), $(SRCS_SUB))
@mkdir -p $(DEPS_PATH) $(addprefix $(DEPS_PATH), $(SRCS_SUB))
endef

define COMPILE
$(CREATE_BUILD_DIR)
$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) -c $< -o $@
endef

define MAKELIB
@-git submodule update --init --recursive
@make -C $(LIBFT_PATH) $(1)
endef

define MAKETEST
@make -C tests $(1)
endef

ifeq ($(UNAME_S),Linux)
define LINK
$(AR) $(ARFLAGS) $@ $(LIBFT_PATH)/libft$(1).a $^
@echo -e "create $(NAME)\naddlib $(NAME)\nsave\nend" | $(AR) -M
ranlib $@
endef
else
define LINK
libtool -static -o $(NAME) $(LIBFT_PATH)/libft$(1).a $^
endef
endif

#
# Rules
#

# Phony.
.PHONY: all clean fclean norme re redebug

# Link the main executable.
$(NAME): CFLAGS += -O3
$(NAME): $(OBJS)
	$(MAKELIB)
	$(LINK)

# Link the debug executable.
$(DEB_NAME): CFLAGS += -g3
$(DEB_NAME): $(DEB_OBJS)
	$(call MAKELIB,debug)
	$(call LINK,_debug)

# Compile the objects.
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(COMPILE)

# Compile the debug objects.
$(OBJS_PATH)%_debug.o: $(SRCS_PATH)%.c
	$(COMPILE)

# Make debug
debug: $(DEB_NAME)

# Make tests
test: $(NAME)
	$(MAKETEST)
	@ln -sf tests/test.sh test

# Clean and rebuild tests
retest: fclean test

# Make all.
all: $(NAME)

# Remove the objects and dependencies files.
clean:
	$(call MAKETEST, clean)
	$(call MAKELIB, clean)
	$(RM) build

# Remove the object, dependencies and executables files.
fclean:
	$(call MAKETEST, fclean)
	$(call MAKELIB, fclean)
	$(RM) build $(NAME) $(DEB_NAME) test

# Clean and rebuild the executable.
re: fclean all

# Clean and rebuild the debug executable.
redebug: fclean $(DEB_NAME)

# Include dependencies for objects.
-include $(DEPS)
-include $(DEB_DEPS)
