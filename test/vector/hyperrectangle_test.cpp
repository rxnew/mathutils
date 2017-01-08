#include "gtest/gtest.h"

#include "vector/hyperrectangle.hpp"

using Vector2i = mathutils::Vector<2, int>;
using Vector3i = mathutils::Vector<3, int>;
using Hyperrectangle2i = mathutils::Hyperrectangle<2, int>;
using Hyperrectangle3i = mathutils::Hyperrectangle<3, int>;

class Hyperrectangle3iTest : public ::testing::Test {
 protected:
  Hyperrectangle3iTest() : hyperrectangle3i_(1, 2, 3, 4, 5, 6) {}

  Hyperrectangle3i hyperrectangle3i_;
};

TEST_F(Hyperrectangle3iTest, Constructor) {
  EXPECT_EQ(hyperrectangle3i_.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i_.get_position(), Vector3i(4, 5, 6));

  Hyperrectangle3i hyperrectangle3i_a(1, 2, 3);
  EXPECT_EQ(hyperrectangle3i_a.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i_a.get_position(), Vector3i(0, 0, 0));

  Hyperrectangle3i hyperrectangle3i_b(Vector3i(1, 2, 3), Vector3i(4, 5, 6));
  EXPECT_EQ(hyperrectangle3i_b.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i_b.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Hyperrectangle3iTest, DefaultConstructor) {
  auto hyperrectangle3i = Hyperrectangle3i();
  EXPECT_EQ(hyperrectangle3i.get_size(), Vector3i(0, 0, 0));
  EXPECT_EQ(hyperrectangle3i.get_position(), Vector3i(0, 0, 0));
}

TEST_F(Hyperrectangle3iTest, CopyConstructor) {
  auto hyperrectangle3i = hyperrectangle3i_;
  EXPECT_EQ(hyperrectangle3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Hyperrectangle3iTest, MoveConstructor) {
  auto hyperrectangle3i_t = hyperrectangle3i_;
  auto hyperrectangle3i = std::move(hyperrectangle3i_);
  EXPECT_EQ(hyperrectangle3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Hyperrectangle3iTest, CopyAssignment) {
  auto hyperrectangle3i = Hyperrectangle3i();
  hyperrectangle3i = hyperrectangle3i_;
  EXPECT_EQ(hyperrectangle3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Hyperrectangle3iTest, MoveAssignment) {
  auto hyperrectangle3i_t = hyperrectangle3i_;
  auto hyperrectangle3i = Hyperrectangle3i();
  hyperrectangle3i = std::move(hyperrectangle3i_t);
  EXPECT_EQ(hyperrectangle3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Hyperrectangle3iTest, Equals) {
  auto hyperrectangle3i = hyperrectangle3i_;
  EXPECT_EQ(hyperrectangle3i_, hyperrectangle3i);
}

TEST_F(Hyperrectangle3iTest, NotEquals) {
  auto hyperrectangle3i_a = Hyperrectangle3i(1, 2, 0, 4, 5, 6);
  auto hyperrectangle3i_b = Hyperrectangle3i(1, 2, 3, 4, 5, 0);
  EXPECT_NE(hyperrectangle3i_, hyperrectangle3i_a);
  EXPECT_NE(hyperrectangle3i_, hyperrectangle3i_b);
}

TEST_F(Hyperrectangle3iTest, SetSize) {
  auto hyperrectangle3i = hyperrectangle3i_;
  hyperrectangle3i.set_size(Vector3i(0, 0, 0));
  EXPECT_EQ(hyperrectangle3i.get_size(), Vector3i(0, 0, 0));
  EXPECT_EQ(hyperrectangle3i.get_position(), Vector3i(4, 5, 6));
}

TEST_F(Hyperrectangle3iTest, SetPosition) {
  auto hyperrectangle3i = hyperrectangle3i_;
  hyperrectangle3i.set_position(Vector3i(0, 0, 0));
  EXPECT_EQ(hyperrectangle3i.get_size(), Vector3i(1, 2, 3));
  EXPECT_EQ(hyperrectangle3i.get_position(), Vector3i(0, 0, 0));
}

TEST_F(Hyperrectangle3iTest, MakeAntigoglinPosition) {
  auto hyperrectangle3i = hyperrectangle3i_;
  auto position = hyperrectangle3i.make_antigoglin_position();
  EXPECT_EQ(position, Vector3i(5, 7, 9));
}

TEST_F(Hyperrectangle3iTest, ReduceDimension) {
  auto hyperrectangle2i = hyperrectangle3i_.reduce_dimension();
  EXPECT_EQ(hyperrectangle2i.get_size(), Vector2i(1, 2));
  EXPECT_EQ(hyperrectangle2i.get_position(), Vector2i(4, 5));
}

TEST_F(Hyperrectangle3iTest, IsIntersected) {
  auto hyperrectangle3i_a = Hyperrectangle3i(3, 3, 3, 0, 0, 0);
  auto hyperrectangle3i_b = Hyperrectangle3i(3, 3, 3, 3, 0, 0);
  auto hyperrectangle3i_c = Hyperrectangle3i(3, 3, 3, 0, 3, 0);
  auto hyperrectangle3i_d = Hyperrectangle3i(3, 3, 3, 0, 0, 3);
  auto hyperrectangle3i_e = Hyperrectangle3i(3, 3, 3, 2, 0, 0);
  auto hyperrectangle3i_f = Hyperrectangle3i(3, 3, 3, 0, 2, 0);
  auto hyperrectangle3i_g = Hyperrectangle3i(3, 3, 3, 0, 0, 2);
  EXPECT_FALSE(hyperrectangle3i_a.is_intersected(hyperrectangle3i_b));
  EXPECT_FALSE(hyperrectangle3i_b.is_intersected(hyperrectangle3i_a));
  EXPECT_FALSE(hyperrectangle3i_a.is_intersected(hyperrectangle3i_c));
  EXPECT_TRUE(hyperrectangle3i_a.is_intersected(hyperrectangle3i_e));
  EXPECT_TRUE(hyperrectangle3i_e.is_intersected(hyperrectangle3i_a));
  EXPECT_TRUE(hyperrectangle3i_a.is_intersected(hyperrectangle3i_f));
  EXPECT_TRUE(hyperrectangle3i_a.is_intersected(hyperrectangle3i_g));
}
