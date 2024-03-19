#ifndef _FUEL_ASSERTS_H_
#define _FUEL_ASSERTS_H_

#include "config.h"

#ifdef FUEL_PLATFORM_LINUX
    #define FUEL_BREAK() __builtin_trap()
#elif defined (FUEL_PLATFORM_WINDOWS)
    #include <intrin.h>
    #define FUEL_BREAK() __debugbreak()
#endif

#if FUEL_ENABLE_ASSERTS == 1

#include <string>

namespace Fuel {
    void LogAsset( const std::string exp, const std::string msg, const char* File, i32 Line );
}

#define FUEL_ASSET(exp) if (exp) {} else { LogAsset( #exp, "", __FILE__, __LINE__ ); }
#define FUEL_ASSET_MSG(exp, msg) if (exp) {} else { LogAsset( #exp, msg, __FILE__, __LINE__ ); }

#ifndef RELEASE
    #define FUEL_ASSET_DEBUG(exp) if (exp) {} else { LogAsset( #exp, "", __FILE__, __LINE__ ); }
#else
    #define FUEL_ASSET_DEBUG(exp)
#endif

#else

#define FUEL_ASSET(exp)
#define FUEL_ASSET_MSG(exp, msg)

#define FUEL_ASSET_DEBUG(exp)

#endif

#endif // _FUEL_ASSERTS_H_