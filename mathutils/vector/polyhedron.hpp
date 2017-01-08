#pragma once

#include "vector.hpp"

namespace mathutils {
template <int dim, class Real = float,
          template <int, class> class VectorT = Vector>
class Polyhedron {
 public:
  using Vector = VectorT<dim, Real>;

  Polyhedron() = default;
  Polyhedron(Vector const& size, Vector const& position);
  Polyhedron(Vector&& size, Vector&& position);
  template <class... Args>
  explicit Polyhedron(Real arg, Args&&... args);
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
  auto make_antigoglin_position() const -> Vector;
  auto reduce_dimension() const -> Polyhedron<dim - 1, Real, VectorT>;
  auto is_intersected(Vector const& position) const -> bool;
  auto is_intersected(Polyhedron const& other) const -> bool;

 protected:
  Vector size_;
  Vector position_;

 private:
  template <class... Args>
  auto _set_args(int i, Real arg, Args&&... args) -> void;
  auto _set_args(int i) -> void;
};
}

#include "polyhedron/polyhedron_impl.hpp"
#include "polyhedron/hash.hpp"
