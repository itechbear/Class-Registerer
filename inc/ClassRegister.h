#ifndef _CLASSREGISTER_HPP_
#define _CLASSREGISTER_HPP_

#include "string"
#include "unordered_map"

using std::string;
using std::unordered_map;

namespace lang {
namespace design {

template<typename T>
class ClassRegister {
 private:
  typedef T *(*CreateCallback)();

  typedef unordered_map<string, CreateCallback> CallbackMap;
  CallbackMap map_;

 public:
  static ClassRegister<T> &GetInstance();

  bool Register(string name, CreateCallback callback) {
    auto it = map_.find(name);

    if (it != map_.end()) {
      return false;
    }

    map_[name] = callback;

    return true;
  }

  bool Unregister(string name) {
    auto it = map_.find(name);

    if (it == map_.end()) {
      return false;
    }

    map_.erase(it);

    return true;
  }

  T *Get(string name) {
    auto it = map_.find(name);

    if (it == map_.end()) {
      return NULL;
    }

    return (it->second)();
  }

};

#define CREATE_BASEINSTANCE(base, derived) namespace lang { namespace design { inline base *Create##derived() { return new derived(); } } }
#define REGISTER_BASECLASS(base) namespace lang { namespace design { template<> ClassRegister<base>& ClassRegister<base>::GetInstance() { static ClassRegister<base> instance; return instance; } } }

}
}

#endif // _CLASSREGISTER_HPP_