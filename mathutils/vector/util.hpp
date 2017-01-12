#pragma once

#include "vector.hpp"
#include "hyperrectangle.hpp"

namespace mathutils {
namespace vector_accessors {
template <int dim, class Real, class = std::enable_if_t<(dim >= 1)>>
auto get_x(Vector<dim, Real> const& vector) -> Real;
template <int dim, class Real, class = std::enable_if_t<(dim >= 2)>>
auto get_y(Vector<dim, Real> const& vector) -> Real;
template <int dim, class Real, class = std::enable_if_t<(dim >= 3)>>
auto get_z(Vector<dim, Real> const& vector) -> Real;
template <int dim, class Real, template <int, class> class VectorT>
auto get_x(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle) -> Real;
template <int dim, class Real, template <int, class> class VectorT>
auto get_y(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle) -> Real;
template <int dim, class Real, template <int, class> class VectorT>
auto get_z(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle) -> Real;
template <int dim, class Real, template <int, class> class VectorT>
auto get_w(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle) -> Real;
template <int dim, class Real, template <int, class> class VectorT>
auto get_h(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle) -> Real;
template <int dim, class Real, template <int, class> class VectorT>
auto get_d(Hyperrectangle<dim, Real, VectorT> const& hyperrectangle) -> Real;

template <int dim, class Real, class = std::enable_if_t<(dim >= 1)>>
auto set_x(Vector<dim, Real>& vector, Real n) -> void;
template <int dim, class Real, class = std::enable_if_t<(dim >= 2)>>
auto set_y(Vector<dim, Real>& vector, Real n) -> void;
template <int dim, class Real, class = std::enable_if_t<(dim >= 3)>>
auto set_z(Vector<dim, Real>& vector, Real n) -> void;
template <int dim, class Real, template <int, class> class VectorT>
auto set_x(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void;
template <int dim, class Real, template <int, class> class VectorT>
auto set_y(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void;
template <int dim, class Real, template <int, class> class VectorT>
auto set_z(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void;
template <int dim, class Real, template <int, class> class VectorT>
auto set_w(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void;
template <int dim, class Real, template <int, class> class VectorT>
auto set_h(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void;
template <int dim, class Real, template <int, class> class VectorT>
auto set_d(Hyperrectangle<dim, Real, VectorT>& hyperrectangle, Real n) -> void;
}
}

#include "util/util_impl.hpp"
