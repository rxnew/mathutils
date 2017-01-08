#pragma once

namespace mathutils {
template <int dim, class Real, class VectorT>
Polyhedron<dim, Real, VectorT>::
Polyhedron(Vector const& size, Vector const& position)
  : size_(size), position_(position) {
}

template <int dim, class Real, class VectorT>
Polyhedron<dim, Real, VectorT>::
Polyhedron(Vector&& size, Vector&& position)
  : size_(std::move(size)), position_(std::move(position)) {
}

template <int dim, class Real, class VectorT>
template <class T, class... Args, class>
Polyhedron<dim, Real, VectorT>::
Polyhedron(T&& t, Args&&... args) {
  _set_args(0, std::forward<T>(t), std::forward<Args>(args)...);
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
operator==(Polyhedron const& other) const -> bool {
  return size_ == other.size_ && position_ == other.position_;
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
operator!=(Polyhedron const& other) const -> bool {
  return !(*this == other);
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
get_size() const -> Vector const& {
  return size_;
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
get_position() const -> Vector const& {
  return position_;
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
set_size(Vector const& size) -> void {
  size_ = size;
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
set_position(Vector const& position) -> void {
  position_ = position;
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
make_antigoglin_position() const -> Vector const& {
  return size_ + position_;
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
reduce_dimension() const -> Polyhedron<dim - 1, Real, VectorT> {
  return Polyhedron<dim - 1, Real, VectorT>(size_.reduce_dimension(),
                                            position_.reduce_dimension());
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
is_intersected(Vector const& position) const -> bool {
  return is_intersected(Polyhedron(Vector(), position));
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
is_intersected(Polyhedron const& other) const -> bool {
  auto const antigoglin_position = other.make_antigoglin_position();
  for(auto i = 0; i < dim; ++i) {
    if(position_[i] >= antigoglin_position[i]) return false;
  }
  return other.is_intersected(*this);
}

template <int dim, class Real, class VectorT>
template <class T, class... Args>
auto Polyhedron<dim, Real, VectorT>::
_set_args(int i, T&& t, Args&&... args) -> void {
  if(i == dim << 1) return;
  if(i < dim) size_[i]           = std::forward<T>(t);
  else        position_[i - dim] = std::forward<T>(t);
  _set_args(i + 1, std::forward<Args>(args)...);
}

template <int dim, class Real, class VectorT>
auto Polyhedron<dim, Real, VectorT>::
_set_args(int i) -> void {
  return;
}
}

namespace std {
template <>
template <int dim, class Real, class VectorT>
auto hash<mathutils::Polyhedron<dim, Real, VectorT>>::
operator()(mathutils::Polyhedron<dim, Real, VectorT> const& obj) const noexcept
  -> size_t {
  using Vector = mathutils::Polyhedron<dim, Real, VectorT>::Vector;
  return hash<Vector>(obj.get_size()) ^ hash<Vector>(obj.get_position());
}
}
