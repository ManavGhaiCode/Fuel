#ifndef _FUEL_LOG_H_
#define _FUEL_LOG_H_

#include "config.h"

#include <iostream>
#include <string>

namespace Fuel {
    template<typename T>
    void format_helper(std::string& str, const T& value) {
        u64 openBracket = str.find('{');
        if (openBracket == std::string::npos) { return; }
        u64 closeBracket = str.find('}', openBracket + 1);
        if (closeBracket == std::string::npos) { return; }
        std::cout << str.substr(0, openBracket) << value;
        str = str.substr(closeBracket + 1);
    }

    template<typename... Targs>
    std::string format(std::string str, Targs... args) {
        (format_helper(str, args),...);
        return str;
    }

    typedef enum {
        LOG_TRACE,
        LOG_DEBUG,
        LOG_INFO,
        LOG_WARN,
        LOG_ERROR,
        LOG_FATAL
    } LogLevel;

    template <typename... Targs>
    void Log( LogLevel Level, const std::string& Msg, Targs... args ) {
        std::string Prefix;
        std::string color;

        switch ( Level ) {
            case LOG_TRACE: {
                Prefix = "[TRACE] ";
                color = "\033[37m";
            } break;

            case LOG_DEBUG: {
                Prefix = "[DEBUG] ";
                color = "\033[34m";
            } break;

            case LOG_INFO: {
                Prefix = "[INFO ] ";
                color = "\033[32m";
            } break;

            case LOG_WARN: {
                Prefix = "[WARN ] ";
                color = "\033[33m";
            } break;

            case LOG_ERROR: {
                Prefix = "[ERROR] ";
                color = "\033[31m";
            } break;

            case LOG_FATAL: {
                Prefix = "[FATAL] ";
                color = "\033[1m\033[31m";
            } break;

            default: break;
        }

        std::cout << color << Prefix << format(Msg, args...) << std::endl;
    }
}

#ifndef RELEASE
    #define FUEL_TRACE(...) Fuel::Log( Fuel::LOG_TRACE, __VA_ARGS__ )
    #define FUEL_DEBUG(...) Fuel::Log( Fuel::LOG_DEBUG, __VA_ARGS__ )
    #define FUEL_INFO(...)  Fuel::Log( Fuel::LOG_INFO, __VA_ARGS__ )
    #define FUEL_WARN(...)  Fuel::Log( Fuel::LOG_WARN, __VA_ARGS__ )
#else
    #define FUEL_TRACE(...)
    #define FUEL_DEBUG(...)
    #define FUEL_INFO(...)
    #define FUEL_WARN(...)
#endif

#define FUEL_FATAL(...) Fuel::Log( Fuel::LOG_FATAL, __VA_ARGS__ )
#define FUEL_ERROR(...) Fuel::Log( Fuel::LOG_ERROR, __VA_ARGS__ )

#endif // _FUEL_LOG_H_