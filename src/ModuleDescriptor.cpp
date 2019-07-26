#include "ModuleDescriptor.hpp"

namespace arch {

    ModuleDescriptor::ModuleDescriptor() : name(), freq(), deadline(), wce(), connection() {}

    ModuleDescriptor::ModuleDescriptor(const std::string &name, const double &freq, const uint32_t &deadline, const uint32_t wce, const bool &connection) : name(name), freq(freq), deadline(deadline), wce(wce), connection(connection) {}

    ModuleDescriptor::~ModuleDescriptor() {}

    ModuleDescriptor::ModuleDescriptor(const ModuleDescriptor &obj) : 
        name(obj.getName()), 
        freq(obj.getFreq()), 
        deadline(obj.getDeadline()), 
        wce(obj.getWorstCaseExecutionTime()), 
        connection(obj.getConnection()) {}

    ModuleDescriptor& ModuleDescriptor::operator=(const ModuleDescriptor &obj) {
        this->name = obj.getName();
        this->freq = obj.getFreq();
        this->deadline = obj.getDeadline();
        this->wce = obj.getWorstCaseExecutionTime();
        this->connection = obj.getConnection();
    }

    void ModuleDescriptor::setName(const std::string &name) {
        this->name = name;
    }

    std::string ModuleDescriptor::getName() const {
        return this->name;
    }

    void ModuleDescriptor::setFreq(const double &freq) {
        this->freq = freq;
    }

    double ModuleDescriptor::getFreq() const {
        return this->freq;
    }

    void ModuleDescriptor::setDeadline(const uint32_t &deadline) {
        this->deadline = deadline;
    }

    uint32_t ModuleDescriptor::getDeadline() const {
        return this->deadline;
    }

    void ModuleDescriptor::setWorstCaseExecutionTime(const std::uint32_t &wce) {
        this->wce = wce;
    }

    uint32_t ModuleDescriptor::getWorstCaseExecutionTime() const {
        return this->wce;
    }

    void ModuleDescriptor::setConnection(const bool &connection) {
        this->connection = connection;
    }

    bool ModuleDescriptor::getConnection() const {
        return this->connection;
    }
}