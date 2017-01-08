#pragma once

#include <array>
#include <sstream>

namespace mathutils {
template <int dim, class Real = float>
class Vector {
 private:
  using Array = std::array<Real, dim>;

 public:
  using iterator = typename Array::iterator;
  using const_iterator = typename Array::const_iterator;
  using reverse_iterator = typename Array::reverse_iterator;
  using const_reverse_iterator = typename Array::const_reverse_iterator;

  Vector();
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

  auto begin() noexcept -> iterator;
  auto begin() const noexcept -> const_iterator;
  auto end() noexcept -> iterator;
  auto end() const noexcept -> const_iterator;
  auto cbegin() const noexcept -> const_iterator;
  auto cend() const noexcept -> const_iterator;
  auto rbegin() noexcept -> reverse_iterator;
  auto rbegin() const noexcept -> const_reverse_iterator;
  auto rend() noexcept -> reverse_iterator;
  auto rend() const noexcept -> const_reverse_iterator;
  auto crbegin() const noexcept -> const_reverse_iterator;
  auto crend() const noexcept -> const_reverse_iterator;
  auto dimension() const -> int;
  template <class T = Real,
            std::enable_if_t<std::is_floating_point<T>::value,
                             std::nullptr_t> = nullptr>
  auto norm(int n = 2) const -> Real;
  template <class T = Real,
            std::enable_if_t<!std::is_floating_point<T>::value,
                             std::nullptr_t> = nullptr>
  auto norm(int n = 2) const -> long double;
  auto reduce_dimension() const -> Vector<dim - 1, Real>;

 protected:
  Vector(Array const& p);
  Vector(Array&& p);

  Array p_;
};

using Vector1d = Vector<1>;
using Vector2d = Vector<2>;

template <int dim, class Real>
auto operator<<(std::ostream& os, Vector<dim, Real> const& vector)
  -> std::ostream&;
}

#include "vector/vector_impl.hpp"
#include "vector/hash.hpp"
