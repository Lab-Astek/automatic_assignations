//
// Created by Esteban on 23/01/2020.
//

#pragma once

#include <string>

struct AstekPercentage {
    std::string name;
    double percentage;

    AstekPercentage(const std::string &name, double percentage) : name(name), percentage(percentage) {}
    ~AstekPercentage() = default;
};