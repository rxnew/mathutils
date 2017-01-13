#pragma once

namespace mathutils {
template <int dim, class Real, template <int, class> class VectorT>
Hyperrectangle<dim, Real, VectorT>::
Hyperrectangle(Vector const& size, Vector const& position)
  : size_(size), position_(position) {
}

template <int dim, class Real, template <int, class> class VectorT>
Hyperrectangle<dim, Real, VectorT>::
Hyperrectangle(Vector&& size, Vector&& position)
  : size_(std::move(size)), position_(std::move(position)) {
}

template <int dim, class Real, template <int, class> class VectorT>
Hyperrectangle<dim, Real, VectorT>::
Hyperrectangle(Vector const& size)
  : size_(size), position_() {
}

template <int dim, class Real, template <int, class> class VectorT>
Hyperrectangle<dim, Real, VectorT>::
Hyperrectangle(Vector&& size)
  : size_(std::move(size)), position_() {
}

template <int dim, class Real, template <int, class> class VectorT>
template <class... Args>
Hyperrectangle<dim, Real, VectorT>::
Hyperrectangle(Real arg, Args&&... args) {
  _set_args(0, arg, std::forward<Args>(args)...);
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
operator==(Hyperrectangle const& other) const -> bool {
  return size_ == other.size_ && position_ == other.position_;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
operator!=(Hyperrectangle const& other) const -> bool {
  return !(*this == other);
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
get_size() const -> Vector const& {
  return size_;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
get_position() const -> Vector const& {
  return position_;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
set_size(Vector const& size) -> void {
  size_ = size;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
set_position(Vector const& position) -> void {
  position_ = position;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
antigoglin_position() const -> Vector {
  return size_ + position_;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
surface_area() const -> Real {
  auto surface_area = Real(0);
  for(auto i = 0; i < dim; ++i) {
    surface_area += size_[i] * size_[(i + 1) % dim];
  }
  return surface_area * 2;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
volume() const -> Real {
  auto volume = Real(1);
  for(auto i = 0; i < dim; ++i) {
    volume *= size_[i];
  }
  return volume;
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
base() const -> Hyperrectangle<dim - 1, Real, VectorT> {
  return Hyperrectangle<dim - 1, Real, VectorT>(size_.reduce_dimension(),
                                                position_.reduce_dimension());
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
is_intersected(Vector const& position) const -> bool {
  return is_intersected(Hyperrectangle(Vector(), position));
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
is_intersected(Hyperrectangle const& other) const -> bool {
  for(auto i = 0; i < dim; ++i) {
    if(position_[i] >= other.position_[i] + other.size_[i] ||
       position_[i] + size_[i] <= other.position_[i]) return false;
  }
  return true;
}

template <int dim, class Real, template <int, class> class VectorT>
template <class... Args>
auto Hyperrectangle<dim, Real, VectorT>::
_set_args(int i, Real arg, Args&&... args) -> void {
  if(i == dim << 1) return;
  if(i < dim) size_[i]           = arg;
  else        position_[i - dim] = arg;
  _set_args(i + 1, std::forward<Args>(args)...);
}

template <int dim, class Real, template <int, class> class VectorT>
auto Hyperrectangle<dim, Real, VectorT>::
_set_args(int i) -> void {
  return;
}
}
