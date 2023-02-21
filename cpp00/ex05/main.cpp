/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:40:54 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 16:14:45 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	// harl.complain("DEBUG");
	// harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("STRANGE");
	return 0;
}
