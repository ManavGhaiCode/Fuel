#ifndef _FUEL_PLATFORM_H_
#define _FUEL_PLATFORM_H_

#include "config.h"

namespace Fuel {
    u32 Time();
    u32 Clock();
    u32 TimeNano();
    u32 ClockNano();

    void Sleep( u32 ms );

    void* PlatformAllocateStack( u32 Size );
    void  PlatformFreeStack( u32 Size );
    void* PlatformMemsetStack( u32 Size );
    void* PlatformMemcpyStack( u32 Size );
}

#endif