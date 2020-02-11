//
// Created by Esteban on 21/01/2020.
//

#include <utils/console.hpp>
#include "Availability.hpp"

Availabilities::Availabilities() {
    int i = 0;
    int j = 0;

    while (i < 10) {
        Availability a{};
        a.available = true;
        a.d = Date(_assocDays.at(j), "", i % 2 == 0 ? "AM" : "PM");
        _availabilities.push_back(a);
        if (i % 2 == 1) j++;
        i++;
    }
}

void Availabilities::changeAvailability(const std::string &day, const std::string &timeOfday) {
    int idx = _assocDaysToId.at(day);
    if (timeOfday.find("Après-midi") != std::string::npos) idx += 1;
    auto &a = getAvailability(idx);
    a.available = false;
    stb::log << "\tNot available on " << day << " " << timeOfday << stb::endl;
}

void Availabilities::changeAvailability(utils::Day day, const std::string &timeOfday) {
    int idx = _assocDaysToId.at(utils::dayToString(day));
    if (timeOfday == "PM")
        idx++;
    auto &a = getAvailability(idx);
    a.available = false;
}

void Availabilities::setAvailabilities(const std::string &str) {
    std::size_t pos = (str[0] == '\"' ? 1 : 0);
    std::size_t stop = 0;

    while ((stop = str.find(',', pos)) != std::string::npos) {
        std::string sub = str.substr(pos, stop - pos);
        std::size_t space = sub.find(' ');
        std::string day = sub.substr(0, space);
        std::string timeOfDay = sub.substr(space + 1, stop - space);
        changeAvailability(day, timeOfDay);

        pos = stop + 2;
    }
    parseLine(str, pos, stop);
}

void Availabilities::parseLine(const std::string &str, size_t pos, size_t stop) {
    std::string sub = str.substr(pos, stop - 1);
    std::size_t space = sub.find(' ');
    std::string day = sub.substr(0, space);
    std::string timeOfDay = sub.substr(space + 1);
    changeAvailability(day, timeOfDay);
}
