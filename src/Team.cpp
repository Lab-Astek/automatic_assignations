//
// Created by Esteban on 22/01/2020.
//

#include <Team.hpp>
#include "utils/console.hpp"

Team::Team(const std::string &filename) {
    std::ifstream in(filename);
    std::string name;
    int nbAssignation;

    while(in >> name >> nbAssignation) {
        stb::log << stb::info << "New Astek : " << name << stb::endl;
        Astek a(name, nbAssignation);
        _members.emplace(name, a);
    }
}

void Team::openAndFetch(const std::string &file, char delimitor,
        const std::function<void (Astek &, const std::string &)> &f) {
    std::ifstream in(file);

    if (!in.is_open()) {
        stb::log << stb::error << "Cannot open file" << stb::endl;
        std::exit(84);
    }
    parseFile(in, delimitor ,f);
}

void Team::parseFile(std::ifstream &in, char delimitor,
                     const std::function<void (Astek &, const std::string &)> &f) {
    std::string line;
    std::string name;
    std::string dispos;
    std::size_t pos;

    while (std::getline(in, line)) {
        pos = line.find(delimitor, 2);
        name = line.substr(0, pos);
        dispos = line.substr(pos + 1);
        if (_members.find(name) == _members.end())
            stb::log << stb::error << "Astek : " << name << " not in team" << stb::endl;
        else {
            stb::log << stb::info << "Astek : " << name << stb::endl;
            f(_members[name], dispos);
        }
    }
}


void Team::fetchAvailabities(const std::string &file) {
    openAndFetch(file, ',', &Astek::setAvailabilities);
}

void Team::fetchPreferences(const std::string &file) {
    openAndFetch(file, ':', &Astek::setPreferences);
}

void Team::fetchToAvoid(const std::string &file) {
    openAndFetch(file, ':', &Astek::setToAvoid);
}

void Team::computeAllAssignableActivities(const Planning &planning) {
    for (auto &astek: _members) {
        astek.second.computeAssignableActivities(planning.getActivities());
    }
}
void Team::setPercentagesForAll(const Planning &planning) {
    for (auto &astek: _members) {
        astek.second.setPercentages(planning);
    }
}

void Team::doTheThing(Planning &planning) {
    computeAllAssignableActivities(planning);
    setPercentagesForAll(planning);

    for (auto &activity: planning.getActivities()) {
        activity.assignAsteks(_members);
        auto same = planning.getSameDayActivity(activity);
        if (same != nullptr && _assignAllDay) {
            same->assignSameAsteks(activity, _members);
        }
        setPercentagesForAll(planning);
    }
}