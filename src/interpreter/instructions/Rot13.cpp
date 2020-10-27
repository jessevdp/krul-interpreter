#include "Rot13.h"

#include <algorithm>
#include <locale>
#include <vector>

static const int ROTATION_VALUE {13};
static const std::vector<char> ALPHABET {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

static int alphabet_index(char c) {
  auto it = std::find(ALPHABET.begin(), ALPHABET.end(), c);
  if (it == ALPHABET.end()) return -1;
  return std::distance(ALPHABET.begin(), it);
}

static size_t index_after_rotation(size_t index) {
  return (index + ROTATION_VALUE) % ALPHABET.size();
}

static char rotate(char c) {
  bool uppercase = isupper(c);
  if (uppercase) c = tolower(c, std::locale());
  int old_index = alphabet_index(c);
  if (old_index < 0) return c;
  size_t index = index_after_rotation(old_index);
  char new_char = ALPHABET[index];
  if (uppercase) new_char = toupper(new_char, std::locale());
  return new_char;
}

namespace krul::interpreter::instructions {

  void Rot13::execute(Context& context) const {
    value_t value = context.stack().pop();
    value_t new_value;

    for (char c : value) {
      new_value += rotate(c);
    }

    context.stack().push(new_value);
  }

  std::unique_ptr<Instruction> Rot13::clone() const {
    return std::make_unique<Rot13>(*this);
  }

} // namespace krul::interpreter::instructions