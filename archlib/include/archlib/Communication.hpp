#ifndef COMM_HPP
#define COMM_HPP

#include <string>

namespace arch {

    class Communication {

        public:
            virtual void sendEvent(const std::string &/*key*/, const std::string &/*value*/) = 0;
            virtual void sendStatus(const std::string &/*key*/, const double &/*value*/) = 0;
    };
}

#endif