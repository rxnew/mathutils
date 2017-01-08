#pragma once

namespace std {
template <int dim, class Real, template <int, class> class VectorT>
auto hash<mathutils::Hyperrectangle<dim, Real, VectorT>>::
operator()(mathutils::Hyperrectangle<dim, Real, VectorT> const& obj)
  const noexcept -> size_t {
  using Vector = typename mathutils::Hyperrectangle<dim, Real, VectorT>::Vector;
  return hash<Vector>()(obj.get_size()) ^ hash<Vector>()(obj.get_position());
}
}
