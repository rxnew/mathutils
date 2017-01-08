#pragma once

namespace mathutils {
namespace dependencies {
template <class T>
struct Default {
  auto operator()(const T& lhs, const T& rhs) const -> bool;
};
}
}

#include "dependencies/dependencies_impl.hpp"
