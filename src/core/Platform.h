#ifndef _FUEL_PLATFORM_H_
#define _FUEL_PLATFORM_H_

#include "config.h"

namespace Fuel {
    u32 Time();
    u32 Clock();
    u64 TimeNano();
    u64 ClockNano();

    void Sleep( u32 ms );
}

#endif