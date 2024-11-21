/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:00:18 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/21 18:03:36 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

// Sort a sequence of integers using Ford-Johnson algorithm with `std::vector`
void fordJohnsonSortVector(std::vector<int>& sequence);

// Sort a sequence of integers using Ford-Johnson algorithm with `std::deque`
void fordJohnsonSortDeque(std::deque<int>& sequence);

#endif // PMERGEME_HPP
