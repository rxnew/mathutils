#include "gtest/gtest.h"

#include "vector/polyhedron.hpp"

using Vector2i = mathutils::Vector<2, int>;
using Vector3i = mathutils::Vector<3, int>;
using Polyhedron2i = mathutils::Polyhedron<2, int>;
using Polyhedron3i = mathutils::Polyhedron<3, int>;

class Polyhedron3iTest : public ::testing::Test {
 protected:
  Polyhedron3iTest() : polyhedron3i_(1, 2, 3, 4, 5, 6) {}

  Polyhedron3i polyhedron3i_;
};

TEST_F(Polyhedron3iTest, Constructor) {
  EXPECT_EQ(polyhedron3i_.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i_.get_position(), Vector3i(4, 5, 6));

  Polyhedron3i polyhedron3i_a(1, 2, 3);
  EXPECT_EQ(polyhedron3i_a.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i_a.get_position(), Vector3i(0, 0, 0));

  Polyhedron3i polyhedron3i_b(Vector3i(1, 2, 3), Vector3i(4, 5, 6));
  EXPECT_EQ(polyhedron3i_b.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i_b.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Polyhedron3iTest, DefaultConstructor) {
  auto polyhedron3i = Polyhedron3i();
  EXPECT_EQ(polyhedron3i.get_size(), Vector3i(0, 0, 0));
  EXPECT_EQ(polyhedron3i.get_position(), Vector3i(0, 0, 0));
}

TEST_F(Polyhedron3iTest, CopyConstructor) {
  auto polyhedron3i = polyhedron3i_;
  EXPECT_EQ(polyhedron3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Polyhedron3iTest, MoveConstructor) {
  auto polyhedron3i_t = polyhedron3i_;
  auto polyhedron3i = std::move(polyhedron3i_);
  EXPECT_EQ(polyhedron3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Polyhedron3iTest, CopyAssignment) {
  auto polyhedron3i = Polyhedron3i();
  polyhedron3i = polyhedron3i_;
  EXPECT_EQ(polyhedron3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Polyhedron3iTest, MoveAssignment) {
  auto polyhedron3i_t = polyhedron3i_;
  auto polyhedron3i = Polyhedron3i();
  polyhedron3i = std::move(polyhedron3i_t);
  EXPECT_EQ(polyhedron3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Polyhedron3iTest, Equals) {
  auto polyhedron3i = polyhedron3i_;
  EXPECT_EQ(polyhedron3i_, polyhedron3i);
}

TEST_F(Polyhedron3iTest, NotEquals) {
  auto polyhedron3i_a = Polyhedron3i(1, 2, 0, 4, 5, 6);
  auto polyhedron3i_b = Polyhedron3i(1, 2, 3, 4, 5, 0);
  EXPECT_NE(polyhedron3i_, polyhedron3i_a);
  EXPECT_NE(polyhedron3i_, polyhedron3i_b);
}

TEST_F(Polyhedron3iTest, SetSize) {
  auto polyhedron3i = polyhedron3i_;
  polyhedron3i.set_size(Vector3i(0, 0, 0));
  EXPECT_EQ(polyhedron3i.get_size(), Vector3i(0, 0, 0));
  EXPECT_EQ(polyhedron3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Polyhedron3iTest, SetPosition) {
  auto polyhedron3i = polyhedron3i_;
  polyhedron3i.set_position(Vector3i(0, 0, 0));
  EXPECT_EQ(polyhedron3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(polyhedron3i.get_position(), Vector3i(0, 0, 0));
}

TEST_F(Polyhedron3iTest, MakeAntigoglinPosition) {
  auto polyhedron3i = polyhedron3i_;
  auto position = polyhedron3i.make_antigoglin_position();
  EXPECT_EQ(position, Vector3i(5, 7, 9));
}

TEST_F(Polyhedron3iTest, ReduceDimension) {
  auto polyhedron2i = polyhedron3i_.reduce_dimension();
  EXPECT_EQ(polyhedron2i.get_size(), Vector2i(1, 2));
  EXPECT_EQ(polyhedron2i.get_position(), Vector2i(4, 5));
}

TEST_F(Polyhedron3iTest, IsIntersected) {
  auto polyhedron3i_a = Polyhedron3i(3, 3, 3, 0, 0, 0);
  auto polyhedron3i_b = Polyhedron3i(3, 3, 3, 3, 0, 0);
  auto polyhedron3i_c = Polyhedron3i(3, 3, 3, 0, 3, 0);
  auto polyhedron3i_d = Polyhedron3i(3, 3, 3, 0, 0, 3);
  auto polyhedron3i_e = Polyhedron3i(3, 3, 3, 2, 0, 0);
  auto polyhedron3i_f = Polyhedron3i(3, 3, 3, 0, 2, 0);
  auto polyhedron3i_g = Polyhedron3i(3, 3, 3, 0, 0, 2);
  EXPECT_FALSE(polyhedron3i_a.is_intersected(polyhedron3i_b));
  EXPECT_FALSE(polyhedron3i_b.is_intersected(polyhedron3i_a));
  EXPECT_FALSE(polyhedron3i_a.is_intersected(polyhedron3i_c));
  EXPECT_TRUE(polyhedron3i_a.is_intersected(polyhedron3i_e));
  EXPECT_TRUE(polyhedron3i_e.is_intersected(polyhedron3i_a));
  EXPECT_TRUE(polyhedron3i_a.is_intersected(polyhedron3i_f));
  EXPECT_TRUE(polyhedron3i_a.is_intersected(polyhedron3i_g));
}
