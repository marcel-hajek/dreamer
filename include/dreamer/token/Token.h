#pragma once

#include <cstdint>
#include <variant>
#include <string>

namespace token {
  struct Token final {
    struct Literal final {
      struct I8 final {
        const std::int8_t value;
      };

      struct I16 final {
        const std::int16_t value;
      };

      struct I32 final {
        const std::int32_t value;
      };

      struct I64 final {
        const std::int64_t value;
      };

      struct U8 final {
        const std::uint8_t value;
      };

      struct U16 final {
        const std::uint16_t value;
      };

      struct U32 final {
        const std::uint32_t value;
      };

      struct U64 final {
        const std::uint64_t value;
      };

      struct F32 final {
        const float value;
      };

      struct F64 final {
        const double value;
      };

      const std::variant<I8, I16, I32, I64, U8, U16, U32, U64, F32, F64> value;
    };

    struct Keyword final {
      struct I8 final {};

      struct I16 final {};

      struct I32 final {};

      struct I64 final {};

      struct U8 final {};

      struct U16 final {};

      struct U32 final {};

      struct U64 final {};

      struct F32 final {};

      struct F64 final {};

      const std::variant<I8, I16, I32, I64, U8, U16, U32, U64, F32, F64> value;
    };

    struct Identifier final {
      const std::string value;
    };

    const std::variant<Literal, Keyword, Identifier> value;
  };
} // namespace token
