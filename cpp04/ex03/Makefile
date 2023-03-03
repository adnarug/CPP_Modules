NAME			= game
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -g -std=c++98 -MD -fsanitize=address#-Werror
SRC_FILES		= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJ_FILES		= $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o)))

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@$(CXX) $(CPPFLAGS) -o $@ $^ 

obj/%.o : %.cpp  obj
	@$(CXX) $(CPPFLAGS) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj

run:
	@make
	@./$(NAME)

fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
