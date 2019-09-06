#ifndef ROSCOMPONENT_HPP
#define ROSCOMPONENT_HPP

#include <string>
#include <stdexcept>

#include "ros/ros.h"

#include "archlib/ROSComponentDescriptor.hpp"

namespace arch {
    class ROSComponent{

        public:
            ROSComponent(const int32_t &argc, char **argv);
		    virtual ~ROSComponent();

        private:
            ROSComponent(const ROSComponent &);
		    ROSComponent &operator=(const ROSComponent &);

        public:
            virtual void setUp() = 0;
            virtual void tearDown() = 0;
            virtual int32_t run() = 0;
            virtual void body() = 0;

        protected:
            ROSComponentDescriptor rosComponentDescriptor;    
    };
}

#endif