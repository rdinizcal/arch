#include "archlib/system_manager/AdaptationEngine.hpp"

namespace arch {
    namespace system_manager {
        AdaptationEngine::AdaptationEngine(int  &argc, char **argv, std::string name): 
            ROSComponent(argc, argv, name)
            {}

        AdaptationEngine::~AdaptationEngine() {}

        /* ROSComponent-related methods */
        void AdaptationEngine::setUp() {}

        void AdaptationEngine::tearDown() {}

        void AdaptationEngine::body() {}

        /* Auxiliary methods (necessary?) */
        void AdaptationEngine::receiveException(const archlib::Exception::ConstPtr& msg) {}

        void AdaptationEngine::propagateStrategy(const archlib::Strategy::ConstPtr& msg) {}

        /* Adaptation-related methods */
        void AdaptationEngine::monitor() {}

        void AdaptationEngine::analyze() {}

        void AdaptationEngine::plan() {}

        void AdaptationEngine::execute() {}
    }
}
