#ifndef _FUEL_MAIN_H_
#define _FUEL_MAIN_H_

#include "log.h"
#include "mem.h"
#include "core/Engine.h"
#include "core/Platform.h"

int main() {
    FUEL_DEBUG("Starting Fuel!");

    Fuel::InitMemory();

    Fuel::Engine& engine = Fuel::Engine::Instance();
    engine.Run();

    Fuel::ShutdownMemory();

    std::cin.ignore();

    return 0;
}

#endif // _FUEL_MAIN_H_