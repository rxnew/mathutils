#pragma once

namespace std {
template <>
template <int dim, class Real, template <int, class> class VectorT>
struct hash<mathutils::Polyhedron<dim, Real, VectorT>> {
  auto operator()(mathutils::Polyhedron<dim, Real, VectorT> const& obj)
    const noexcept -> size_t;
};
}

#include "hash/hash_impl.hpp"
