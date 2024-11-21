/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:01:28 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/21 17:02:23 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"


int main(int argc, char** argv)
{
    if (argc != 2)
	{
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    bool error = false;

    int result = evaluateRPN(expression, error);

    if (error)
	{
        std::cout << "Error" << std::endl;
    }
	else
	{
        std::cout << result << std::endl;
    }

    return 0;
}