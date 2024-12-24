#include <string>
#include "neuron.h"

Neuron::Neuron(const int complexity, const int threshold = 0, const bool clock = false)
{
    value = 0;
    index = 0;
    transmitter = 0;
    this->threshold = threshold;
    this->complexity = complexity;
    this->using_clock = clock;
    connections = new Neuron *[complexity];
    for (int i = 0; i < complexity; i++)
    {
        connections[i] = NULL;
    }
}

Neuron::~Neuron()
{
    delete connections;
}

void Neuron::setTransmitter(float new_transmitter)
{
    this->transmitter = new_transmitter;
}

void Neuron::setThreshold(float new_threshold)
{
    this->threshold = new_threshold;
}

void Neuron::addConnection(Neuron &neuron)
{
    connections[index] = &neuron;
}

void Neuron::receive(float transmission)
{
    value += transmission;
    if (value > threshold && !using_clock)
    {
        this->fire();
    }
}

void Neuron::clock()
{
    if (value > threshold)
    {
        this->fire();
    }
}

void Neuron::fire()
{
    for (int i = 0; i < complexity; i++)
    {
        connections[i]->receive(transmitter);
    }
}