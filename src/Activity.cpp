//
// Created by Esteban on 23/01/2020.
//

#include <algorithm>
#include <random>
#include "Activity.hpp"
#include "Astek.hpp"
#include "AstekPercentage.hpp"

Activity::Activity(const std::string &activity, const std::string &project, const std::string &module, const std::string &location, int nbAstek) :
        _project(project), _activity(utils::stringToActivity(activity)), _module(utils::stringToModules(module)),
        _location(utils::stringToLocation(location)), _needAstek(nbAstek), _date()
{
    if (_activity == utils::Activity::Unknown
        || _module == utils::Modules::Unknown
        || _location == utils::Location::Unknown
        || _needAstek <= 0)
        throw std::runtime_error("Invalid activity");
    stb::log << stb::info << "New activity -> " + activity + " for " + project + " in " + location << stb::endl;
}

void Activity::assignAsteks(std::unordered_map<std::string, Astek> &asteks) {
    std::vector<AstekPercentage> toAdd;
    std::string name = toString();

    for (auto &astek: asteks) {
        toAdd.emplace_back(astek.first, astek.second.getPercentageForActivity(name));
    }
    std::shuffle(toAdd.begin(), toAdd.end(), std::mt19937{ std::random_device{}() });
    std::sort(toAdd.begin(), toAdd.end(),
              [](const AstekPercentage &a, const AstekPercentage &b){ return a.percentage > b.percentage; });
    for (auto i = 0u; i < _needAstek && toAdd[i].percentage > 0; ++i) {
        auto astek = asteks.find(toAdd[i].name);
        if (astek != asteks.end())
            astek->second.assign(this);
        _assignedAsteks.push_back(toAdd[i].name);
    }
    _needAstek = 0;
}

void Activity::assignSameAsteks(const Activity &other, std::unordered_map<std::string, Astek> &asteks) {
    auto &assignedAsteks = other.getAssignedAsteks();
    auto name = this->toString();

    if (_needAstek == 0)
        return;
    for (const auto &e: assignedAsteks) {
        auto perc = asteks[e].getPercentageForActivity(name);
        if (perc > 0) {
            _assignedAsteks.push_back(e);
            --_needAstek;
            asteks[e].assign(this);
        }
    }
}