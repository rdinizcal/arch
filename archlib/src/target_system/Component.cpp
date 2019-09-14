#include "archlib/target_system/Component.hpp"

namespace arch {
	namespace target_system {
		Component::Component(int &argc, char **argv, const std::string &name) : ROSComponent(argc, argv, name) {}

		Component::~Component() {}

		void Component::setUp() {
			double freq;
			handle.getParam("frequency", freq);
			rosComponentDescriptor.setFreq(freq);

			collect_event = handle.advertise<archlib::Event>("collect_event", 10);
			while(collect_event.getNumSubscribers() < 1) {} // to cope with the delay on opening the connection

			collect_status = handle.advertise<archlib::Status>("collect_status", 10);
			while(collect_status.getNumSubscribers() < 1) {}

			sendStatus("init");
			activate();

			signal(SIGINT, sigIntHandler);
		}

		void Component::tearDown() {
			/* sigIntHandler is making the job of the tearDown
			sendStatus("finish");
			deactivate();
			*/
		}

		void Component::sigIntHandler(int signal){
			archlib::Event eventMsg;
			archlib::Status statusMsg;

			eventMsg.source = ros::this_node::getName();
			eventMsg.content = "deactivate";

			statusMsg.source = ros::this_node::getName();
			statusMsg.content = "status";

			ros::NodeHandle nh;

			ros::Publisher last_event = nh.advertise<archlib::Event>("collect_event", 10);
			while(last_event.getNumSubscribers() < 1) {} // to cope with the delay on opening the connection
			last_event.publish(eventMsg);

			ros::Publisher last_status = nh.advertise<archlib::Status>("collect_status", 10);
			while(last_status.getNumSubscribers() < 1) {}
			last_status.publish(statusMsg);

			ros::shutdown();
		}

		int32_t Component::run() {
			setUp();

			while(ros::ok()) {
				ros::Rate loop_rate(rosComponentDescriptor.getFreq());
				ros::spinOnce();

				sendStatus("running");
				try{
					body();
					sendStatus("success");
				} catch (const std::exception& e) {
					sendStatus("fail");
				} 
				loop_rate.sleep();
			}
			
			tearDown();
			return 0;
		}

		void Component::sendEvent(const std::string &content) {
			archlib::Event msg;

			msg.source = rosComponentDescriptor.getName();
			msg.content = content;

			collect_event.publish(msg);
		}

		void Component::sendStatus(const std::string &content) {
			archlib::Status msg;

			msg.source = rosComponentDescriptor.getName();
			msg.content = content;

			collect_status.publish(msg);
		}

		void Component::reconfigure(const archlib::AdaptationCommand::ConstPtr& msg) {
			reconfigure(msg);
		}

		void Component::activate() {
			sendEvent("activate");
			status = true;
		}

        void Component::deactivate() {
			sendEvent("deactivate");
			status = false;
		}
	}
}