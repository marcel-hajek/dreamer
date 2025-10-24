#include "dreamer/lexer/Lexer.h"

#include <expected>
#include <vector>

auto Lexer::run(std::string &&source_core) noexcept -> std::expected< std::vector<token::Token>, ErrorKind> {
  static constexpr const auto FORBIDDEN_CHARS = {'\t'};

  std::vector<token::Token> ret{};

  std::string last_word;
  for (const char source_code_char : source_core) {
    for (const auto forbidden_char : FORBIDDEN_CHARS) {
      if (source_code_char == forbidden_char) [[unlikely]] {
        return std::unexpected {ErrorKind::ForbiddenSymbol};
      }
    }
  }

  return ret;
}
