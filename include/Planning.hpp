//
// Created by Esteban on 15/01/2020.
//

#pragma once

#include <string>
#include <vector>
#include "utils/console.hpp"
#include "Activity.hpp"

class Planning {
private:
    std::vector<Activity> _activities;

    void fetchPlanning(const std::string &file);
public:
    explicit Planning(const std::string &file);
    ~Planning() = default;

    std::vector<Activity> &getActivities() { return _activities; }
    const std::vector<Activity> &getActivities() const { return _activities; }
    Activity *getSameDayActivity(const Activity &activity);
    void display() const;
};