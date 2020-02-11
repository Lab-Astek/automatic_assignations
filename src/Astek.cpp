//
// Created by Esteban on 22/01/2020.
//

#include <algorithm>
#include "Astek.hpp"
#include "utils/console.hpp"

static void fetchModules(const std::string &str, std::vector<utils::Modules> &vec) {
    std::size_t pos = 0;
    std::size_t old;
    std::string module;
    bool isGood = true;

    while (isGood) {
        old = pos;
        pos = str.find(',', pos);
        module = str.substr(old, pos);
        vec.push_back(utils::stringToModules(module));
        if (pos == std::string::npos)
            isGood = false;
        pos += 1;
    }
}

void Astek::setPreferences(const std::string &str) {
    stb::log << stb::info << "\tSet preferences" << stb::endl;
    fetchModules(str, _preferences);
}

void Astek::setToAvoid(const std::string &str) {
    stb::log << stb::info << "\tSet to avoid" << stb::endl;
    fetchModules(str, _toAvoid);
}

void Astek::computeAssignableActivities(const std::vector<Activity> &activities) {
    for (const auto &activity: activities) {
        const auto &date = activity.getDate();
        if (isAvailable(date))
            ++_assignableActivities;
    }
}

bool Astek::isAvailable(const Date &d) const {
    const auto &availabilities = _av.getAvailabilities();

    for (const auto &availability: availabilities) {
        if (availability.d == d)
            return availability.available;
    }
    return false;
}

double Astek::calculateMultiplier(const Activity &activity) const {
    if (std::find(_preferences.cbegin(), _preferences.cend(), activity.getModule()) != _preferences.cend())
        return 1.5;
    if (std::find(_toAvoid. cbegin(), _toAvoid.cend(), activity.getModule()) != _toAvoid.cend())
        return 0.5;
    return 1;
}

void Astek::setPercentages(const Planning &planning) {
    _percentages.clear();
    for (const auto &activity: planning.getActivities()) {
        if (isAvailable(activity.getDate()) && _assignableActivities != 0) {
            auto multiplier = calculateMultiplier(activity);
            auto perc = 20.0 / _assignableActivities * _leftAssignations * multiplier;
            _percentages[activity.toString()] = perc;
        }
        else
            _percentages[activity.toString()] = 0.0;
    }
}