#include "VectorCallStack.h"

namespace krul::interpreter {

  void VectorCallStack::push(line_t line) {
    _vector.push_back(line);
  }

  line_t VectorCallStack::pop() {
    if (_vector.empty()) throw std::out_of_range("VectorCallStack is empty");
    line_t item = _vector.back();
    _vector.pop_back();
    return item;
  }

} // namespace krul::interpreter