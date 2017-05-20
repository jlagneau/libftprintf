#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 08:29:58 by jlagneau          #+#    #+#              #
#    Updated: 2017/05/20 12:08:17 by jlagneau         ###   ########.fr        #
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
SRCS_PATH  = src
HEAD_PATH  = include

BUILD_PATH = build
OBJS_PATH  = $(BUILD_PATH)/obj
DEPS_PATH  = $(BUILD_PATH)/dep

LIBFT_PATH = libft
LIBFT_HEAD = $(LIBFT_PATH)/include

HEADERS   := $(LIBFT_HEAD) $(shell find $(HEAD_PATH) -type d)

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

define COMPILE
$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) -c $< -o $@
endef

define MAKELIB
@$(MAKE) -C $(LIBFT_PATH) $(1)
endef

define MAKETEST
@$(MAKE) -C tests $(1)
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
.PHONY: all clean fclean libft libft_debug re redebug retest

# Link the main executable.
$(NAME): CFLAGS += -O3
$(NAME): $(OBJS)
	$(LINK)

# Link the debug executable.
$(DEB_NAME): CFLAGS += -g3
$(DEB_NAME): $(DEB_OBJS)
	$(call LINK,_debug)

# Compile the objects.
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(COMPILE)

# Compile the debug objects.
$(OBJS_PATH)%_debug.o: $(SRCS_PATH)%.c
	$(COMPILE)

# Create build directories and build library
$(OBJS): | $(OBJS_PATH) $(DEPS_PATH) libft
$(DEB_OBJS): | $(OBJS_PATH) $(DEPS_PATH) libft_debug

# Create build object directory
$(OBJS_PATH):
	mkdir -p $(OBJS_PATH) $(addprefix $(OBJS_PATH), $(SRCS_SUB))

# Create build dependencies directory
$(DEPS_PATH):
	mkdir -p $(DEPS_PATH) $(addprefix $(DEPS_PATH), $(SRCS_SUB))

# Build library
libft:
	$(MAKELIB)

# Build debug library
libft_debug:
	$(call MAKELIB, debug)

# Make debug
debug: $(DEB_NAME)

# Make tests
test: | $(NAME)
	$(MAKETEST)
	@ln -sf tests/test.sh test

# Make all.
all: $(NAME)

# Remove the objects and dependencies files.
clean:
	$(call MAKETEST, clean)
	$(call MAKELIB, clean)
	$(RM) $(BUILD_PATH)

# Remove the object, dependencies and executables files.
fclean:
	$(call MAKETEST, fclean)
	$(call MAKELIB, fclean)
	$(RM) $(BUILD_PATH) $(NAME) $(DEB_NAME) test

# Clean and rebuild the executable.
re: | fclean
	@$(MAKE) all

# Clean and rebuild the debug executable.
redebug: | fclean
	@$(MAKE) debug

# Clean and rebuild tests
retest: | fclean
	@$(MAKE) test

# Include dependencies for objects.
-include $(DEPS)
-include $(DEB_DEPS)
