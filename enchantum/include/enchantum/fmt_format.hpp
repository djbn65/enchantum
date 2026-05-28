#pragma once

#include "details/format_util.hpp"
#include "details/string_view.hpp"
#include "enchantum.hpp"
#include <fmt/format.h>

#ifdef __cpp_concepts
template<enchantum::Enum E>
struct fmt::formatter<E>
#else
template<typename E>
struct fmt::formatter<E, char, typename std::enable_if<std::is_enum<E>::value>::type>
#endif
: fmt::formatter< ::enchantum::string_view> {
  template<typename FmtContext>
  constexpr auto format(const E e, FmtContext& ctx) const
  {
    return fmt::formatter< ::enchantum::string_view>::format(enchantum::details::format(e), ctx);
  }
};