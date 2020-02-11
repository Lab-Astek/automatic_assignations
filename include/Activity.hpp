//
// Created by Esteban on 14/01/2020.
//

#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include "Date.hpp"
#include "utils/Types.hpp"

class Astek;

class Activity {
private:
    std::string                 _project;
    utils::Activity             _activity;
    utils::Modules              _module;
    utils::Location             _location;
    unsigned int                _needAstek;
    std::vector<std::string>    _assignedAsteks;
    Date                        _date;

public:
    Activity(const std::string &activity, const std::string &project, const std::string &module, const std::string &location, int nbAstek);
    ~Activity() = default;

    void assignAsteks(std::unordered_map<std::string, Astek> &asteks);
    void assignSameAsteks(const Activity &act, std::unordered_map<std::string, Astek> &asteks);

    /*
     * SETTERS
     */
    void setDate(const Date &d) { _date = d; }

    /*
     * GETTERS
     */
    const Date &getDate() const { return _date; }
    utils::Modules getModule() const { return _module; }
    const std::vector<std::string> &getAssignedAsteks() const { return _assignedAsteks; }

    /*
     * UTILS
     */
    bool operator==(const Activity &other) const {
        return isSameActivity(other) && _date.getTimeOfDay() == other._date.getTimeOfDay();
    }
    bool operator!=(const Activity &other) const {
        return !operator==(other);
    }
    bool isSameActivity(const Activity &other) const {
        return _project == other._project && _activity == other._activity && _location == other._location && _date.getDay() == other._date.getDay();
    }
    std::string toString() const {
        return utils::activityToString(_activity) + "_" + _project + "_" + utils::locationToString(_location) + "_" + utils::dayToString(_date.getDay()) + "_" + _date.getTimeOfDay();
    }
};