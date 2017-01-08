#pragma once

#include <cmath>

namespace mathutils {
template <int dim, class Real>
template <class T, class... Args, class>
inline Vector<dim, Real>::Vector(T&& t, Args&&... args)
  : p_{{std::forward<T>(t), std::forward<Args>(args)...}} {
}

template <int dim, class Real>
inline auto Vector<dim, Real>::operator==(Vector const& other) const -> bool {
  return p_ == other.p_;
}

template <int dim, class Real>
inline auto Vector<dim, Real>::operator!=(Vector const& other) const -> bool {
  return p_ != other.p_;
}

template <int dim, class Real>
auto Vector<dim, Real>::operator<(Vector<dim, Real> const& other) const -> bool {
  for(auto i = dim - 1; i >= 0; --i) {
    if((*this)[i] < other[i]) return true;
    if((*this)[i] > other[i]) return false;
  }
  return p_[0] != other.p_[0];
}

template <int dim, class Real>
auto Vector<dim, Real>::operator>(Vector<dim, Real> const& other) const -> bool {
  for(auto i = dim - 1; i >= 0; --i) {
    if((*this)[i] > other[i]) return true;
    if((*this)[i] < other[i]) return false;
  }
  return p_[0] != other.p_[0];
}

template <int dim, class Real>
inline auto Vector<dim, Real>::operator[](size_t n) -> Real& {
  return p_[n];
}

template <int dim, class Real>
inline auto Vector<dim, Real>::operator[](size_t n) const -> Real const& {
  return p_[n];
}

template <int dim, class Real>
auto Vector<dim, Real>::operator+(Vector<dim, Real> const& other) const
  -> Vector {
  auto vector = Vector<dim, Real>();
  for(auto i = 0; i < dim; ++i) {
    vector[i] = (*this)[i] + other[i];
  }
  return vector;
}

template <int dim, class Real>
auto Vector<dim, Real>::operator-(Vector<dim, Real> const& other) const
  -> Vector {
  auto vector = Vector<dim, Real>();
  for(auto i = 0; i < dim; ++i) {
    vector[i] = (*this)[i] - other[i];
  }
  return vector;
}

template <int dim, class Real>
auto Vector<dim, Real>::operator*(Real const& n) const -> Vector {
  auto vector = Vector<dim, Real>();
  for(auto i = 0; i < dim; ++i) {
    vector[i] = (*this)[i] * n;
  }
  return vector;
}

template <int dim, class Real>
inline auto Vector<dim, Real>::dimension() const -> int {
  return dim;
}

template <int dim, class Real>
template <class T,
          std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t>>
auto Vector<dim, Real>::norm(int n) const -> Real {
  auto inner = Real(0);
  for(auto const& e : p_) {
    inner += std::pow(e, n);
  }
  return std::pow(inner, Real(1) / n);
}

template <int dim, class Real>
template <class T,
          std::enable_if_t<!std::is_floating_point<T>::value, std::nullptr_t>>
auto Vector<dim, Real>::norm(int n) const -> long double {
  auto inner = 0;
  for(auto const& e : p_) {
    inner += std::pow(e, n);
  }
  return std::pow(static_cast<long double>(inner), 1.0l / n);
}

template <int dim, class Real>
auto Vector<dim, Real>::reduce_dimension() const -> Vector<dim - 1, Real> {
  auto p = std::array<Real, dim - 1>();
  for(auto i = 0; i < dim - 1; ++i) {
    p[i] = (*this)[i];
  }
  return Vector<dim - 1, Real>(std::move(p));
}

template <int dim, class Real>
inline Vector<dim, Real>::Vector(std::array<Real, dim> const& p) : p_(p) {
}

template <int dim, class Real>
inline Vector<dim, Real>::Vector(std::array<Real, dim>&& p) : p_(std::move(p)) {
}

template <int dim, class Real>
auto operator<<(std::ostream& os, Vector<dim, Real> const& vector)
  -> std::ostream& {
  os << "(";
  for(auto i = 0; i < dim; ++i) {
    if(i != 0) os << ", ";
    os << vector[i];
  }
  return os << ")";
}
}

namespace std {
template <>
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
