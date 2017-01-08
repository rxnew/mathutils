#pragma once

namespace std {
template <int dim, class Real>
auto hash<mathutils::Vector<dim, Real>>::
operator()(mathutils::Vector<dim, Real> const& obj) const noexcept -> size_t {
  auto hash_value = size_t(0);
  for(auto i = 0; i < dim; ++i) {
    hash_value ^= hash<Real>((*this)[i]);
  }
  return hash_value;
}
}
