#include "gtest/gtest.h"

#include "vector/vector.hpp"

using Vector2i = mathutils::Vector<2, int>;
using Vector2d = mathutils::Vector<2, double>;
using Vector3i = mathutils::Vector<3, int>;

template <class Real>
constexpr auto const err = static_cast<Real>(0.00001);

class Vector3iTest : public ::testing::Test {
 protected:
  Vector3iTest() : vector3i_(1, 2, 3) {}

  Vector3i vector3i_;
};

TEST_F(Vector3iTest, Constructor) {
  EXPECT_EQ(vector3i_[0], 1);
  EXPECT_EQ(vector3i_[1], 2);
  EXPECT_EQ(vector3i_[2], 3);
}

TEST_F(Vector3iTest, DefaultConstructor) {
  auto vector3i = Vector3i();
  EXPECT_EQ(vector3i[0], 0);
  EXPECT_EQ(vector3i[1], 0);
  EXPECT_EQ(vector3i[2], 0);
}

TEST_F(Vector3iTest, CopyConstructor) {
  auto vector3i = vector3i_;
  EXPECT_EQ(vector3i[0], 1);
  EXPECT_EQ(vector3i[1], 2);
  EXPECT_EQ(vector3i[2], 3);
}

TEST_F(Vector3iTest, MoveConstructor) {
  auto vector3i_t = vector3i_;
  auto vector3i = std::move(vector3i_);
  EXPECT_EQ(vector3i[0], 1);
  EXPECT_EQ(vector3i[1], 2);
  EXPECT_EQ(vector3i[2], 3);
}

TEST_F(Vector3iTest, CopyAssignment) {
  auto vector3i = Vector3i();
  vector3i = vector3i_;
  EXPECT_EQ(vector3i[0], 1);
  EXPECT_EQ(vector3i[1], 2);
  EXPECT_EQ(vector3i[2], 3);
}

TEST_F(Vector3iTest, MoveAssignment) {
  auto vector3i_t = vector3i_;
  auto vector3i = Vector3i();
  vector3i = std::move(vector3i_t);
  EXPECT_EQ(vector3i[0], 1);
  EXPECT_EQ(vector3i[1], 2);
  EXPECT_EQ(vector3i[2], 3);
}

TEST_F(Vector3iTest, Equals) {
  auto vector3i = vector3i_;
  EXPECT_EQ(vector3i_, vector3i);
}

TEST_F(Vector3iTest, NotEquals) {
  auto vector3i = Vector3i(1, 2, 0);
  EXPECT_NE(vector3i_, vector3i);
}

TEST_F(Vector3iTest, LessThan) {
  EXPECT_LT(vector3i_, Vector3i(0, 0, 4));
  EXPECT_LT(vector3i_, Vector3i(0, 3, 3));
  EXPECT_LT(vector3i_, Vector3i(2, 2, 3));
}

TEST_F(Vector3iTest, GreaterThan) {
  EXPECT_GT(vector3i_, Vector3i(4, 4, 2));
  EXPECT_GT(vector3i_, Vector3i(4, 1, 3));
  EXPECT_GT(vector3i_, Vector3i(0, 2, 3));
}

TEST_F(Vector3iTest, Plus) {
  auto vector3i = Vector3i(1, 2, 3) + Vector3i(4, 5, 6);
  EXPECT_EQ(vector3i, Vector3i(5, 7, 9));
}

TEST_F(Vector3iTest, Minus) {
  auto vector3i = Vector3i(4, 5, 6) - Vector3i(1, 2, 3);
  EXPECT_EQ(vector3i, Vector3i(3, 3, 3));
}

TEST_F(Vector3iTest, Times) {
  auto vector3i = vector3i_ * 2;
  EXPECT_EQ(vector3i, Vector3i(2, 4, 6));
}

TEST_F(Vector3iTest, Iterator) {
  auto i = 0;
  for(auto it = std::begin(vector3i_); it != std::end(vector3i_); ++it) {
    EXPECT_EQ(*it, vector3i_[i++]);
    EXPECT_FALSE(std::is_const<std::remove_reference_t<decltype(*it)>>::value);
  }
}

TEST_F(Vector3iTest, ConstIterator) {
  auto i = 0;
  for(auto it = std::cbegin(vector3i_); it != std::cend(vector3i_); ++it) {
    EXPECT_EQ(*it, vector3i_[i++]);
    EXPECT_TRUE(std::is_const<std::remove_reference_t<decltype(*it)>>::value);
  }
}

TEST_F(Vector3iTest, ReverseIterator) {
  auto i = 2;
  for(auto it = std::rbegin(vector3i_); it != std::rend(vector3i_); ++it) {
    EXPECT_EQ(*it, vector3i_[i--]);
    EXPECT_FALSE(std::is_const<std::remove_reference_t<decltype(*it)>>::value);
  }
}

TEST_F(Vector3iTest, ConstReverseIterator) {
  auto i = 2;
  for(auto it = std::crbegin(vector3i_); it != std::crend(vector3i_); ++it) {
    EXPECT_EQ(*it, vector3i_[i--]);
    EXPECT_TRUE(std::is_const<std::remove_reference_t<decltype(*it)>>::value);
  }
}

TEST_F(Vector3iTest, ReduceDimension) {
  auto vector2i = vector3i_.reduce_dimension();
  EXPECT_EQ(vector2i, Vector2i(1, 2));
}

TEST(Vector2Test, Norm) {
  auto vector2i_a = Vector2i(3, 4);
  auto vector2i_b = Vector2i(1, 1);
  auto vector2i_a_norm = vector2i_a.norm();
  auto vector2i_b_norm = vector2i_b.norm();
  EXPECT_EQ(vector2i_a_norm, 5.0f);
  EXPECT_LT(std::abs(vector2i_b_norm - std::sqrt(2.0f)), err<float>);

  auto vector2d_a = Vector2d(3.0, 4.0);
  auto vector2d_b = Vector2d(1.0, 1.0);
  auto vector2d_a_norm = vector2d_a.norm();
  auto vector2d_b_norm = vector2d_b.norm();
  EXPECT_EQ(vector2d_a_norm, 5.0);
  EXPECT_LT(std::abs(vector2d_b_norm - std::sqrt(2.0)), err<double>);
}
