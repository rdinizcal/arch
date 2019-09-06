#include "archlib/ROSComponentDescriptor.hpp"

namespace arch {

    ROSComponentDescriptor::ROSComponentDescriptor(std::string &_name) : name(name), freq() {}
    ROSComponentDescriptor::~ROSComponentDescriptor() {}

    ROSComponentDescriptor::ROSComponentDescriptor(const ROSComponentDescriptor &obj) : 
        name(obj.getName()), 
        freq(obj.getFreq()) {}

    ROSComponentDescriptor& ROSComponentDescriptor::operator=(const ROSComponentDescriptor &obj) {
        this->name = obj.getName();
        this->freq = obj.getFreq();
    }

    std::string ROSComponentDescriptor::getName() const {
        return this->name;
    }

    void ROSComponentDescriptor::setFreq(const double &freq) {
        this->freq = freq;
    }

    double ROSComponentDescriptor::getFreq() const {
        return this->freq;
    }
}