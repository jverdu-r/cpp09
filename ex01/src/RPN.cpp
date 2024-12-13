/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:59:24 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/12/13 15:05:00 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"



int evaluateRPN(const std::string& expression, bool& error)
{
    std::stack<int> stack;
    std::istringstream tokens(expression);
    std::string token;

    error = false;

    while (tokens >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            stack.push(std::atoi(token.c_str()));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                error = true;
                return 0;
            }

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = 0;

            if (token == "+") {
                result = a + b;
            } else if (token == "-") {
                result = a - b;
            } else if (token == "*") {
                result = a * b;
            } else if (token == "/") {
                if (b == 0) {
                    error = true;
                    return 0;
                }
                result = a / b;
            }

            stack.push(result);
        } else {
            error = true;
            return 0;
        }
    }

    if (stack.size() != 1) {
        error = true;
        return 0;
    }

    return stack.top();
}
