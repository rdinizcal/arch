#include "enactor/Enactor.hpp"

StategyEnactor::StategyEnactor(int  &argc, char **argv, std::string name): 
    ROSComponent(argc, argv, name), 
    {}

StategyEnactor::~StategyEnactor() {}

void Enactor::setUp() {}

void StategyEnactor::tearDown() {}

void StategyEnactor::receiveEvent(const archlib::Event::ConstPtr& msg) {}

void StategyEnactor::receiveStatus(const archlib::Status::ConstPtr& msg) {}

void StategyEnactor::receiveStrategy(const archlib::Strategy::ConstPtr& msg) {}

void StategyEnactor::apply_strategy(const std::string &component) {}

void StategyEnactor::body() {}
