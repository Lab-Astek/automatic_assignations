//
// Created by Esteban on 15/01/2020.
//

#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include "Date.hpp"

class Availabilities {
public:
    struct Availability {
        Date d;
        bool available;
    };

private:
    std::vector<Availability> _availabilities;

    const std::unordered_map<int, std::string> _assocDays = {
            {0, "Mon"},
            {1, "Tue"},
            {2, "Wed"},
            {3, "Thu"},
            {4, "Fri"},
            {5, "Sat"},
            {6, "Sun"}
    };

    const std::unordered_map<std::string, int> _assocDaysToId = {
            {"Lundi", 0},
            {"Mardi", 2},
            {"Mercredi", 4},
            {"Jeudi", 6},
            {"Vendredi", 8}
    };


public:
    Availabilities();
    ~Availabilities() = default;

    void changeAvailability(const std::string &day, const std::string &timeOfDay);
    void changeAvailability(utils::Day day, const std::string &timeOfDay);
    void parseLine(const std::string &str, size_t pos, size_t stop);

    /*
     * SETTERS
     */
    void setAvailabilities(const std::string &str);

    /*
     * GETTERS
     */
    const std::vector<Availabilities::Availability> &getAvailabilities() const { return _availabilities; }
    Availability &getAvailability(int idx) { return _availabilities[idx]; }
};