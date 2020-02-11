//
// Created by Esteban on 07/02/2020.
//

#include <fstream>
#include "Planning.hpp"

Planning::Planning(const std::string &file) {
    fetchPlanning(file);
}

void Planning::fetchPlanning(const std::string &file) {
    std::ifstream in(file);
    std::string activity;
    std::string project;
    std::string module;
    std::string month;
    std::string day;
    std::string timeOfDay;
    int nbAsteks;
    std::string room;

    while (in >> activity >> project >> module >> day >> month >> timeOfDay >> nbAsteks >> room) {
        try {
            Activity a(activity, project, module, room, nbAsteks);
            Date d(day, month, timeOfDay);
            a.setDate(d);
            _activities.push_back(a);
        }
        catch (const std::exception &e) {
            stb::log << stb::error << e.what() << stb::endl;
            exit(84);
        }

    }
}

Activity *Planning::getSameDayActivity(const Activity &activity) {
    for (auto &act: _activities) {
        if (activity == act) continue;
        if (activity.isSameActivity(act)) return &act;
    }
    return nullptr;
}

void Planning::display() const {
    for (const auto &act: _activities) {
        std::cout << act.toString() << std::endl;
        for (const auto &e: act.getAssignedAsteks()) {
            std::cout << "\t" << e << std::endl;
        }
        std::cout << "\\--------------------/" << std::endl;
    }
}