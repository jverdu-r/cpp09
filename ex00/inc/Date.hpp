/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:37:12 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/20 15:32:38 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

class Date
{
    private:
        int _day;
        int _month;
        int _year;
        const static int _dpm[12];

    public:
        Date(void);
        ~Date(void);
        Date(const Date &origin);
        Date(const std::string& date);
        Date &operator=(const Date &origin);
        bool operator<(const Date &origin) const;
        bool operator==(const Date &origin) const;
        bool validDate(void);
        int getDay(void) const;
        int getMonth(void) const;
        int getYear(void) const;

         class InvalidDate : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("ERROR: Invalid date");
            }
        };
};

std::ostream &operator<<(std::ostream &o, const Date &prt);

#endif