#ifndef ADAPTATION_ENGINE_HPP
#define ADAPTATION_ENGINE_HPP

#include "archlib/ROSComponent.hpp"
#include "archlib/Strategy.h"
#include "archlib/Exception.h"

 /*		Adaptation engines must contain at least one type of target system representation,  *
	*		be it a parametric formula or not																										*/

namespace archlib {
	namespace system_manager {
		class AdaptationEngine : public arch::ROSComponent {
			
			public: 
				AdaptationEngine(int &argc, char **argv, const std::string &name);
				virtual ~AdaptationEngine();

			public:
				virtual void setUp();
				virtual void tearDown();
				virtual void body();

				virtual void receiveException(const archlib::Exception::ConstPtr& msg) = 0;
				virtual void propagateStrategy(const archlib::Strategy::ConstPtr& msg) = 0;

				virtual void monitor() = 0;
				virtual void analyze() = 0;
				virtual void plan() = 0;
				virtual void execute() = 0;
		};
	}
}
#endif 