#include "archlib/target_system/Component.hpp"

namespace arch {
	namespace target_system {
		Component::Component(int &argc, char **argv, const std::string &name) : ROSComponent(argc, argv, name) {}

		Component::~Component() {}

		void Component::setUp() {
			double freq;
			handle.getParam("frequency", freq);
			rosComponentDescriptor.setFreq(freq);

			effect = handle.subscribe("effect_" + rosComponentDescriptor.getName(), 1, &Component::reconfigure, this);

			activate();
		}

		void Component::tearDown() {
		}

		int Component::run() {

			Component::setUp();
			setUp();

			while(!ros::isShuttingDown()) {
				ros::Rate loop_rate(rosComponentDescriptor.getFreq());
				ros::spinOnce();

				try{
					body();
				} catch (const std::exception& e) {
					sendEvent(e.what(), "failure");
				}
				loop_rate.sleep();
			}
			
			tearDown();
			Component::tearDown();

			return 0;
		}

		void Component::sendEvent(const std::string &type, const std::string &description) {
			archlib::Event msg;

			msg.source = rosComponentDescriptor.getName();
			msg.type = type;
			msg.description = description;

			collect_event = handle.advertise<archlib::Event>("collect_event", 10);
			collect_event.publish(msg);
		}

		void Component::sendStatus(const std::string &id, const double &value) {
			archlib::Status msg;

			msg.source = rosComponentDescriptor.getName();
			msg.key = id;
			msg.value = value;

			collect_status = handle.advertise<archlib::Status>("collect_status", 10);
			collect_status.publish(msg);
		}

		void Component::reconfigure(const archlib::AdaptationCommand::ConstPtr& msg) {
			reconfigure(msg);
		}

		void Component::activate() {
			status = true;
		}

        void Component::deactivate() {
			status = false;
		}
	}
}