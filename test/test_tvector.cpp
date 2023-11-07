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

TEST(TDynamicVector, can_create_vector_from_pointer)
{
	int ptr[3] = { 1, 2, 3 };
	ASSERT_NO_THROW(TDynamicVector<int> v(ptr, 3));
}

TEST(TDynamicVector, cant_create_vector_from_nullptr)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(nullptr, 34734));
}

TEST(TDynamicVector, cant_create_vector_with_big_pointer)
{
	int* ptr = new int[MAX_VECTOR_SIZE + 1];
	ASSERT_ANY_THROW(TDynamicVector<int> v(nullptr, MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v1(4);
	v1[0] = 4;
	TDynamicVector<int> v2(v1);

	EXPECT_EQ(4, v2[0]);
	EXPECT_EQ(0, v2[1]);
	EXPECT_EQ(0, v2[2]);
	EXPECT_EQ(0, v2[3]);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(v1);

	v1[3] = 70;
	EXPECT_NE(70, v2[3]);
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
	ASSERT_ANY_THROW(v.at(-2) = 42);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(64) = 0);
	ASSERT_ANY_THROW(v.at(v.size()) = 45454);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(4);
	v[1] = 42;
	ASSERT_NO_THROW(v = v);
	EXPECT_EQ(42, v[1]);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(8), v2(8);
	v1[2] = 2;

	ASSERT_NO_THROW(v2 = v1);
	EXPECT_EQ(2, v2[2]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(3), v2(8);
	for (int i = 0; i < 3; i++)
		v1[i] = i;
	v2[1] = 42;

	v2 = v1;
	ASSERT_NO_THROW(v2 = v1);
	EXPECT_EQ(3, v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v1(3), v2(8);
	v1[1] = 4;
	v2[1] = 42;

	ASSERT_NO_THROW(v2 = v1);
	EXPECT_EQ(4, v2[1]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(4), v2(4);

	for (int i = 0; i < 4; i++)
	{
		v1[i] = i;
		v2[i] = i;
	}

	ASSERT_TRUE(v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(4);
	v[1] = 7;
	ASSERT_TRUE(v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(4), v2(5);
	ASSERT_FALSE(v1 == v2);
}

TEST(TDynamicVector, different_vectors_are_not_equal)
{
	TDynamicVector<int> v1(4), v2(4);

	for (int i = 0; i < 4; i++)
	{
		v1[i] = i;
		v2[i] = 2 * i;
	}

	ASSERT_FALSE(v1 == v2);
}

TEST(TDynamicVector, inequality_with_itself_returns_false)
{
	TDynamicVector<int> v(4);
	v[1] = 7;
	ASSERT_FALSE(v != v);
}

TEST(TDynamicVector, inequality_with_equal_vector_returns_false)
{
	TDynamicVector<int> v1(4), v2(4);

	for (int i = 0; i < 4; i++)
	{
		v1[i] = i;
		v2[i] = i;
	}

	ASSERT_FALSE(v1 != v2);
}

TEST(TDynamicVector, inequality_with_unequal_vector_returns_true)
{
	TDynamicVector<int> v1(4), v2(4);

	for (int i = 0; i < 4; i++)
	{
		v1[i] = i;
		v2[i] = 2*i;
	}

	ASSERT_TRUE(v1 != v2);
}

TEST(TDynamicVector, inequality_with_vector_with_different_size_returns_true)
{
	TDynamicVector<int> v1(4), v2(5);
	ASSERT_TRUE(v1 != v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(4);
	ASSERT_NO_THROW(v = v + 2);

	EXPECT_EQ(2, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(2, v[2]);
	EXPECT_EQ(2, v[3]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(4);
	ASSERT_NO_THROW(v = v - 2);

	EXPECT_EQ(-2, v[0]);
	EXPECT_EQ(-2, v[1]);
	EXPECT_EQ(-2, v[2]);
	EXPECT_EQ(-2, v[3]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i;
	ASSERT_NO_THROW(v = v * 2);

	EXPECT_EQ(0, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(4, v[2]);
	EXPECT_EQ(6, v[3]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4), v2(4), v3(4);
	v1[0] = 2; v1[1] = 4; v1[2] = -11; v1[3] = 0;
	v2[0] = 8; v2[1] = 6; v2[2] = 11; v2[3] = 1;

	ASSERT_NO_THROW(v3 = v1 + v2);

	EXPECT_EQ(10, v3[0]);
	EXPECT_EQ(10, v3[1]);
	EXPECT_EQ(0, v3[2]);
	EXPECT_EQ(1, v3[3]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(4), v2(5);
	ASSERT_ANY_THROW(TDynamicVector<int> v3 = v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4), v2(4), v3(4);
	v1[0] = 2; v1[1] = 4; v1[2] = -11; v1[3] = 0;
	v2[0] = 8; v2[1] = 6; v2[2] = 11; v2[3] = 1;

	ASSERT_NO_THROW(v3 = v1 - v2);

	EXPECT_EQ(-6, v3[0]);
	EXPECT_EQ(-2, v3[1]);
	EXPECT_EQ(-22, v3[2]);
	EXPECT_EQ(-1, v3[3]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(4), v2(5);
	ASSERT_ANY_THROW(TDynamicVector<int> v3 = v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4), v2(4);
	v1[0] = 2; v1[1] = 4; v1[2] = -11; v1[3] = 0;
	v2[0] = 8; v2[1] = 6; v2[2] = 11; v2[3] = 1;
	
	EXPECT_EQ(-81, v1 * v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3), v2(10);
	ASSERT_ANY_THROW(v1 * v2);
}

