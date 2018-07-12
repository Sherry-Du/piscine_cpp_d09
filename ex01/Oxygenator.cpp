
#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator()
    : _quantity(0)
{
}

Oxygenator::~Oxygenator()
{
}

void
Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void
Oxygenator::useOxygen(int quantity)
{
    LifeCriticalError lfOx("Not enough oxygen to live.", "Oxygenator");
    _quantity -= quantity;
    if (_quantity <= 5)
        throw lfOx;
    if (_quantity <= 15) 
    {
        MissionCriticalError msOx("Not enough oxygen to continue the mission.", "Oxygenator");
        throw msOx;
    }
}
