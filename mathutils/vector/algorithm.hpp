#pragma once

#include "vector.hpp"

namespace mathutils {
template <int dim, class Real>
auto dot(Vector<dim, Real> const& a, Vector<dim, Real> const& b) -> Real;
template <class Real>
auto cross(Vector<2, Real> const& a, Vector<2, Real> const& b) -> Real;
template <class Real>
auto cross(Vector<3, Real> const& a, Vector<3, Real> const& b)
  -> Vector<3, Real>;
template <class Real>
auto is_intersected(Vector<1, Real> const& a1,
                    Vector<1, Real> const& a2,
                    Vector<1, Real> const& b1,
                    Vector<1, Real> const& b2) -> bool;
template <class Real>
auto is_intersected(Vector<2, Real> const& a1,
                    Vector<2, Real> const& a2,
                    Vector<2, Real> const& b1,
                    Vector<2, Real> const& b2) -> bool;
}

#include "algorithm/algorithm_impl.hpp"
