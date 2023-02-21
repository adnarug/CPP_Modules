#!/bin/bash

# Prompt for program name, number of classes, and class names
read -p "Enter the program name: " program_name
read -p "Enter the number of classes: " num_classes
for ((i=1;i<=num_classes;i++)); do
    read -p "Enter the name of class $i: " class_name
    class_names+=($class_name)
done

# Create Makefile
cat << EOF > Makefile
NAME			= $program_name
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -MD
SRC_FILES		= $(echo "${class_names[@]/%/.cpp}" | tr ' ' '\n') main.cpp
OBJ_FILES		= \$(addprefix obj/,\$(notdir \$(SRC_FILES:.cpp=.o)))

all : \$(NAME)

\$(NAME) : \$(OBJ_FILES)
	@\$(CXX) \$(CPPFLAGS) -o \$@ \$^ 

obj/%.o : %.cpp  obj
	@\$(CXX) \$(CPPFLAGS) -c \$< -o \$@

obj :
	@mkdir obj

clean :
	@rm -rf obj

log:
	@make
	@./\$(NAME) > my_log

fclean : clean
	@rm -f \$(NAME)
	@rm -f my_log

re : clean all

.PHONY : all clean fclean re
EOF

# Create .cpp and .hpp files
for class_name in "${class_names[@]}"; do
    # Create .hpp file
    cat << EOF > $class_name.hpp
#ifndef ${class_name_HPP}_HPP
# define ${class_name_HPP}_HPP

# include <iostream>
# include <string>

class $class_name {
public:
    $class_name();
    ~$class_name();
};

#endif
EOF

    # Create .cpp file
    cat << EOF > $class_name.cpp
#include "$class_name.hpp"

$class_name::$class_name() {
}

$class_name::~$class_name() {
}
EOF
done

# Create main.cpp
cat << EOF > main.cpp
#include "${class_names[0]}.hpp"

int main() {
    // TODO: Write code here
    return 0;
}
EOF

echo "Done!"
