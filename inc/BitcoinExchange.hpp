/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:34 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/19 15:49:25 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCINEXCHANGE_HPP
#define BITCINEXCHANGE_HPP

#include <iostream>
#include <map>
#include "Date.hpp"

#define DATAFILE "data.csv"

class BitcoinExchange
{
    private:
        std::map<Date, float> dataBase;

    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &origin);
        BitcoinExchange &operator=(const BitcoinExchange &origin);
        float searchDate(Date date) const;

        class CannotOpenData : public std:exception
        {
            virtual const char* what() const throw()
            {
                return ("ERROR: Cannot open data file");
            }
        };

        class DateTooEarly : public std:exception
        {
            virtual const char* what() const throw()
            {
                return ("ERROR: Date too early");
            }
        };

}