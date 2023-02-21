/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 16:08:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	
	if (argc != 4)
	{
		std::cerr<<"Error\nWrong parameters"<<std::endl;
		return (EXIT_FAILURE);
	}
	
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::ifstream	ifs(filename);
	std::ofstream	ofs(filename.append(".replace"));
	size_t			pos;
	std::string		line;

	if (ifs >> std::ws && ifs.peek() == EOF)
	{
		std::cerr<<"Error\nEmpty input file"<<std::endl;
		return (EXIT_FAILURE);
	}
	if (s1 == s2)
		std::cout<<"Warning\nIdentical s1 and s2"<<std::endl;
	if (ifs.is_open() && ifs.good() && ofs.good())
	{
		while (getline (ifs, line))
		{
			pos = line.find(s1);
			if (pos != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
			}
			ofs << line << '\n';
		}
		ifs.close();
		ofs.close();
	}
	else 
		std::cerr << "Error\nUnable to open the file" <<std::endl;
	return 0;
}
