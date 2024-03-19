#ifndef _FUEL_MAIN_H_
#define _FUEL_MAIN_H_

#include "log.h"
#include "core/Platform.h"

int main() {
    FUEL_TRACE("Hello World!"); 

    FUEL_DEBUG("{}, {}", Fuel::Time(),Fuel::TimeNano());
    FUEL_DEBUG("{}, {}", Fuel::Clock(), Fuel::ClockNano());

    Fuel::Sleep( 5000 );
    
    return 0;
}

#endif // _FUEL_MAIN_H_