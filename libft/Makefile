# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 16:45:22 by jhamon            #+#    #+#              #
#    Updated: 2018/05/20 00:51:46 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AUTEUR = jhamon

CC = gcc

FLAG = -Wall -Werror -Wextra
G3 = -fsanitize=address -g3

OBJ = $(SRC:.c=.o)
SRC = 	get_next_line.c	ft_memalloc.c 	ft_memdel.c 	ft_strnew.c 	ft_strdel.c \
		ft_strclr.c 	ft_striter.c 	ft_striteri.c 	ft_strmap.c 	ft_strmapi.c \
		ft_strequ.c 	ft_strnequ.c 	ft_strsub.c 	ft_strjoin.c 	ft_strtrim.c \
		ft_strsplit.c 	ft_itoa.c		ft_putchar.c 	ft_putstr.c 	ft_putendl.c \
		ft_putnbr.c 	ft_putchar_fd.c ft_putstr_fd.c 	ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atoi.c 		ft_isdigit.c 	ft_memcpy.c 	ft_strcmp.c 	ft_strncat.c \
		ft_strstr.c 	ft_bzero.c 		ft_isprint.c 	ft_memmove.c 	ft_strcpy.c \
		ft_strncmp.c 	ft_tolower.c 	ft_isalnum.c 	ft_memccpy.c 	ft_memset.c \
		ft_strdup.c 	ft_strncpy.c 	ft_toupper.c 	ft_isalpha.c 	ft_memchr.c \
		ft_strcat.c 	ft_strlcat.c 	ft_strnstr.c 	ft_isascii.c 	ft_memcmp.c \
		ft_strchr.c 	ft_strlen.c 	ft_strrchr.c 	ft_printf_s.c 	ft_memdel_zero.c\
		ft_printf_c.c 	ft_printf_ss.c 	ft_itoa_base.c 	ft_printf_cc.c 	ft_printf_u.c \
		ft_strlen_ptf.c	ft_atoi_ptf.c 	ft_printf_i.c 	ft_printf_x.c 	ft_care_is_me.c \
		ft_printf_o.c 	ft_printparms.c ft_strsub.c 	ft_charcmp.c 	ft_printf.c \
		ft_printf_p.c 	ft_put_wchar.c 	ft_strupper.c 	ft_charnumb.c 	ft_printf_pc.c \
		ft_resetprset.c	ft_color.c 		ft_printf_b.c 	ft_memdel_zero.c ft_strchr_int.c \

# Utile
_END=tput sgr0
_BOLD=tput bold
_UNDER=tput smul
_REV=tput smso
_DAFUK=tput smacs

# Colors
_GREY=tput setaf 250
_RED=tput setaf 160
_GREEN=tput setaf 10
_YELLOW=tput setaf 11
_BLUE=tput setaf 27
_PURPLE=tput setaf 92
_CYAN=tput setaf 50
_WHITE=tput setaf 255

# Inverted
_IGREY=tput setab 250
_IRED=tput setab 160
_IGREEN=tput setab 10
_IYELLOW=tput setab 11
_IBLUE=tput setab 27
_IPURPLE=tput setab 92
_ICYAN=tput setab 50
_IWHITE=tput setab 255

define OK
	@$(call _GREEN) && printf "[Ok]	"
	@$(call _UNDER)
	@$(call _YELLOW) && printf "$1\n"
	@$(call _END)
endef

define FOK
	@$(call _GREEN) && printf "\n[Compiled]	"
	@$(call _CYAN) && printf "$(NAME)\n"
	@$(call _END)
endef

define CLNOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "$1\n"
	@$(call _END)
endef

define CLNOBJOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "Obj_$(NAME)\n"
	@$(call _END)
endef

define BULSHIT
	@$(call _PURPLE) && printf "auteur :	"
	@$(call _RED) && printf "$(AUTEUR)\n"
	@$(call _END)
endef

all : $(NAME)
	@:

$(NAME) : $(OBJ)
	@$(CC) -c $(SRC) $(FLAG)
	@ar -rc $(NAME) $(OBJ)
	@make auteur
	$(call FOK)

%.o: %.c
	@$(CC) -c $(FLAG) $< -o $@
	$(call OK,$*)

clean :
	@rm -rf $(OBJ)
	$(call CLNOBJOK,$(OBJ))

fclean : clean
	@rm -rf $(NAME) auteur
	$(call CLNOK,$(NAME))

re : fclean all

force :
	@$(CC) -c $(SRC)
	@ar -rc $(NAME) $(OBJ)

debug : $(OBJ)
	@$(CC) -c $(SRC) $(G3)
	@ar -rc $(NAME) $(OBJ)

auteur :
	@touch $@ && echo $(AUTEUR) > $@
	$(call BULSHIT,$(AUTEUR))

norme :
	@norminette $(SRC)

.PHONY : all clean fclean re force debug auteur
