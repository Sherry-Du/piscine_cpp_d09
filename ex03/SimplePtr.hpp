
#ifndef SIMPLE_PTR_HPP_
#define SIMPLE_PTR_HPP_

#include "BaseComponent.hpp"

class SimplePtr
{
    public:
        SimplePtr(BaseComponent *rawPtr);
        ~SimplePtr();
        BaseComponent *get();

    private:
        BaseComponent *_rawPtr;

        SimplePtr(SimplePtr const &);
        SimplePtr &operator=(SimplePtr const &);
};

#endif // SIMPLE_PTR_HPP_
