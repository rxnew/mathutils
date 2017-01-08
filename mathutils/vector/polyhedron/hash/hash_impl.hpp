#pragma once

namespace std {
template <int dim, class Real, template <int, class> class VectorT>
auto hash<mathutils::Polyhedron<dim, Real, VectorT>>::
operator()(mathutils::Polyhedron<dim, Real, VectorT> const& obj) const noexcept
  -> size_t {
  using Vector = typename mathutils::Polyhedron<dim, Real, VectorT>::Vector;
  return hash<Vector>()(obj.get_size()) ^ hash<Vector>()(obj.get_position());
}
}
