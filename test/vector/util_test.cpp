#include "gtest/gtest.h"

#include "vector/util.hpp"

using namespace mathutils::vector_accessors;

using Vector1i = mathutils::Vector<1, int>;
using Vector2i = mathutils::Vector<2, int>;
using Vector3i = mathutils::Vector<3, int>;
using Vector4i = mathutils::Vector<4, int>;

using Hyperrectangle1i = mathutils::Hyperrectangle<1, int>;
using Hyperrectangle2i = mathutils::Hyperrectangle<2, int>;
using Hyperrectangle3i = mathutils::Hyperrectangle<3, int>;
using Hyperrectangle4i = mathutils::Hyperrectangle<4, int>;

class VectorAccessorsTest : public ::testing::Test {
 protected:
  VectorAccessorsTest() : vector1i_(1),
                          vector2i_(1, 2),
                          vector3i_(1, 2, 3),
                          vector4i_(1, 2, 3, 4) {}

  Vector1i vector1i_;
  Vector2i vector2i_;
  Vector3i vector3i_;
  Vector4i vector4i_;
};

class HyperrectangleAccessorsTest : public ::testing::Test {
 protected:
  HyperrectangleAccessorsTest() : hyperrectangle1i_(1, 5),
                                  hyperrectangle2i_(1, 2, 5, 6),
                                  hyperrectangle3i_(1, 2, 3, 5, 6, 7),
                                  hyperrectangle4i_(1, 2, 3, 4, 5, 6, 7, 8) {}

  Hyperrectangle1i hyperrectangle1i_;
  Hyperrectangle2i hyperrectangle2i_;
  Hyperrectangle3i hyperrectangle3i_;
  Hyperrectangle4i hyperrectangle4i_;
};

TEST_F(VectorAccessorsTest, GetX) {
  EXPECT_EQ(get_x(vector1i_), 1);
  EXPECT_EQ(get_x(vector2i_), 1);
  EXPECT_EQ(get_x(vector3i_), 1);
  EXPECT_EQ(get_x(vector4i_), 1);
}

TEST_F(VectorAccessorsTest, GetY) {
  EXPECT_EQ(get_y(vector2i_), 2);
  EXPECT_EQ(get_y(vector3i_), 2);
  EXPECT_EQ(get_y(vector4i_), 2);
}

TEST_F(VectorAccessorsTest, GetZ) {
  EXPECT_EQ(get_z(vector3i_), 3);
  EXPECT_EQ(get_z(vector4i_), 3);
}

TEST_F(HyperrectangleAccessorsTest, GetX) {
  EXPECT_EQ(get_x(hyperrectangle1i_), 5);
  EXPECT_EQ(get_x(hyperrectangle2i_), 5);
  EXPECT_EQ(get_x(hyperrectangle3i_), 5);
  EXPECT_EQ(get_x(hyperrectangle4i_), 5);
}

TEST_F(HyperrectangleAccessorsTest, GetY) {
  EXPECT_EQ(get_y(hyperrectangle2i_), 6);
  EXPECT_EQ(get_y(hyperrectangle3i_), 6);
  EXPECT_EQ(get_y(hyperrectangle4i_), 6);
}

TEST_F(HyperrectangleAccessorsTest, GetZ) {
  EXPECT_EQ(get_z(hyperrectangle3i_), 7);
  EXPECT_EQ(get_z(hyperrectangle4i_), 7);
}

TEST_F(HyperrectangleAccessorsTest, GetW) {
  EXPECT_EQ(get_w(hyperrectangle1i_), 1);
  EXPECT_EQ(get_w(hyperrectangle2i_), 1);
  EXPECT_EQ(get_w(hyperrectangle3i_), 1);
  EXPECT_EQ(get_w(hyperrectangle4i_), 1);
}

TEST_F(HyperrectangleAccessorsTest, GetH) {
  EXPECT_EQ(get_h(hyperrectangle2i_), 2);
  EXPECT_EQ(get_h(hyperrectangle3i_), 2);
  EXPECT_EQ(get_h(hyperrectangle4i_), 2);
}

TEST_F(HyperrectangleAccessorsTest, GetD) {
  EXPECT_EQ(get_d(hyperrectangle3i_), 3);
  EXPECT_EQ(get_d(hyperrectangle4i_), 3);
}
