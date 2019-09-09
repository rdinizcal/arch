#include "archlib/target_system/Probe.hpp"

namespace arch {
	namespace target_system {
		Probe::Probe(int &argc, char **argv, const std::string &name) : ROSComponent(argc, argv, name) {}

		Probe::~Probe() {}

        void Probe::setUp() {
            log_event = handle.advertise<archlib::Event>("log_event", 1000);
            log_status = handle.advertise<archlib::Status>("log_status", 1000);

            ros::Subscriber collect_event = handle.subscribe("collect_event", 1000, &Probe::collectEvent, this);
            ros::Subscriber collect_status = handle.subscribe("collect_status", 1000, &Probe::collectStatus, this);
        }

        void Probe::tearDown() {
        }

        void Probe::collectEvent(const archlib::Event::ConstPtr& msg) {
            log_event.publish(msg);
        }

        void Probe::collectStatus(const archlib::Status::ConstPtr& msg) {
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