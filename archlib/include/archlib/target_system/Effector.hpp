#ifndef EFFECTOR_HPP
#define EFFECTOR_HPP

#include "ros/ros.h"

#include "archlib/AdaptationCommand.h"
#include "archlib/ROSComponent.hpp"

namespace arch {
    namespace target_system {

        class Effector : public ROSComponent {

            public:
                Effector(int &argc, char **argv, const std::string &name);
                virtual ~Effector();

            private:
                Effector(const Effector &);
                Effector &operator=(const Effector &);

            public:
                virtual void setUp();
                virtual void tearDown();
                virtual int32_t run();

                virtual void receiveAdaptationCommand(const archlib::AdaptationCommand::ConstPtr& msg) = 0;
        };

    }
}


#endif 