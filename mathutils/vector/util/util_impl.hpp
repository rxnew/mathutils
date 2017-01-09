#pragma once

namespace mathutils {
namespace vector_accessors {
template <int dim, class Real, class>
inline auto get_x(Vector<dim, Real> const& vector) -> Real {
  return vector[0];
}

template <int dim, class Real, class>
inline auto get_y(Vector<dim, Real> const& vector) -> Real {
  return vector[1];
}

template <int dim, class Real, class>
inline auto get_z(Vector<dim, Real> const& vector) -> Real {
  return vector[2];
}

template <int dim, class Real, template <int, class> class VectorT>
inline auto get_x(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle)
  -> Real {
  return get_x(hyperrectangle.get_position());
}

template <int dim, class Real, template <int, class> class VectorT>
inline auto get_y(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle)
  -> Real {
  return get_y(hyperrectangle.get_position());
}

template <int dim, class Real, template <int, class> class VectorT>
inline auto get_z(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle)
  -> Real {
  return get_z(hyperrectangle.get_position());
}

template <int dim, class Real, template <int, class> class VectorT>
inline auto get_w(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle)
  -> Real {
  return get_x(hyperrectangle.get_size());
}

template <int dim, class Real, template <int, class> class VectorT>
inline auto get_h(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle)
  -> Real {
  return get_y(hyperrectangle.get_size());
}

template <int dim, class Real, template <int, class> class VectorT>
inline auto get_d(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle)
  -> Real {
  return get_z(hyperrectangle.get_size());
}
}
}
