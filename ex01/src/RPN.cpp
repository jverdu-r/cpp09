/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:59:24 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/21 17:08:38 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"




int evaluateRPN(const std::string& expression, bool& error)
{
    int stack[MAX_STACK_SIZE];
    int top = -1;
    std::istringstream tokens(expression);
    std::string token;

    error = false;

    while (tokens >> token) {
        if (token.length() == 1 && std::isdigit(token[0]))
		{
            if (top + 1 >= MAX_STACK_SIZE)
			{
                error = true;
                return 0;
            }
            stack[++top] = std::atoi(token.c_str());
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
            if (top < 1)
			{
                error = true;
                return 0;
            }

            int b = stack[top--];
            int a = stack[top--];
            int result = 0;

            if (token == "+")
			{
                result = a + b;
            } else if (token == "-")
			{
                result = a - b;
            } else if (token == "*")
			{
                result = a * b;
            } else if (token == "/")
			{
                if (b == 0)
				{
                    error = true;
                    return 0;
                }
                result = a / b;
            }

            stack[++top] = result;
        }
		else
		{
            error = true;
            return 0;
        }
    }

    if (top != 0)
	{
        error = true;
        return 0;
    }

    return stack[top];
}