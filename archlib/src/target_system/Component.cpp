#include "archlib/target_system/Component.hpp"

namespace arch {
	namespace target_system {
		Component::Component(const int32_t &argc, char **argv) : ROSComponent(argc, argv) {}

		Component::~Component() {}

		void Component::setUp() {
			handle.getParam("freq", freq);
			rosComponentDescriptor.setFreq(freq);
		}

		void Component::tearDown() {
		}

		void Component::run() {

			Component::setUp();
			setUp();

			ros::Rate loop_rate(rosComponentDescriptor.getFreq());
			while(!ros::isShuttingDown()) {
				ros::spinOnce();
				body();
				loop_rate.sleep();
			}
			
			tearDown();
			Component::tearDown();
		}
	}
}