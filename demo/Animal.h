#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include "ClassRegister.h"

using namespace base;

namespace demo {

class Animal {
 public:
  Animal() {

  };

  ~Animal() {

  }

  virtual void Roar() = 0;
};

#define CREATE_ANIMAL_INSTANCE(name) CREATE_BASEINSTANCE(Animal, name)
#define REGISTER_ANIMAL_SUBCLASS(name) namespace base { void Register##name() { ClassRegister<Animal>::GetInstance().Register(#name, &Create##name); } __attribute__((constructor)) void Register##name(); }
}

#endif // _ANIMAL_HPP_