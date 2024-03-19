#ifndef _FUEL_MAIN_H_
#define _FUEL_MAIN_H_

#include "log.h"
#include "core/Engine.h"
#include "core/Platform.h"

int main() {
    Fuel::Engine& engine = Fuel::Engine::Instance();
    engine.Run();
    
    std::cin.ignore();

    return 0;
}

#endif // _FUEL_MAIN_H_