#include "dreamer/lexer/Lexer.h"
#include "dreamer/token/Token.h"

#include <expected>
#include <initializer_list>
#include <optional>
#include <vector>

auto Lexer::run(std::vector<std::string> &&source_core) noexcept
    -> std::expected<std::vector<token::Token>, ErrorKind> {
  const std::initializer_list<char> forbidden_chars{
      '\t',
  },
      included_chars{
          '(',
          ')',
          ':',
          '=',
      };

  std::vector<token::Token> ret{};
  std::string last_word{};
  for (const char source_code_char : source_core) {
    if (const auto &&_ = search(source_code_char, forbidden_chars))
        [[unlikely]] {
      return std::unexpected{ErrorKind::ForbiddenSymbol};
    } else if (const auto &&opt_char = search(source_code_char, included_chars))
        [[likely]] {

      last_word.push_back(opt_char.value());
    }
  }

  return ret;
}

auto Lexer::search(const char target,
                   const std::initializer_list<char> &list) noexcept
    -> std::optional<char> {
  for (auto &&list_char : list) {
    if (target == list_char) {
      return true;
    }
  }

  return false;
}
