#pragma once

#include "vector.hpp"

namespace mathutils {
template <int dim, class RealType = float,
          template <int, class> class VectorT = Vector>
class Hyperrectangle {
 public:
  using Dimension = std::integral_constant<int, dim>;
  using Real = RealType;
  using Vector = VectorT<dim, Real>;

  Hyperrectangle() = default;
  Hyperrectangle(Vector const& size, Vector const& position);
  explicit Hyperrectangle(Vector&& size, Vector&& position);
  explicit Hyperrectangle(Vector const& size);
  Hyperrectangle(Vector&& size);
  template <class... Args>
  explicit Hyperrectangle(Real arg, Args&&... args);
  Hyperrectangle(Hyperrectangle const&) = default;
  Hyperrectangle(Hyperrectangle&&) noexcept = default;
  virtual ~Hyperrectangle() noexcept = default;

  auto operator=(Hyperrectangle const&) -> Hyperrectangle& = default;
  auto operator=(Hyperrectangle&&) noexcept -> Hyperrectangle& = default;
  auto operator==(Hyperrectangle const& other) const -> bool;
  auto operator!=(Hyperrectangle const& other) const -> bool;

  auto get_size() const -> Vector const&;
  auto get_position() const -> Vector const&;
  auto set_size(Vector const& size) -> void;
  auto set_position(Vector const& position) -> void;
  auto make_antigoglin_position() const -> Vector;
  auto reduce_dimension() const -> Hyperrectangle<dim - 1, Real, VectorT>;
  auto is_intersected(Vector const& position) const -> bool;
  auto is_intersected(Hyperrectangle const& other) const -> bool;

 protected:
  Vector size_;
  Vector position_;

 private:
  template <class... Args>
  auto _set_args(int i, Real arg, Args&&... args) -> void;
  auto _set_args(int i) -> void;
};
}

#include "hyperrectangle/hyperrectangle_impl.hpp"
#include "hyperrectangle/hash.hpp"
