#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

namespace arch {

    class Communication {

        public:
            virtual void sendStatus() = 0;
            virtual void sendEvent() = 0;
    };
}

#endif