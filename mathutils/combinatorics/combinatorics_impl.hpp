#pragma once

namespace mathutils {
template <class T>
auto combination(T n, T k) -> T {
  k = std::min(k, n - k);
  auto const identity = T(1);
  auto result = identity;
  for(auto i = 1; i <= static_cast<int>(k); ++i) {
    result *= n;
    result /= i;
    n -= identity;
  }
  return result;
}
}
