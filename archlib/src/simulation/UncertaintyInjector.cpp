#include "archlib/simulation/UncertaintyInjector.hpp"

namespace archlib {
    namespace simulation {
        UncertaintyInjector::UncertaintyInjector(int &argc, char **argv, const std::string &name):
            ROSComponent(argc, argv, name)
            {}

        UncertaintyInjector::~UncertaintyInjector() {}

        void UncertaintyInjector::setUp() {}
        void UncertaintyInjector::tearDown() {}
        void UncertaintyInjector::body() {}

        void UncertaintyInjector::inject(const std::string &component, const std::string &content) {}
    }
}