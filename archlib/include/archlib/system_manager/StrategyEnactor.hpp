#ifndef STRATEGY_ENACTOR_HPP
#define STRATEGY_ENACTOR_HPP

#include "archlib/Status.h"
#include "archlib/Event.h"
#include "archlib/Strategy.h"

#include "archlib/ROSComponent.hpp"

namespace arch {
    namespace system_manager {
        class StrategyEnactor : public arch::ROSComponent {

            public:
                StrategyEnactor(int &argc, char **argv, std::string name);
                virtual ~StrategyEnactor();

                virtual void setUp();
                virtual void tearDown();
                virtual void body();

                virtual void receiveStatus(const archlib::Status::ConstPtr& msg) = 0;
                virtual void receiveEvent(const archlib::Event::ConstPtr& msg) = 0;
                virtual void receiveStrategy(const archlib::Strategy::ConstPtr& msg) = 0;
                virtual void apply_strategy(const std::string &component) = 0;
        };
    }
}

#endif 