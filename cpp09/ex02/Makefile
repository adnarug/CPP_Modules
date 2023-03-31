NAME			= PmergeMe
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -std=c++98 #-WERRRO!!!
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
	@awk 'BEGIN { srand(); for (i=1; i<=$(NUM_INTS); i++) printf("%d\n", int(1 + rand() * (50 - 1 + 1 ))); }' > rand_ints.txt
	@echo "Running $(NAME) with random integers..."
	@./$(NAME) `cat rand_ints.txt`

.PHONY : all clean fclean re
