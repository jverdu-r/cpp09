/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:49:54 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/20 15:32:54 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Date.hpp"

const int Date::_dpm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(void): _day(0), _month(0), _year(0) {}

Date::~Date(void){}

Date::Date(const Date &origin)
{
	*this = origin;
}

Date::Date(const std::string& date)
{
	std::string sday, smonth, syear;

	if (date.length() != 10)
		throw InvalidDate();
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw InvalidDate();
		}
		else if (!isdigit(date[i]))
			throw InvalidDate();
	}
	this->_year = atoi(date.substr(0, 4).c_str());
	this->_month = atoi(date.substr(5, 2).c_str());
	this->_day = atoi(date.substr(8, 2).c_str());
	if (!validDate())
		throw InvalidDate();
}

Date& Date::operator=(const Date &origin)
{
	this->_day = origin._day;
	this->_month = origin._month;
	this->_year = origin._year;
	return (*this);
}

bool Date::operator<(const Date &origin) const
{
	if (this->_year > origin._year)
		return (true);
	if (this->_year < origin._year)
		return (false);
	if (this->_month > origin._month)
		return (true);
	if (this->_month < origin._month)
		return (false);
	if (this->_day > origin._day)
		return (true);
	return (false);
}

bool Date::operator==(const Date &origin) const
{
	return (this->_day == origin._day && this->_month == origin._month && this->_year == origin._year);
}

bool Date::validDate(void)
{
	if (this->_day == 0 || this->_month > 12 || this->_year == 0)
		return (false);
	if (this->_month == 2 && this->_year % 4 == 0)
	{
		if (this->_day > 29)
			return (false);
		else
			return (true);
	}
	if (this->_dpm[this->_month - 1] < this->_day)
		return (false);
	return (true);
}

int Date::getDay(void) const
{
	return (this->_day);
}
int Date::getMonth(void) const
{
	return (this->_month);
}
int Date::getYear(void) const
{
	return (this->_year);
}

std::ostream &operator<<(std::ostream &o, const Date &prt)
{
	o << prt.getDay() << '-' << prt.getMonth() << '-' << prt.getYear();
	return (o);
}