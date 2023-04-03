NAME			= PmergeMe
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SRC_FILES		=  main.cpp PmergeMe.cpp
OBJ_FILES		= $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o)))
NUM_INTS		= 100

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@$(CXX) $(CPPFLAGS) -o $@ $^ 

obj/%.o : %.cpp  obj
	@$(CXX) $(CPPFLAGS) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)
	@rm -f rand_ints.txt

re : clean all

rand : $(NAME)
	@make
	@echo "Generating $(NUM_INTS) random non-unique integers..."
	@jot -r 300 1 $(NUM_INTS) | tr '\n' ' ' > rand_ints.txt
	@echo "Running $(NAME) with random $(NUM_INTS) integers..."
	@./$(NAME) `cat rand_ints.txt`

.PHONY : all clean fclean re
