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
	int a[4] = { 2, 4, 6, 8 };
	int a1[4];
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(v);
	for (size_t i = 0; i < 4; i++) {
		a1[i] = v1[i];
	}
	for (size_t i = 0; i < 4; i++) {
		EXPECT_EQ(a[i], a1[i]);
	}
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(v);
	EXPECT_NE(&v[0], &v1[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	ASSERT_ANY_THROW(v.at(6));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(a, 4);
	v = v;
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(4);
	v1 = v;
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(7);
	v1 = v;
	EXPECT_EQ(v.size(), v1.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(7);
	v1 = v;
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(a, 4);
	ASSERT_NE(v == v1, 0);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	int a[4] = { 2, 4, 6, 8 };
	TDynamicVector<int> v(a, 4);
	EXPECT_NE(v == v, 0);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	int a[7] = { 2, 4, 6, 8, 0, 0, 0 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(a, 7);
	ASSERT_NE(v, v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	int a[4] = { 1, 3, 7, 8 };
	TDynamicVector<int> v(a, 4);
	v = v + 4;
	int a1[4];
	for (size_t i = 0; i < 4; i++) {
		a1[i] = a[i] + 4;
	}
	for (size_t i = 0; i < 4; i++) {
		EXPECT_EQ(v[i], a1[i]);
	}
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	int a[4] = { 1, 3, 7, 8 };
	TDynamicVector<int> v(a, 4);
	v = v - 4;
	int a1[4];
	for (size_t i = 0; i < 4; i++) {
		a1[i] = a[i] - 4;
	}
	for (size_t i = 0; i < 4; i++) {
		EXPECT_EQ(v[i], a1[i]);
	}
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int a[4] = { 1, 3, 7, 8 };
	TDynamicVector<int> v(a, 4);
	v = v * 7;
	int a1[4];
	for (size_t i = 0; i < 4; i++) {
		a1[i] = a[i] * 7;
	}
	for (size_t i = 0; i < 4; i++) {
		EXPECT_EQ(v[i], a1[i]);
	}
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	int a[4] = { 1, 3, 7, 8 };
	int b[4] = { 2, 4, 10, 1 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(b, 4);
	v = v + v1;
	int a1[4];
	for (size_t i = 0; i < 4; i++) {
		a1[i] = a[i] + b[i];
	}
	for (size_t i = 0; i < 4; i++) {
		EXPECT_EQ(v[i], a1[i]);
	}
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	int a[4] = { 1, 3, 7, 8 };
	int b[5] = { 2, 4, 10, 1, 0 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(b, 5);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	int a[4] = { 1, 3, 7, 8 };
	int b[4] = { 2, 4, 10, 1 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(b, 4);
	v = v - v1;
	int a1[4];
	for (size_t i = 0; i < 4; i++) {
		a1[i] = a[i] - b[i];
	}
	for (size_t i = 0; i < 4; i++) {
		EXPECT_EQ(v[i], a1[i]);
	}
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	int a[4] = { 1, 3, 7, 8 };
	int b[5] = { 2, 4, 10, 1, 0 };
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(b, 5);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	int a[4] = { 1, 3, 7, 8 };
	int b[4] = { 2, 4, 10, 1 };
	int res;
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(b, 4);
	res = v * v1;
	EXPECT_EQ(res, 92);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	int a[4] = { 1, 3, 7, 8 };
	int b[5] = { 2, 4, 10, 1, 1 };
	int res;
	TDynamicVector<int> v(a, 4);
	TDynamicVector<int> v1(b, 5);
	ASSERT_ANY_THROW(v * v1);
}

