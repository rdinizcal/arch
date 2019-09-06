#include "archlib/target_system/Probe.hpp"

namespace arch {
	namespace target_system {
		Probe::Probe(const int32_t &argc, char **argv) : ROSComponent(argc, argv) {}

		Probe::~Probe() {}

        void Probe::setUp() {
            log_event = handle.advertise<messages::Event>("log_event", 1000);
            log_status = handle.advertise<messages::Status>("log_status", 1000);

            ros::Subscriber collect_event = handle.subscribe("collect_event", 1000, &Probe::collectEvent, this);
            ros::Subscriber collect_status = handle.subscribe("collect_status", 1000, &Probe::collectStatus, this);
        }

        void Probe::tearDown() {
        }

        void Probe::collectEvent(const messages::Event::ConstPtr& msg) {
            log_event.publish(msg);
        }

        void Probe::collectStatus(const messages::Status::ConstPtr& msg) {
            log_status.publish(msg);
        }

		int32_t Probe::run() {
			setUp();    
            ros::spin();			
			tearDown();

            return 0;
		}
	}
}