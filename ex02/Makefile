# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 16:22:46 by omoreno-          #+#    #+#              #
#    Updated: 2023/10/04 18:04:36 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= test

MAINSRC		:=	main.cpp Functions.cpp

BUILD_PATH	:= .build/
HEADER		:= Base.hpp A.hpp B.hpp C.hpp

MAINOBJ		:= $(addprefix $(BUILD_PATH), $(MAINSRC:.cpp=.o))
CLASSOBJ	:= $(addprefix $(BUILD_PATH), $(CLASSSRC:.cpp=.o))
MAINDEPS	:= $(addprefix $(BUILD_PATH), $(MAINSRC:.cpp=.d))
CLASSDEPS	:= $(addprefix $(BUILD_PATH), $(CLASSSRC:.cpp=.d))

CC			:=	@c++
RM			:=	@rm -Rf
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98

folder_create 	= $(shell mkdir -p $(1))

.SECONDEXPANSION:


$(BUILD_PATH)%.o : %.cpp ${HEADER} Makefile | $$(call folder_create,$$(dir $$@))
	@echo "Compiling" $@
	${CC} ${CFLAGS} -c -I. $< -o $@

all : $(NAME)

$(NAME) : ${MAINOBJ} ${HEADER} Makefile
	@echo "Linking" $@
	${CC} ${CFLAGS} ${MAINOBJ} -o $@

clean :
	@echo "Cleaning $(BUILD_PATH) ..."
	$(RM) $(BUILD_PATH)

fclean : clean
	$(RM) $(NAME)
	@echo "Cleaned executable"

re: fclean all

.PHONY : clean fclean re all