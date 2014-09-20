#include <iostream>
#include <string>
#include <cassert>
#include <ClassRegister.h>

#include "Cat.h"

using namespace std;
using namespace base;
using namespace demo;

int main() {
  Cat *cat_ptr = (Cat *) ClassRegister<Animal>::GetInstance().Get("Cat");

  assert(cat_ptr != NULL);

  return 0;
}