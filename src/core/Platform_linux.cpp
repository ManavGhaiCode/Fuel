#include "core/Platform.h"
#include "config.h"

#ifdef FUEL_PLATFORM_LINUX

#include <time.h>
#include <unistd.h>
#include <alloca.h>

#ifdef FUEL_ALLOCA
    #undef FUEL_ALLOCA
    #define FUEL_ALLOCA( Size ) alloca( Size )
#endif

namespace Fuel {
    u32 Time() {
        timespec now;
        clock_gettime(CLOCK_REALTIME, &now);

        return now.tv_nsec * 1000 + (now.tv_nsec - ( now.tv_nsec % 1000000 ));
    }

    u32 Clock() {
        timespec now;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &now);

        return now.tv_nsec * 1000 + (now.tv_nsec - ( now.tv_nsec % 1000000 ));
    }

    u64 TimeNano() {
        timespec now;
        clock_gettime(CLOCK_REALTIME, &now);

        return now.tv_nsec * 1000000000 + now.tv_nsec;
    }

    u64 ClockNano() {
        timespec now;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &now);

        return now.tv_nsec * 1000000000 + now.tv_nsec;
    }

    void Sleep( u32 ms ) {
        #if _POSIX_C_SOURCE >= 200809L
            timespec now;

            now.tv_sec = ms / 1000;
            now.tv_nsec = ( ms % 1000 ) * 1000000;

            nanosleep( &now, 0 );
        #else
            if (ms >= 1000) {
                sleep(ms / 1000);
            }

            usleep( ( ms % 1000 ) * 1000 );
        #endif
    }
}

#endif