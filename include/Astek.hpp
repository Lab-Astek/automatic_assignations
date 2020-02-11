//
// Created by Esteban on 14/01/2020.
//

#pragma once

#include <string>
#include <unordered_map>
#include "Availability.hpp"
#include "Activity.hpp"
#include "Planning.hpp"

class Astek {
private:
    std::string _name;
    int _totalAssignations;
    int _leftAssignations;
    int _assignableActivities = 0;
    Availabilities _av;
    std::unordered_map<std::string, double> _percentages;
    std::vector<const Activity *> _assignations;
    std::vector<utils::Modules> _preferences;
    std::vector<utils::Modules> _toAvoid;

    bool isAvailable(const Date &d) const;
    double calculateMultiplier(const Activity &activity) const;

public:
    Astek(const std::string &name, int nbAssignations) : _name(name), _totalAssignations(nbAssignations), _leftAssignations(nbAssignations) {}
    Astek(const Astek &other): _name(other.getName()), _totalAssignations(other.getTotalAssignations()), _leftAssignations(other.getTotalAssignations()) {}
    Astek() = default;
    ~Astek() = default;

    void computeAssignableActivities(const std::vector<Activity> &activities);
    void setPercentages(const Planning &planning);
    void assign(const Activity *act) {
        _av.changeAvailability(act->getDate().getDay(), act->getDate().getTimeOfDay());
        _assignations.push_back(act);
        _leftAssignations--;
    }

    /*
     * SETTERS
     */
    void setAvailabilities(const std::string &str) { _av.setAvailabilities(str); }
    void setPreferences(const std::string &str);
    void setToAvoid(const std::string &str);

    /*
     * GETTERS
     */
    int getTotalAssignations() const { return _totalAssignations; }
    const std::string &getName() const { return _name; }
    double getPercentageForActivity(const std::string &str) {
        if (_percentages.find(str) == _percentages.end())
            return -1;
        return _percentages[str];
    }
};