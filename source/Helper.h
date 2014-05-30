/*!
 * \file   Helper.h
 * \date   10 September 2011
 * \author StefanP.MUC
 * \brief  Provides helper functions, constants and defines
 *
 *  Copyright (C) 2011-2014  OpenDungeons Team
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HELPER_H_
#define HELPER_H_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

//! \brief Math constant pi. Always use this one, never M_PI from <cmath> (it's not portable)
const double PI = 3.141592653589793238462643;

//! \brief Helper namespace that contains globals that really don't fit in any better context
namespace Helper
{
    /*! \brief Converts a string to a primitive type T
     *
     *  \param str The string to be converted
     *  \return The converted primitive number
     */
    template<typename T>
    T stringToT(const std::string& str)
    {
        std::istringstream stream(str);
        T t = 0;
        stream >> t;
        return t;
    }

    /*! \brief Checks if a string contains primitive type T
     *
     *  \param str The string to be checked
     *  \return true if string contains type T, else false
     */
    template<typename T>
    bool checkIfT(const std::string& str)
    {
        std::istringstream stream(str);
        T t = 0;
        return (stream >> t);
    }

    static std::vector<std::string> split(const std::string& line, char delimiter)
    {
        //std::cout << line << std::endl;
        std::stringstream ss(line);
        std::vector<std::string> elems;
        std::string item;
        while (std::getline(ss, item, '\t'))
        {
            elems.push_back(item);
            //std::cout << item << std::endl;
        }
        return elems;
    }

    static int toInt(const std::string& text)
    {
        std::stringstream ss(text);
        int number = 0;
        ss >> number;
        return number;
    }

    static double toDouble(const std::string& text)
    {
        std::stringstream ss(text);
        double number = 0.0;
        ss >> number;
        return number;
    }

    // Needed on MSVC <2012
    // http://social.msdn.microsoft.com/Forums/vstudio/en-US/260e04fc-dd05-4a96-8953-9c6ea1ad62fb/cant-find-stdround-in-cmath?forum=vclanguage
    static int round(double d)
    {
        return static_cast<int>(d + 0.5);
    }
}

#endif // HELPER_H_
