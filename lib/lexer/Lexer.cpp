#include "dreamer/lexer/Lexer.h"

#include <expected>
#include <initializer_list>
#include <vector>

auto Lexer::run(std::string &&source_core) noexcept -> std::expected< std::vector<token::Token>, ErrorKind> {
  const std::initializer_list<char> FORBIDDEN_CHARS {'\t'};

  std::vector<token::Token> ret{};

  for (const char source_code_char : source_core) {
    if (search(source_code_char, FORBIDDEN_CHARS)) [[unlikely]] {
      return std::unexpected {ErrorKind::ForbiddenSymbol};
    }
  }

  return ret;
}

auto Lexer::search(const char target, const std::initializer_list<char> &list) noexcept -> bool {
  for (const auto forbidden_char : list) {
    if (target == forbidden_char) [[unlikely]] {
      return true;
    }
  }

  return false;
}
