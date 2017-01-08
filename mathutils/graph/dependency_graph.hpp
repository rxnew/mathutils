/**
 * @file dependency_graph.hpp
 * @brief header of DependencyGraph class
 */

#pragma once

#include "directed_graph.hpp"
#include "dependency_graph/dependencies.hpp"
#include "util/footprints.hpp"

namespace mathutils {
template <class V,
          class Dependency = dependencies::Default<V>,
          class Hash = std::hash<V>>
class DependencyGraph : public DirectedGraph<V> {
 protected:
  using Super = DirectedGraph<V>;

 public:
  using Vertex = V;
  using Vertices = typename Super::Vertices;
  using AdjacencyList = typename Super::AdjacencyList;

  explicit DependencyGraph(const Dependency& dependency = Dependency(),
                           const Hash& hash = Hash());
  explicit DependencyGraph(size_t size,
                           const Dependency& dependency = Dependency(),
                           const Hash& hash = Hash());
  explicit DependencyGraph(const Vertices& vertices,
                           const Dependency& dependency = Dependency(),
                           const Hash& hash = Hash());
  DependencyGraph(const DependencyGraph&) = default;
  DependencyGraph(DependencyGraph&&) noexcept = default;
  virtual ~DependencyGraph() = default;

  auto operator=(const DependencyGraph&) -> DependencyGraph& = default;
  auto operator=(DependencyGraph&&) noexcept -> DependencyGraph& = default;

  virtual auto add_vertex(const Vertex& v) -> void final;
  virtual auto remove_vertex(const Vertex& v) -> void final;
  virtual auto collect_source_vertices() const -> Vertices;
  auto get_independent_vertices() const -> const Vertices&;
  auto count_dependent_vertices(const Vertex& v) const -> int;
  template <template <class...> class Container>
  auto count_dependent_vertices(const Container<Vertex>& vertices) const -> int;

 protected:
  Dependency dependency_;
  Hash hash_;
  Vertices independent_vertices_;
  mutable util::Footprints<Vertex, Hash> footprints_;

  virtual auto add_edge(const Vertex& v, const Vertex& u) -> void final;
  virtual auto remove_edge(const Vertex& v, const Vertex& u) -> void final;
  auto _add_vertex(const Vertex& v, const Vertex& pos) -> bool;
  template <template <class...> class Container>
  auto _count_dependent_vertices(const Container<Vertex>& vertices) const
    -> int;
};
}

#include "dependency_graph/dependency_graph_impl.hpp"
