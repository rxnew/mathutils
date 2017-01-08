#pragma once

namespace std {
template <>
template <int dim, class Real>
struct hash<mathutils::Vector<dim, Real>> {
  auto operator()(mathutils::Vector<dim, Real> const& obj) const noexcept
    -> size_t;
};
}

#include "hash/hash_impl.hpp"
