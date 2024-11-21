/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:02:49 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/21 18:05:30 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"


int main(int argc, char** argv)
{
    if (argc < 2)
	{
        std::cout << "Error: Provide a sequence of positive integers." << std::endl;
        return 1;
    }

    // Parse the input integers
    std::vector<int> vecSequence;
    std::deque<int> deqSequence;
    try
	{
        for (int i = 1; i < argc; ++i)
		{
            int num = std::atoi(argv[i]);
            if (num <= 0) throw std::invalid_argument("Non-positive integer");
            vecSequence.push_back(num);
            deqSequence.push_back(num);
        }
    }
	catch (const std::exception&)
	{
        std::cout << "Error: Invalid input." << std::endl;
        return 1;
    }

    // Display the original sequence
    std::cout << "Original sequence: ";
    for (size_t i = 0; i < vecSequence.size(); ++i)
        std::cout << vecSequence[i] << " ";
    std::cout << std::endl;

    // Sort using `std::vector`
    clock_t startVec = clock();
    fordJohnsonSortVector(vecSequence);
    clock_t endVec = clock();

    // Display the sorted sequence
    std::cout << "Sorted sequence with vector: ";
    for (size_t i = 0; i < vecSequence.size(); ++i)
        std::cout << vecSequence[i] << " ";
    std::cout << std::endl;

    // Sort using `std::deque`
    clock_t startDeq = clock();
    fordJohnsonSortDeque(deqSequence);
    clock_t endDeq = clock();

    // Display the sorted sequence
    std::cout << "Sorted sequence with deque: ";
    for (size_t i = 0; i < deqSequence.size(); ++i)
        std::cout << deqSequence[i] << " ";
    std::cout << std::endl;

    // Display timing results
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;
    std::cout << "Time taken by vector: " << timeVec << " seconds" << std::endl;
    std::cout << "Time taken by deque: " << timeDeq << " seconds" << std::endl;

    return 0;
}