#pragma once

#include <expected>
#include <optional>
#include <vector>

#include "dreamer/token/Token.h"

class Lexer final {
public:
  enum class ErrorKind {
    ForbiddenSymbol,
  };
  [[nodiscard]] static auto run(std::vector<std::string> &&source_core) noexcept
      -> std::expected<std::vector<token::Token>, ErrorKind>;

private:
  [[nodiscard]] static auto
  split_tokens(std::vector<std::string> &&source_core) noexcept
      -> std::expected<std::vector<token::Token>, ErrorKind>;

  [[nodiscard]] static auto
  search(const char target, const std::initializer_list<char> &list) noexcept
      -> std::optional<char>;
};
