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
	TDynamicVector<int> v(1000);
	for (auto i = 0; i < 1000; i++) {
		v[i] = i * 53;
	}
	TDynamicVector<int> v1 =v;
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(1000);
	for (auto i = 0; i < 1000; i++) {
		v[i] = i * 53;
	}
	TDynamicVector<int> v1 = v;
	for (auto i = 0; i < 1000; i++) {
		v1[i] = i;
	}
	EXPECT_NE(v, v1);
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
TEST(TDynamicVector, can_set_and_get_element_at)
{
	TDynamicVector<int> v(4);
	v.at(0) = 4;

	EXPECT_EQ(4, v.at(0));
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(423);
	ASSERT_ANY_THROW(v.at(-1) = 4);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(423);
	ASSERT_ANY_THROW(v.at(423) = 4);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(423);
	for (int i = 0; i < 423; i++) {
		v.at(i) = i + 1;
	}
	TDynamicVector<int> v1 = v;
	ASSERT_NO_THROW(v = v);
	EXPECT_EQ(v1, v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(423);
	for (int i = 0; i < 423; i++) {
		v.at(i) = i + 1;
	}
	TDynamicVector<int> v1(423);
	ASSERT_NO_THROW(v1 = v);
	EXPECT_EQ(v1, v);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(2111), v1(8002);
	for (auto i = 0; i < 8002; i++) {
		v[i % 2111] = 101 * i;
		v1[i] = i%51;
	}
	ASSERT_NO_THROW(v1 = v);
	EXPECT_EQ(v1.size(), v.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(2111), v1(8002);
	for (auto i = 0; i < 8002; i++) {
		v[i % 2111] = 101 * i;
		v1[i] = i % 51;
	}
	ASSERT_NO_THROW(v1 = v);
	EXPECT_EQ(v1, v);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(2111), v1(2111);
	for (auto i = 0; i < 2111; i++) {
		v[i] = 101 * i;
		v1[i] = 101*i;
	}
	ASSERT_NO_THROW(v == v1);
	EXPECT_EQ(v1 == v, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(2111);
	for (auto i = 0; i < 2111; i++) {
		v[i] = 101 * i;
	}
	ASSERT_NO_THROW(v == v);
	EXPECT_EQ(v == v, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(2131), v1(2111);
	
	ASSERT_NO_THROW(v == v1);
	EXPECT_EQ(v1 == v, false);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(2111), v1(2111);
	srand(time(0));
	int el = rand() % 2763;
	for (auto i = 0; i < 2111; i++) {
		v[i] = 101 * i;
		v1[i] = 101 * i + el;
	}
	ASSERT_NO_THROW(v + el);
	EXPECT_EQ(v+el,v1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(2111), v1(2111);
	srand(time(0));
	int el = rand() % 2763;
	for (auto i = 0; i < 2111; i++) {
		v[i] = 101 * i;
		v1[i] = 101 * i - el;
	}
	ASSERT_NO_THROW(v - el);
	EXPECT_EQ(v - el, v1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(2111), v1(2111);
	srand(time(0));
	int el = rand() % 2763;
	for (auto i = 0; i < 2111; i++) {
		v[i] = 101 * i;
		v1[i] = 101 * i * el;
	}
	ASSERT_NO_THROW(v * el);
	EXPECT_EQ(v * el, v1);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v(100), v1(100),v2(100);
	for (int i = 0; i < 100; i++) {
		v[i] = i;
		v1[i] = i;
		v2[i] = i + i;
	}
	
	ASSERT_NO_THROW(v1 + v);
	EXPECT_EQ(v1 + v, v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(100), v1(1012);
	for (int i = 0; i < 100; i++) {
		v[i] = i;
		v1[i] = i;
	}

	ASSERT_ANY_THROW(v1 + v);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v(100), v1(100), v2(100);
	for (int i = 0; i < 100; i++) {
		v[i] = i;
		v1[i] = i;
		v2[i] = 0;
	}

	ASSERT_NO_THROW(v1 - v);
	EXPECT_EQ(v1 - v, v2);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(100), v1(1012);
	for (int i = 0; i < 100; i++) {
		v[i] = i;
		v1[i] = i;
	}

	ASSERT_ANY_THROW(v1 - v);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v(100), v1(100);
	int res = 0;
	srand(time(0));
	int el1, el2;
	for (int i = 0; i < 100; i++) {
		el1 = rand() % 97;
		el2 = rand() % 103;
		v[i] = el1;
		v1[i] = el2;
		res += el1 * el2;
	}

	ASSERT_NO_THROW(v1 * v);
	EXPECT_EQ(res, v1 * v);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(100), v1(101);
	for (int i = 0; i < 100; i++) { v[i] = i; v1[i] = i; }
	v1[100] = 0;

	ASSERT_ANY_THROW(v1 * v);
}

