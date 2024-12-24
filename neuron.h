#ifndef __neuron_h__
#define __neuron_h__

class Neuron
{
public:
    // constructors and destructor
    Neuron(const int complexity, const int threshold, const bool clock);
    ~Neuron();

    // getters/setters
    float getValue() const { return value; };
    void setTransmitter(float new_transmitter);
    float getThreshold() const { return threshold; };
    void setThreshold(float new_threshold);

    // modifiers
    void addConnection(Neuron &neuron);
    void receive(float transmission);
    void clock();

private:
    // member variables
    float value;
    float transmitter;
    float threshold;
    int index;
    int complexity;
    bool using_clock;
    Neuron **connections;

    // member functions
    void fire();
    std::string makeID();
};

#endif