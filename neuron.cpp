#include <string>
#include "neuron.h"

Neuron::Neuron(const std::string id, const int complexity, const float resting, const float balancer = 1, const int refractory = 0, const int threshold = 0, const bool clock = false)
{
    this->id = id;
    this->value = resting;
    this->resting = resting;
    this->balancer = balancer;
    this->refractory = 0;
    this->refractory_period = refractory;
    this->threshold = threshold;
    this->complexity = complexity;
    this->using_clock = clock;
}

Neuron::~Neuron()
{
}

void Neuron::setTransmitter(std::string id, float new_transmitter)
{
    this->connections[id].first = new_transmitter;
}

void Neuron::setThreshold(float new_threshold)
{
    this->threshold = new_threshold;
}

void Neuron::addConnection(float transmitter, Neuron &neuron)
{
    this->connections[neuron.id] = std::make_pair(transmitter, &neuron);
}

void Neuron::receive(float transmission)
{
    this->value += transmission;
    if (this->value < this->threshold || this->using_clock)
    {
        return;
    }

    if (this->refractory == 0)
    {
        this->fire();
    }
    else
    {
        this->refractory -= 1;
    }
}

void Neuron::clock()
{
    if (this->refractory > 0)
    {
        this->refractory -= 1;
        return;
    }

    if (this->value > this->threshold)
    {
        this->fire();
    }
    else if (this->value > this->resting)
    {
        this->value -= balancer;
    }
    else if (this->value < this->resting)
    {
        this->value += balancer;
    }
}

void Neuron::fire()
{
    for (std::map<std::string, std::pair<float, Neuron *>>::iterator itr = connections.begin(); itr != connections.end(); itr++)
    {
        itr->second.second->receive(itr->second.first);
    }
    this->refractory = this->refractory_period;
}