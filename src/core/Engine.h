#ifndef _FUEL_ENGINE_H_
#define _FUEL_ENGINE_H_

namespace Fuel {
    class Engine {
        public:
            static Engine& Instance();
            void Run();

        private:
            bool Init();
            void Shutdown();

            static Engine* m_Instance;

            bool isRunning = false;
    };
}

#endif // _FUEL_ENGINE_H_