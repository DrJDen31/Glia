#ifndef __neuron_h__
#define __neuron_h__

#include <map>

/*
Class representing a single neuron cell, each connecting to various other cells that it forwards its message to
*/
class Neuron
{
public:
    // constructors and destructor
    Neuron(const std::string id, const int complexity, const float resting, const float balancer, const int refractory, const int threshold, const bool tick);
    ~Neuron();

    // getters/setters
    float getValue() const { return value; };
    void setTransmitter(std::string id, float new_transmitter);
    float getThreshold() const { return threshold; };
    void setThreshold(float new_threshold);

    // modifiers
    void addConnection(float transmitter, Neuron &neuron);
    void receive(float transmission);
    void tick();

private:
    // member variables
    float value;                                                   // represents the current voltage value of neuron
    float resting;                                                 // represents the resting voltage value
    float balancer;                                                // voltage amount the cell moves towards resting each tick
    int refractory;                                                // current refractory state of the cell
    int refractory_period;                                         // refractory period after each firing
    float threshold;                                               // voltage threshold at which the cell fires
    int complexity;                                                // represents the complexity of the circuit - how many neurons there are
    bool using_tick;                                               // states whether tick is being used
    std::string id;                                                // unique ID of the cell
    std::map<std::string, std::pair<float, Neuron *>> connections; // map of all cells whose dendrites receive from this cells axon
    // key is ID of the receiving cell, value is a pair containing the transmission and a pointer to the receiving cell

    // member functions
    void fire();
};

#endif