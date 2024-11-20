/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:53:10 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/20 16:01:30 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream file(DATAFILE);
	std::string line;
	std::string value;
	Date auxDate;
	float auxValue;

	if (!file.is_open())
		throw (CannotOpenDataFile());
	std::getline(file, line);
	while (!file.eof())
	{
		std::getline(file, line);
		if (line == "")
			break;
		auxDate = Date(line.substr(0, line.find_first_of(',')));
		value = line.substr(0, line.find_first_of(',') + 1);
		auxValue = atof(value.c_str());
		this->_dataBase[auxDate] = auxValue;
	}
}
BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &origin)
{
	*this = origin;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &origin)
{
	this->_dataBase = origin._dataBase;
	return (*this);
}
float BitcoinExchange::searchDate(Date date) const
{
	if (this->_dataBase.lower_bound(date) == this->_dataBase.end())
		throw (DateTooEarly());
	return (this->_dataBase.lower_bound(date))->second;
}