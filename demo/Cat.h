#ifndef _CAT_H_
#define _CAT_H_

#include "Animal.h"

namespace demo {
class Cat : public Animal {
 private:
  void Meow() {

  };

 public:
  virtual void Roar() {
    Meow();
  };
};

CREATE_ANIMAL_INSTANCE(Cat)
}

#endif // _CAT_H_