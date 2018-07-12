
#ifndef SHARED_PTR_HPP_
#define SHARED_PTR_HPP_

#include <cstddef>
#include "BaseComponent.hpp"

class RefPtr {
public:
  RefPtr(BaseComponent *rawPtr);
  RefPtr(RefPtr const &other);
  RefPtr() : RefPtr(nullptr) {}
  RefPtr &operator=(RefPtr const &other);
  ~RefPtr();
  BaseComponent *get() {
    return _rawPtr;
  }
private:
  BaseComponent *_rawPtr;
  int *_refCounter;
};

#endif // SHARED_PTR_HPP_
