#include "Rot13.h"

#include <locale>
#include <vector>

static const int ROTATION_VALUE {13};
static const std::vector<char> ALPHABET {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

static size_t alphabet_index(char c) {
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
  size_t index = index_after_rotation(alphabet_index(c));
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

} // namespace krul::interpreter::instructions