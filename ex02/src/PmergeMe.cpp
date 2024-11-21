/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:00:40 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/21 18:15:29 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

void fordJohnsonSortVector(std::vector<int>& sequence)
{
    if (sequence.size() <= 1) return;

    // Divide the input into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < sequence.size(); i += 2)
	{
        if (sequence[i] > sequence[i + 1])
            pairs.push_back(std::make_pair(sequence[i + 1], sequence[i]));
        else
            pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
    }

    // Push the leftover element if odd-sized sequence
    std::vector<int> singletons;
    if (sequence.size() % 2 != 0)
        singletons.push_back(sequence.back());

    // Extract the "larger" elements from each pair and sort them
    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].second);

    std::sort(larger.begin(), larger.end());

    // Merge the "smaller" elements with the sorted "larger" elements
    std::vector<int> smaller;
    for (size_t i = 0; i < pairs.size(); ++i)
        smaller.push_back(pairs[i].first);

    std::vector<int> merged;
    merged.insert(merged.end(), larger.begin(), larger.end());

    // Insert smaller elements and singletons into their correct positions
    for (size_t i = 0; i < smaller.size(); ++i)
	{
        std::vector<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), smaller[i]);
        merged.insert(pos, smaller[i]);
    }
    for (size_t i = 0; i < singletons.size(); ++i)
	{
        std::vector<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), singletons[i]);
        merged.insert(pos, singletons[i]);
    }

    // Copy the sorted result back into the original sequence
    sequence = merged;
}

void fordJohnsonSortDeque(std::deque<int>& sequence)
{
    if (sequence.size() <= 1) return;

    // Divide the input into pairs and sort each pair
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < sequence.size(); i += 2)
	{
        if (sequence[i] > sequence[i + 1])
            pairs.push_back(std::make_pair(sequence[i + 1], sequence[i]));
        else
            pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
    }

    // Push the leftover element if odd-sized sequence
    std::deque<int> singletons;
    if (sequence.size() % 2 != 0)
        singletons.push_back(sequence.back());

    // Extract the "larger" elements from each pair and sort them
    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].second);

    std::sort(larger.begin(), larger.end());

    // Merge the "smaller" elements with the sorted "larger" elements
    std::deque<int> smaller;
    for (size_t i = 0; i < pairs.size(); ++i)
        smaller.push_back(pairs[i].first);

    std::deque<int> merged;
    merged.insert(merged.end(), larger.begin(), larger.end());

    // Insert smaller elements and singletons into their correct positions
    for (size_t i = 0; i < smaller.size(); ++i)
	{
        std::deque<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), smaller[i]);
        merged.insert(pos, smaller[i]);
    }
    for (size_t i = 0; i < singletons.size(); ++i)
	{
        std::deque<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), singletons[i]);
        merged.insert(pos, singletons[i]);
    }

    // Copy the sorted result back into the original sequence
    sequence = merged;
}