#include "core/Engine.h"

namespace Fuel {
    Engine& Engine::Instance() {
        if (m_Instance == nullptr) {
            m_Instance = new Engine ();
        }

        return *m_Instance;
    }

    void Engine::Run() {
        if (!Init()) {
            return;
        }

        while (isRunning) {}

        Shutdown();
    }

    bool Engine::Init() {
        return false;
    }

    void Engine::Shutdown() {
        return;
    }

    Engine* Engine::m_Instance = nullptr;
}