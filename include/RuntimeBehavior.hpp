#ifndef RUNTIME_BEHAVIOR_HPP
#define RUNTIME_BEHAVIOR_HPP

namespace arch {

    class RuntimeBehavior {
        public:
            virtual void setUp() = 0;
            virtual void tearDown() = 0;
            virtual void run() = 0;
    };
}

#endif