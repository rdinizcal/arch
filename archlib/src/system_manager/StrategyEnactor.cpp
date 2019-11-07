#include "archlib/system_manager/StrategyEnactor.hpp"

namespace archlib {
    namespace system_manager {
        StrategyEnactor::StrategyEnactor(int  &argc, char **argv, const std::string &name): 
            ROSComponent(argc, argv, name)
            {}

        StrategyEnactor::~StrategyEnactor() {}

        void StrategyEnactor::setUp() {}
        
        void StrategyEnactor::body() {}

        void StrategyEnactor::tearDown() {}

        void StrategyEnactor::receiveEvent(const archlib::Event::ConstPtr& msg) {}

        void StrategyEnactor::receiveStatus(const archlib::Status::ConstPtr& msg) {}

        void StrategyEnactor::receiveStrategy(const archlib::Strategy::ConstPtr& msg) {}

        void StrategyEnactor::apply_strategy(const std::string &component) {}

    }
}
