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
	TDynamicVector<int> vec1(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	TDynamicVector<int> vec2 = vec1;
	EXPECT_EQ(vec1, vec2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> vec1(1000);
	for (auto i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	TDynamicVector<int> vec2 = vec1;
	for (auto i = 0; i < 1000; i++) {
		vec2[i] = i * 2;
	}
	EXPECT_NE(vec1, vec2);
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
	TDynamicVector<int> v(1000);

	ASSERT_ANY_THROW(v.at(-500));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(1000);

	ASSERT_ANY_THROW(v.at(1000));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> vec1(1000);
	for (int i = 0; i < 1000; i++) {
		vec1.at(i) = i;
	}
	TDynamicVector<int> vec2 = vec1;
	ASSERT_NO_THROW(vec1 = vec1);
	EXPECT_EQ(vec1, vec2);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> vec1(1000);
	for (int i = 0; i < 1000; i++) {
		vec1.at(i) = i;
	}
	TDynamicVector<int> vec2(1000);
	for (int i = 0; i < 1000; i++) {
		vec2.at(i) = i * 2;
	}
	ASSERT_NO_THROW(vec2 = vec1);
	EXPECT_EQ(vec1, vec2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> vec1(1000), vec2(2000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	for (int i = 0; i < 2000; i++) {
		vec2[i] = i*2;
	}
	ASSERT_NO_THROW(vec2 = vec1);
	EXPECT_EQ(vec1.size(), vec2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> vec1(1000), vec2(2000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	for (int i = 0; i < 2000; i++) {
		vec2[i] = i * 2;
	}
	ASSERT_NO_THROW(vec2 = vec1);
	EXPECT_EQ(vec1, vec2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> vec1(1000), vec2(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
		vec2[i] = i;
	}
	ASSERT_NO_THROW(vec2 == vec1);
	EXPECT_EQ(vec1 == vec2, true);
}

TEST(TDynamicVector, compare_not_equal_vectors_return_false)//my
{
	TDynamicVector<int> vec1(1000), vec2(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
		vec2[i] = i * 2;
	}
	ASSERT_NO_THROW(vec1 == vec2);
	EXPECT_EQ(vec1 == vec2, false);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> vec1(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	ASSERT_NO_THROW(vec1 == vec1);
	EXPECT_EQ(vec1 == vec1, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> vec1(1000), vec2(2000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	for (int i = 0; i < 2000; i++) {
		vec2[i] = i * 2;
	}
	ASSERT_NO_THROW(vec2 == vec1);
	EXPECT_EQ(vec1 == vec2, false);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> vec1(1000), vec2(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
		vec2[i] = i + 2;
	}
	ASSERT_NO_THROW(vec1 + 2);
	EXPECT_EQ(vec1 + 2, vec2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> vec1(1000), vec2(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
		vec2[i] = i - 2;
	}
	ASSERT_NO_THROW(vec1 - 2);
	EXPECT_EQ(vec1 - 2, vec2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> vec1(1000), vec2(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
		vec2[i] = i * 2;
	}
	ASSERT_NO_THROW(vec1 * 2);
	EXPECT_EQ(vec1 * 2, vec2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> vec1(1000), vec2(1000), vec3(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
		vec2[i] = i;
		vec3[i] = i + i;
	}

	ASSERT_NO_THROW(vec1 + vec2);
	EXPECT_EQ(vec1 + vec2, vec3);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> vec1(1000), vec2(2000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	for (int i = 0; i < 2000; i++) {
		vec2[i] = i;
	}
		ASSERT_ANY_THROW(vec1 + vec2);
}

	TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> vec1(1000), vec2(1000), vec3(1000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i*2;
		vec2[i] = i;
		vec3[i] = i;
	}
	ASSERT_NO_THROW(vec1 - vec2);
	EXPECT_EQ(vec1 - vec2, vec3);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> vec1(1000), vec2(2000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	for (int i = 0; i < 2000; i++) {
		vec2[i] = i;
	}
	ASSERT_ANY_THROW(vec1 - vec2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> vec1(1000), vec2(1000);
	int res=0;
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
		vec2[i] = i;
		res+=i*i;
	}
	ASSERT_NO_THROW(vec1 * vec2);
	EXPECT_EQ(vec1 * vec2, res);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> vec1(1000), vec2(2000);
	for (int i = 0; i < 1000; i++) {
		vec1[i] = i;
	}
	for (int i = 0; i < 2000; i++) {
		vec2[i] = i;
	}
	ASSERT_ANY_THROW(vec1 * vec2);
}

