//
// Created by Esteban on 01/02/2020.
//

#pragma once

#include <unordered_map>
#include <iostream>
#include <string>

namespace stb {
    class Logger {
    public:
        enum class Level {
            INFO = 0,
            WARNING = 1,
            SUCCESS = 2,
            ERROR = 3,
        };
    private:
       const std::unordered_map<Level, std::string> _colors = {
                {Level::INFO, "\033[0;34m"},
                {Level::WARNING, "\033[0;33m"},
                {Level::SUCCESS, "\033[0;32m"},
                {Level::ERROR, "\033[0;31m"}
        };
        const std::unordered_map<Level, std::string> _names = {
                {Level::INFO, "[INFO]"},
                {Level::WARNING, "[WARNING]"},
                {Level::SUCCESS, "[SUCCESS]"},
                {Level::ERROR, "[ERROR]"}
        };
        const char *_reset = "\033[0m";

        Level _actualLevel;
        Level _displayLevel;
        bool _newLog;
        bool _fullColor;
        std::string _delimitor;

        void dispLevel() {
            if (_newLog) {
                std::cout << _colors.at(_actualLevel) << _names.at(_actualLevel);
                if (!_fullColor)
                    std::cout << _reset;
                std::cout << _delimitor;
                _newLog = false;
            }
        }

    public:
        Logger()
        : _actualLevel(Level::INFO), _displayLevel(Level::INFO), _newLog(true), _fullColor(false), _delimitor(" ")
        {}

        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;
        
        Logger &operator<<(const std::string &value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(int value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(unsigned int value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(long value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(unsigned long value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(long long value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(unsigned long long value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(float value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(double value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(long double value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(short value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(unsigned short value) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << value;
            }
            return *this;
        }
        Logger &operator<<(std::nullptr_t) {
            if (_actualLevel >= _displayLevel) {
                dispLevel();
                std::cout << "null";
            }
            return *this;
        }


        Logger &operator<<(Logger & (*func)(Logger &)) {
            return func(*this);
        }
        void displayLevel(Level lvl) { _displayLevel = lvl; }
        void setLevel(Level lvl) { _actualLevel = lvl; }
        void endLine() {
            std::cout << std::endl;
            _newLog = true;
        }
        void setFullColor(bool value) { _fullColor = value; }
        void boolalpha() { std::cout << std::boolalpha; }
        void noboolalpha() { std::cout << std::noboolalpha; }
        void setDelimitor(const std::string &s) { _delimitor = s; }
    };

    extern Logger log;

    static Logger &boolalpha(Logger &log) {
        log.boolalpha();
        return log;
    }
    static Logger &noboolalpha(Logger &log) {
        log.noboolalpha();
        return log;
    }
    static Logger &fullcolor(Logger &log) {
        log.setFullColor(true);
        return log;
    }
    static Logger &nofullcolor(Logger &log) {
        log.setFullColor(false);
        return log;
    }
    static Logger &warning(Logger &log) {
        log.setLevel(Logger::Level::WARNING);
        return log;
    }
    static Logger &info(Logger &log) {
        log.setLevel(Logger::Level::INFO);
        return log;
    }
    static Logger &error(Logger &log) {
        log.setLevel(Logger::Level::ERROR);
        return log;
    }
    static Logger &success(Logger &log) {
        log.setLevel(Logger::Level::SUCCESS);
        return log;
    }
    static Logger &endl(Logger &log) {
        log.endLine();
        return log;
    }
}