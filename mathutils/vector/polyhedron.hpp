#pragma once

#include "vector.hpp"

namespace mathutils {
template <int dim, class Real = float, class VectorType = Vector<dim, Real>>
class Polyhedron {
 public:
  using Vector = VectorType;

  Polyhedron() = default;
  Polyhedron(Vector const& size, Vector const& position);
  Polyhedron(Vector&& size, Vector&& position);
  template <class T, class... Args,
            class = std::enable_if_t<!std::is_convertible<T, Polyhedron>::value>>
  explicit Polyhedron(T&& t, Args&&... args);
  Polyhedron(Polyhedron const&) = default;
  Polyhedron(Polyhedron&&) noexcept = default;
  virtual ~Polyhedron() noexcept = default;

  auto operator=(Polyhedron const&) -> Polyhedron& = default;
  auto operator=(Polyhedron&&) noexcept -> Polyhedron& = default;
  auto operator==(Polyhedron const& other) const -> bool;
  auto operator!=(Polyhedron const& other) const -> bool;

  auto get_size() const -> Vector const&;
  auto get_position() const -> Vector const&;
  auto set_size(Vector const& size) -> void;
  auto set_position(Vector const& position) -> void;
  auto make_antigoglin_position() const -> Vector const&;
  auto reduce_dimension() const -> Polyhedron<dim - 1, Real, Vector>;
  auto is_intersected(Vector const& position) const -> bool;
  auto is_intersected(Polyhedron const& other) const -> bool;

 protected:
  Vector size_;
  Vector position_;

 private:
  template <class T, class... Args>
  auto _set_args(int i, T&& t, Args&&... args) -> void;
  auto _set_args(int i) -> void;
};
}

namespace std {
template <>
template <int dim, class Real, class Vector>
struct hash<mathutils::Polyhedron<dim, Real, Vector>> {
  auto operator()(mathutils::Polyhedron<dim, Real, Vector> const& obj)
    const noexcept -> size_t;
};
}

#include "polyhedron/polyhedron_impl.hpp"
