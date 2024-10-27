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
	TDynamicVector<int> v1(10);
	for (int i = 0; i < 10; ++i) 
		v1[i] = i;
	TDynamicVector<int> v2 = v1;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v1(10);
	v1[5] = 4;
	TDynamicVector<int> v2 = v1;
	v2[5] = 3;

	EXPECT_NE(v1, v2);
}

TEST(TDynamicVector, can_construct_vector_with_T_pointer) // my test
{
	int size = 10;
	int* arr = new int[size];
	TDynamicVector<int> v(arr, size);

	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], v[i]);
	}
}

TEST(TDynamicVector, moved_vector_is_equal_to_source_one) // my test
{
	TDynamicVector<int> v1(10);
	v1[0] = 1;
	v1[4] = 5;
	v1[9] = 2;
	TDynamicVector<int> v2 = v1 + v1 - v1;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_moved_vector_is_equal_to_source_one) // my test
{
	TDynamicVector<int> v1(10);
	v1[0] = 1;
	v1[4] = 5;
	v1[9] = 2;
	TDynamicVector<int> v2;
	v2 = TDynamicVector<int>(v1);

	EXPECT_EQ(v1, v2);
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
	TDynamicVector<int> v(4);

	ASSERT_ANY_THROW(v.at(-4));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);

	ASSERT_ANY_THROW(v.at(4));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(10);
	for (int i = 0; i < 10; ++i) v[i] = i;
	TDynamicVector<int> w = v;

	ASSERT_NO_THROW(v = v);
	EXPECT_EQ(v, w);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}

	ASSERT_NO_THROW(v = w);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(12);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}
	w[10] = 10;
	w[11] = 11;

	EXPECT_EQ((v = w).size(), 12);
	EXPECT_EQ(v, w);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(12);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}
	w[10] = 10;
	w[11] = 11;

	ASSERT_NO_THROW(v = w);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = i;
	}

	EXPECT_EQ(v == w, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
	}

	EXPECT_EQ(v == v, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(12);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}

	ASSERT_NO_THROW(v == w, false);
}

TEST(TDynamicVector, compare_with_not_equal_of_equal_vectors_return_false) // my test
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = i;
	}

	EXPECT_EQ(v != w, false);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> res(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		res[i] = i + 10;
	}

	ASSERT_NO_THROW(v + 10);
	//v = v + 10;
	//for (int i = 0; i < 10; ++i) { // just create additional res variable
	//	EXPECT_EQ(v[i], i + 10);
	//}
	EXPECT_EQ(v + 10, res);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> res(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		res[i] = i - 10;
	}

	ASSERT_NO_THROW(v - 10);
	//v = v - 10;
	//for (int i = 0; i < 10; ++i) { // just create additional res variable
	//	EXPECT_EQ(v[i], i - 10);
	//}
	EXPECT_EQ(v - 10, res);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> res(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		res[i] = i * 10;
	}

	ASSERT_NO_THROW(v * 10);
	//v = v * 10;
	//for (int i = 0; i < 10; ++i) { // just create additional res variable
	//	EXPECT_EQ(v[i], i * 10);
	//}
	EXPECT_EQ(v * 10, res);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}

	ASSERT_NO_THROW(v + w);
	EXPECT_EQ(v + w, v * 3);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(12);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}
	w[10] = 10;
	w[11] = 11;

	ASSERT_ANY_THROW(v + w);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}

	ASSERT_NO_THROW(v - w);
	EXPECT_EQ(v - w, v * (-1));
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(12);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}
	w[10] = 10;
	w[11] = 11;

	ASSERT_ANY_THROW(v - w);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(10);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}

	ASSERT_NO_THROW(v * w);
	EXPECT_EQ(v * w, 570);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(12);
	for (int i = 0; i < 10; ++i) {
		v[i] = i;
		w[i] = 2 * i;
	}
	w[10] = 10;
	w[11] = 11;

	ASSERT_ANY_THROW(v * w);
}

