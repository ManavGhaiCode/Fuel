#include "asserts.h"
#include "log.h"

namespace Fuel {
    void LogAsset( const std::string exp, const std::string msg, const char* File, i32 Line ) {
        FUEL_FATAL("Failed to Assert exp: {} message: {} FILE: {} LINE: {}", exp, msg, File, Line);
        FUEL_BREAK();
    }
}