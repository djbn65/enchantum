#pragma once

#ifdef ENCHANTUM_CONFIG_FILE
  #include ENCHANTUM_CONFIG_FILE
#endif

#include <type_traits>

namespace enchantum {
#ifdef ENCHANTUM_ALIAS_VOID_T
ENCHANTUM_ALIAS_VOID_T;
#else
#ifdef __cpp_lib_void_t	
using ::std::void_t;
#else
template <class... Ts>
using void_t = void;
#endif
#endif

} // namespace enchantum