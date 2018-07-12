#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{}

SimplePtr::SimplePtr(SimplePtr const &)
{}

SimplePtr::~SimplePtr()
{
    delete _rawPtr;
}

SimplePtr &SimplePtr::operator=(SimplePtr const &)
{
    return *this;
}

BaseComponent* SimplePtr::get()
{
    return _rawPtr;
}
