#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 08:29:58 by jlagneau          #+#    #+#              #
#    Updated: 2017/05/20 11:59:34 by jlagneau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#
# Variables
#

# Name of the executable
NAME       = test
DEB_NAME   = test_debug

# Exec
CC        ?= gcc
RM         = rm -rf

# Directories
SRCS_PATH  = src
HEAD_PATH  = include

BUILD_PATH = build
OBJS_PATH  = $(BUILD_PATH)/obj
DEPS_PATH  = $(BUILD_PATH)/dep

LIBFT_PATH = ../libft
LIBFT_HEAD = $(LIBFT_PATH)/include

LIBPF_PATH = ..
LIBPF_HEAD = $(LIBPF_PATH)/include

HEADERS   := $(LIBFT_HEAD) $(LIBPF_HEAD) $(shell find $(HEAD_PATH) -type d)

# Flags
CFLAGS    += -Wall -Wextra -Werror -Wno-format
CPPFLAGS  += $(addprefix -I, $(HEADERS))
LDFLAGS   += -L$(LIBPF_PATH)
DEPSFLAGS  = -MMD -MF"$(subst $(OBJS_PATH),$(DEPS_PATH),$(@:.o=.d))"

# Files
SRCS      := $(shell find src -type f)
SRCS_SUB  := $(subst $(SRCS_PATH),, $(shell find src -mindepth 1 -type d))

OBJS      := $(subst $(SRCS_PATH), $(OBJS_PATH), $(SRCS:.c=.o))
DEPS      := $(subst $(SRCS_PATH), $(DEPS_PATH), $(SRCS:.c=.d))

DEB_OBJS   = $(OBJS:.o=_debug.o)
DEB_DEPS   = $(DEPS:.d=_debug.d)

#
# Macro
#

define COMPILE
$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) -c $< -o $@
endef

define LINK
$(CC) $^ $(LDFLAGS) -o $@
endef

#
# Rules
#

# Phony.
.PHONY: all clean debug fclean norme re redebug

# Link the main executable.
$(NAME): CFLAGS += -O3
$(NAME): LDFLAGS += -lftprintf
$(NAME): $(OBJS)
	$(LINK)

# Link the debug executable.
$(DEB_NAME): CFLAGS += -g3
$(DEB_NAME): LDFLAGS += -lftprintf_debug
$(DEB_NAME): $(DEB_OBJS)
	$(LINK)

# Compile the objects.
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(COMPILE)

# Compile the debug objects.
$(OBJS_PATH)%_debug.o: $(SRCS_PATH)%.c
	$(COMPILE)

# Create build directories
$(OBJS): | $(OBJS_PATH) $(DEPS_PATH)
$(DEB_OBJS): | $(OBJS_PATH) $(DEPS_PATH)

# Create build object directory
$(OBJS_PATH):
	mkdir -p $(OBJS_PATH) $(addprefix $(OBJS_PATH), $(SRCS_SUB))

# Create build dependencies directory
$(DEPS_PATH):
	mkdir -p $(DEPS_PATH) $(addprefix $(DEPS_PATH), $(SRCS_SUB))

# Make all.
all: $(NAME)

# Make debug
debug: $(DEB_NAME)

# Remove the objects and dependencies files.
clean:
	$(RM) build

# Remove the object, dependencies and executables files.
fclean:
	$(RM) build $(NAME) $(DEB_NAME)

# Clean and rebuild the executable.
re: | fclean
	@$(MAKE) all

# Clean and rebuild the debug executable.
redebug: | fclean
	@$(MAKE) debug

# Include dependencies for objects.
-include $(DEPS)
-include $(DEB_DEPS)
