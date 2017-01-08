#pragma once

namespace mathutils {
namespace dependencies {
template <class T>
auto Default<T>::operator()(const T& lhs, const T& rhs) const -> bool {
  return lhs == rhs;
}
}
}
