NAME			= sed_for_losers
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -MD
SRC_FILES		=  main.cpp
OBJ_FILES		= $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o)))

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@$(CXX) $(CPPFLAGS) -o $@ $^ 
	@echo "sed_for_losers is compiled"

obj/%.o : %.cpp  obj
	@$(CXX) $(CPPFLAGS) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj

run:
	@make
	@./$(NAME) Makefile FILES JOKES

fclean : clean
	@rm -f $(NAME)
	@rm -f *.replace

re : clean all

.PHONY : all clean fclean re
