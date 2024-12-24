#ifndef __neuron_h__
#define __neuron_h__

#include <map>

class Neuron
{
public:
    // constructors and destructor
    Neuron(const std::string id, const int complexity, const float resting, const float balancer, const int refractory, const int threshold, const bool clock);
    ~Neuron();

    // getters/setters
    float getValue() const { return value; };
    void setTransmitter(std::string id, float new_transmitter);
    float getThreshold() const { return threshold; };
    void setThreshold(float new_threshold);

    // modifiers
    void addConnection(float transmitter, Neuron &neuron);
    void receive(float transmission);
    void clock();

private:
    // member variables
    float value;
    float resting;
    float balancer;
    int refractory;
    int refractory_period;
    float threshold;
    int complexity;
    bool using_clock;
    std::string id;
    std::map<std::string, std::pair<float, Neuron *>> connections;

    // member functions
    void fire();
};

#endif