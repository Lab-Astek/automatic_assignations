//
// Created by Esteban on 14/01/2020.
//

#pragma once

#include <string>
#include <stdexcept>
#include "utils/Types.hpp"

class Date {
    utils::Month _month;
    utils::Day _day;
    utils::TimeOfDay _tod;

public:
    Date(const std::string &day, const std::string &month, const std::string &timeOfDay) :
    _month(utils::stringToMonth(month)), _day(utils::stringToDay(day)), _tod(utils::stringToTimeOfDay(timeOfDay))
    {
        if (_day == utils::Day::Unknown
        || _tod == utils::TimeOfDay::Unknown)
            throw std::runtime_error("Invalid Date");
    }
    Date() = default;
    ~Date() = default;

    utils::Day getDay() const { return _day; }
    std::string getTimeOfDay() const {
        if (_tod == utils::TimeOfDay::AM) return "AM";
        return "PM";
    }

    bool operator==(const Date &d) const {
        return d._day == _day && d._tod == _tod;
    }
};