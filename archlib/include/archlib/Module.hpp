#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>

#include "archlib/RuntimeBehavior.hpp"
#include "archlib/Communication.hpp"
#include "archlib/ModuleDescriptor.hpp"

#include "std_msgs/String.h"
#include "ros/ros.h"

namespace arch {
    
    class Module : public RuntimeBehavior, Communication {

        public:
            Module(const Module &);
		    Module &operator=(const Module &);

            Module(const int32_t &argc, char **argv);
		    virtual ~Module();

            virtual void setUp() = 0;
            virtual void tearDown() = 0;
            virtual void run();
            virtual void body() = 0;

            virtual void sendEvent(const std::string &/*key*/, const std::string &/*value*/) = 0;
            virtual void sendStatus(const std::string &/*key*/, const double &/*value*/) = 0;

            void setModuleDescriptor(const ModuleDescriptor &/*moduleDescriptor*/);
            ModuleDescriptor getModuleDescriptor() const;

        protected:
            ModuleDescriptor moduleDescriptor;
    };
}

#endif