#pragma once

#include <expected>
#include <vector>

#include "dreamer/token/Token.h"

class Lexer final {
public:
  enum class ErrorKind {
    ForbiddenSymbol,
  };
  [[nodiscard]] static auto run(std::string &&source_core) noexcept -> std::expected< std::vector<token::Token>, ErrorKind>;

private:

};
