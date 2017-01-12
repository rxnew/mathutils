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

template <int dim, class Real, class>
inline auto set_x(Vector<dim, Real>& vector, Real n) -> void {
  vector[0] = n;
}

template <int dim, class Real, class>
inline auto set_y(Vector<dim, Real>& vector, Real n) -> void {
  vector[1] = n;
}

template <int dim, class Real, class>
inline auto set_z(Vector<dim, Real>& vector, Real n) -> void {
  vector[2] = n;
}

template <int dim, class Real, template <int, class> class VectorT>
auto set_x(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void {
  auto position = hyperrectangle.get_position();
  set_x(position, n);
  hyperrectangle.set_position(position);
}

template <int dim, class Real, template <int, class> class VectorT>
auto set_y(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void {
  auto position = hyperrectangle.get_position();
  set_y(position, n);
  hyperrectangle.set_position(position);
}

template <int dim, class Real, template <int, class> class VectorT>
auto set_z(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void {
  auto position = hyperrectangle.get_position();
  set_z(position, n);
  hyperrectangle.set_position(position);
}

template <int dim, class Real, template <int, class> class VectorT>
auto set_w(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void {
  auto size = hyperrectangle.get_size();
  set_x(size, n);
  hyperrectangle.set_size(size);
}

template <int dim, class Real, template <int, class> class VectorT>
auto set_h(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void {
  auto size = hyperrectangle.get_size();
  set_y(size, n);
  hyperrectangle.set_size(size);
}

template <int dim, class Real, template <int, class> class VectorT>
auto set_d(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void {
  auto size = hyperrectangle.get_size();
  set_z(size, n);
  hyperrectangle.set_size(size);
}
}
}
