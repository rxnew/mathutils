#pragma once

#include <array>
#include <sstream>

namespace mathutils {
template <int dim, class Real = float>
class Vector {
public:
  Vector() = default;
  template <class T, class... Args,
            class = std::enable_if_t<!std::is_convertible<T, Vector>::value>>
  explicit Vector(T&& t, Args&&... args);
  Vector(Vector const&) = default;
  Vector(Vector&&) noexcept = default;
  virtual ~Vector() noexcept = default;

  auto operator=(Vector const&) -> Vector& = default;
  auto operator=(Vector&&) noexcept -> Vector& = default;
  auto operator==(Vector const& other) const -> bool;
  auto operator!=(Vector const& other) const -> bool;
  auto operator<(Vector const& other) const -> bool;
  auto operator>(Vector const& other) const -> bool;
  auto operator+(Vector const& other) const -> Vector;
  auto operator-(Vector const& other) const -> Vector;
  auto operator*(Real const& n) const -> Vector;
  auto operator[](size_t n) -> Real&;
  auto operator[](size_t n) const -> Real const&;

  auto dimension() const -> int;
  template <class = std::enable_if_t<std::is_floating_point<Real>::value>>
  auto norm(int n = 2) const -> Real;
  template <class = std::enable_if_t<!std::is_floating_point<Real>::value>>
  auto norm(int n = 2) const -> long double;
  template <int dim, class Real = float>
  auto reduce_dimension() const -> Vector<dim - 1, Real>;
}

 protected:
  Vector(std::array<Real, dim> const& p);
  Vector(std::array<Real, dim>&& p);

  std::array<Real, dim> p_;
};

using Vector1d = Vector<1>;
using Vector2d = Vector<2>;

template <int dim, class Real>
auto operator<<(std::ostream& os, Vector<dim, Real> const& vector)
  -> std::ostream&;
}

namespace std {
template <>
template <int dim, class Real>
struct hash<mathutils::Vector<dim, Real>> {
  auto operator()(mathutils::Vector<dim, Real> const& obj) const noexcept
    -> size_t;
};
}

#include "vector/vector_impl.hpp"
