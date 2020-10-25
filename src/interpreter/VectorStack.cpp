#include "VectorStack.h"

#include <string>

namespace krul::interpreter {
  using namespace exception;

  void VectorStack::push(value_t item) {
    _vector.push_back(item);
  }

  value_t VectorStack::pop() {
    throw_if_empty();
    value_t item = _vector.back();
    _vector.pop_back();
    return item;
  }

  value_t VectorStack::peek() const {
    throw_if_empty();
    return _vector.back();
  }

  int VectorStack::pop_as_int() {
    return convert_to_int(pop());
  }

  int VectorStack::peek_as_int() const {
    return convert_to_int(peek());
  }

  int VectorStack::convert_to_int(const value_t& item) {
    try {
      return std::stoi(item);
    } catch (const std::exception& e) { throw TypeConversionException(item, "int"); }
  }

  void VectorStack::throw_if_empty() const {
    if (_vector.empty()) throw std::out_of_range("VectorStack is empty");
  }

} // namespace krul::interpreter