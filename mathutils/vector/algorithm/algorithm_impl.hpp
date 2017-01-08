#pragma once

namespace mathutils {
// prototype declarations
template <class Real>
auto _ccw(Vector<2, Real> const& a,
          Vector<2, Real> const& b,
          Vector<2, Real> const& c) -> int;

// implementations
template <int dim, class Real>
auto dot(Vector<dim, Real> const& a, Vector<dim, Real> const& b) -> Real {
  auto result = Real(0);
  for(auto i = 0; i < dim; ++i) {
    result += a[i] * b[i];
  }
  return result;
}

template <class Real>
auto cross(Vector<2, Real> const& a, Vector<2, Real> const& b) -> Real {
  return a[0] * b[1] - a[1] * b[0];
}

template <class Real>
auto cross(Vector<3, Real> const& a, Vector<3, Real> const& b)
  -> Vector<3, Real> {
  return Vector<3, Real>(a[1] * b[2] - a[2] * b[1],
                         a[2] * b[0] - a[0] * b[2],
                         a[0] * b[1] - a[1] * b[0]);
}

template <class Real>
auto is_intersected(Vector<1, Real> const& a1,
                    Vector<1, Real> const& a2,
                    Vector<1, Real> const& b1,
                    Vector<1, Real> const& b2) -> bool {
  Vector<1, Real> const& a_max = std::max(a1, a2); 
  Vector<1, Real> const& a_min = std::min(a1, a2);
  Vector<1, Real> const& b_max = std::max(b1, b2);
  Vector<1, Real> const& b_min = std::min(b1, b2);
  return !(a_min > b_max || a_max < b_min);
}

template <class Real>
auto is_intersected(Vector<2, Real> const& a1,
                    Vector<2, Real> const& a2,
                    Vector<2, Real> const& b1,
                    Vector<2, Real> const& b2) -> bool {
  return
    _ccw(a1, a2, b1) * _ccw(a1, a2, b2) <= 0 &&
    _ccw(b1, b2, a1) * _ccw(b1, b2, a2) <= 0;
}

template <class Real>
auto _ccw(Vector<2, Real> const& a,
          Vector<2, Real> const& b,
          Vector<2, Real> const& c) -> int {
  auto ba = b - a;
  auto ca = c - a;
  if(cross(ba, ca) > 0)     return +1; // counter clockwise
  if(cross(ba, ca) < 0)     return -1; // clockwise
  if(dot(ba, ca) < 0)       return +2; // c--a--b on line
  if(ba.norm() < ca.norm()) return -2; // a--b--c on line
  return 0;
}
}
