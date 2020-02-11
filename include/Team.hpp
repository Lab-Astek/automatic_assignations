//
// Created by Esteban on 14/01/2020.
//

#pragma once

#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include "Astek.hpp"
#include "Planning.hpp"

class Team {
private:
    std::unordered_map<std::string, Astek> _members;
    bool _assignAllDay = true;


    void computeAllAssignableActivities(const Planning &planning);
    void setPercentagesForAll(const Planning &planning);
    void parseFile(std::ifstream &in, char delimitor, const std::function<void(Astek &, const std::string &)> &f);
    void openAndFetch(const std::string &file, char delimitor, const std::function<void(Astek &, const std::string &)> &f);
public:
    explicit Team(const std::string &fileName);
    ~Team() = default;

    void fetchAvailabities(const std::string &file);
    void fetchPreferences(const std::string &file);
    void fetchToAvoid(const std::string &file);
    void doTheThing(Planning &planning);
    void assignAllDay(bool value) { _assignAllDay = value; }
};