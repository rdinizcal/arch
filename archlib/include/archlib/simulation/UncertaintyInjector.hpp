#ifndef UNCERTAINTY_INJECTOR_HPP
#define UNCERTAINTY_INJECTOR_HPP

#include "ros/ros.h"
#include <ros/package.h>

#include "archlib/Uncertainty.h"
#include "archlib/ROSComponent.hpp"

namespace archlib {
    namespace simulation {
        class UncertaintyInjector : public arch::ROSComponent {
            public:
                UncertaintyInjector(int &argc, char **argv, const std::string &name);
                virtual ~UncertaintyInjector();

                virtual void setUp();
                virtual void tearDown();
                virtual void body();

                void inject(const std::string &component, const std::string &content);
        };
    }
}

#endif 