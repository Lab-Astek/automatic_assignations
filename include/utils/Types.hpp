//
// Created by Esteban on 14/01/2020.
//

#pragma once

#include <string>

namespace utils {
    enum class Location {
        SM20,
        SM21,
        SM22,
        SM23,
        SM24,
        SM25,
        SM501,
        SM502,
        Unknown
    };

    static Location stringToLocation(const std::string &str) {
        if (str == "SM20") return Location::SM20;
        if (str == "SM21") return Location::SM21;
        if (str == "SM22") return Location::SM22;
        if (str == "SM23") return Location::SM23;
        if (str == "SM24") return Location::SM24;
        if (str == "SM25") return Location::SM25;
        if (str == "501") return Location::SM501;
        if (str == "502") return Location::SM502;
        return Location::Unknown;
    }

    static std::string locationToString(Location location) {
        switch (location) {
            case Location::SM20: return "SM20";
            case Location::SM21: return "SM21";
            case Location::SM22: return "SM22";
            case Location::SM23: return "SM23";
            case Location::SM24: return "SM24";
            case Location::SM25: return "SM25";
            case Location::SM501: return "SM501";
            case Location::SM502: return "SM502";
            default: return "INCONNU";
        }
    }

    enum class Activity {
        FU,
        CR,
        REVIEW,
        BS,
        STUMPER,
        TAM,
        PISCINE,
        Unknown
    };

    static Activity stringToActivity(const std::string &str) {
        if (str == "FU") return Activity::FU;
        if (str == "CR") return Activity::CR;
        if (str == "BS") return Activity::BS;
        if (str == "REVIEW") return Activity::REVIEW;
        if (str == "STUMPER") return Activity::STUMPER;
        if (str == "TAM") return Activity::TAM;
        if (str == "PISCINE") return Activity::PISCINE;
        return Activity::Unknown;
    }

    static std::string activityToString(Activity activity) {
        switch (activity) {
            case Activity::FU: return "FU";
            case Activity::CR: return "CR";
            case Activity::REVIEW: return "REVIEW";
            case Activity::BS: return "BS";
            case Activity::STUMPER: return "STUMPER";
            case Activity::TAM: return "TAM";
            case Activity::PISCINE: return "PISCINE";
            default: return "INCONNU";
        }
    }

    enum class Modules {
        PSU,
        SHELL,
        CPE,
        CORE,
        MAT,
        MUL,
        AIA,
        SAD,
        SYS,
        ALL,
        Unknown
    };

    static Modules stringToModules(const std::string &str) {
        if (str == "PSU") return Modules::PSU;
        if (str == "CPE") return Modules::CPE;
        if (str == "MAT") return Modules::MAT;
        if (str == "MUL") return Modules::MUL;
        if (str == "AIA") return Modules::AIA;
        if (str == "SAD") return Modules::SAD;
        if (str == "SHELL") return Modules::SHELL;
        if (str == "CORE") return Modules::CORE;
        if (str == "SYS") return Modules::SYS;
        if (str == "ALL") return Modules::ALL;
        return Modules::Unknown;
    };

    enum class Month {
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
        Unknown
    };

    static Month stringToMonth(const std::string &str) {
        if (str == "Jan") return Month::January;
        if (str == "Feb") return Month::February;
        if (str == "Mar") return Month::March;
        if (str == "Apr") return Month::April;
        if (str == "May") return Month::May;
        if (str == "Jun") return Month::June;
        if (str == "Jul") return Month::July;
        if (str == "Aug") return Month::August;
        if (str == "Sep") return Month::September;
        if (str == "Oct") return Month::October;
        if (str == "Nov") return Month::November;
        if (str == "Dec") return Month::December;
        return Month::Unknown;
    }

    enum class Day {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday,
        Unknown
    };

    static Day stringToDay(const std::string &str) {
        if (str == "Mon") return Day::Monday;
        if (str == "Tue") return Day::Tuesday;
        if (str == "Wed") return Day::Wednesday;
        if (str == "Thu") return Day::Thursday;
        if (str == "Fri") return Day::Friday;
        if (str == "Sat") return Day::Saturday;
        if (str == "Sun") return Day::Sunday;
        return Day::Unknown;
    }

    static std::string dayToString(Day day) {
        switch (day) {
            case Day::Monday: return "Lundi";
            case Day::Tuesday: return "Mardi";
            case Day::Wednesday: return "Mercredi";
            case Day::Thursday: return "Jeudi";
            case Day::Friday: return "Vendredi";
            case Day::Saturday: return "Samedi";
            case Day::Sunday: return "Dimanche";
            default: return "Inconnu";
        }
    }

    enum class TimeOfDay {
        AM,
        PM,
        Unknown
    };

    static TimeOfDay stringToTimeOfDay(const std::string &str) {
        if (str == "AM") return TimeOfDay::AM;
        if (str == "PM") return TimeOfDay::PM;
        return TimeOfDay::Unknown;
    }
}