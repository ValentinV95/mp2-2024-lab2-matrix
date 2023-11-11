#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(10);
	v[5] = 17;
	TDynamicVector<int> v_copy(v);
	EXPECT_EQ(v, v_copy);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{

	TDynamicVector<int> v(10);
	TDynamicVector<int> v_copy(v);
	v_copy[7] = 19;
	EXPECT_NE(19,v[7]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(-5)=7);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(11) = 7);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(5);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(5);
	v1[3] = 7;
	v2[4] = 8;
	v2 = v1;
	EXPECT_NE(v2[4], 8);
	EXPECT_EQ(v1[3], v2[3]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(7);
	v2 = v1;
	EXPECT_EQ(v2.size(), 5);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size_without_throw)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(7);
	v1[3] = 7;
	v2[4] = 8;
	ASSERT_NO_THROW(v2 = v1);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size_correct)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(7);
	v1[3] = 7;
	v2[4] = 8;
	v2 = v1;
	EXPECT_NE(v2[4], 8);
	EXPECT_EQ(v1[3], v2[3]);

}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(5);
	v1[3] = 7;
	v2[3] = 7;
	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v1(5);
	v1[3] = 7;
	EXPECT_EQ(v1, v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(7);
	EXPECT_NE(v2, v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(v + 5);
}

TEST(TDynamicVector, correct_add_scalar_to_vector)
{
	TDynamicVector<int> v1(2);
	v1[0] = 7;
	int a = 5;
	v1 = v1 + a;
	TDynamicVector<int> v2(2);
	v2[0] = 12;
	v2[1] = 5;
	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_subtract_scalar_to_vector)
{
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(v - 5);
}

TEST(TDynamicVector, correct_subtract_scalar_from_vector)
{
	TDynamicVector<int> v1(2);
	v1[0] = 7;
	int a = 5;
	v1 = v1 - a;
	TDynamicVector<int> v2(2);
	v2[0] = 2;
	v2[1] = -5;
	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_multiply_scalar_to_vector)
{
	TDynamicVector<int> v(3);
	ASSERT_NO_THROW(v * 5);
}

TEST(TDynamicVector, correct_multiply_scalar_by_vector)
{
	TDynamicVector<int> v1(2);
	v1[0] = 7;
	int a = 5;
	v1 = v1 * a;
	TDynamicVector<int> v2(2);
	v2[0] = 35;
	v2[1] = 0;
	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	ASSERT_NO_THROW(v2 + v1);
}

TEST(TDynamicVector, correct_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	v1[0] = 5;
	v1[1] = 7;
	v2 = v1;
	v2 = v2 + v1;
	EXPECT_EQ(v2[0], 10);
	EXPECT_EQ(14, v2[1]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(3);
	ASSERT_ANY_THROW(v1+v2);
}

TEST(TDynamicVector, can_substract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	ASSERT_NO_THROW(v2 - v1);
}

TEST(TDynamicVector, correct_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	v1[0] = 5;
	v1[1] = 7;
	v2[0] = 3;
	v2[1] = 8;
	v2 = v2 - v1;
	EXPECT_EQ(v2[0], -2);
	EXPECT_EQ(1, v2[1]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(3);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	ASSERT_NO_THROW(v2 * v1);
}

TEST(TDynamicVector, correct_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	int res;
	v1[0] = 1;
	v1[1] = 7;
	v2[0] = 4;
	v2[1] = 3;
	res = v2 * v1;
	EXPECT_EQ(res,25);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(3);
	ASSERT_ANY_THROW(v1 * v2);
}

