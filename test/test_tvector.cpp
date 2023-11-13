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
	TDynamicVector<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	TDynamicVector<int> b(a);
	EXPECT_TRUE(a == b);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> a(3);
	a[0] = 5;
	a[1] = 6;
	a[2] = 37;
	TDynamicVector<int> b(a);
	EXPECT_NE(&a, &b);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> a(4);
	EXPECT_EQ(4, a.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	TDynamicVector<int> a(4);
	a[0] = 4;
	EXPECT_EQ(4, a[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> a(4);
	ASSERT_ANY_THROW(a.at(-2) = -87);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> a(4);
	ASSERT_ANY_THROW(a.at(8) = 7);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	a = a;
	EXPECT_EQ(a, a);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	TDynamicVector<int> b(4);
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	TDynamicVector<int> b(10);
	b = a;
	EXPECT_EQ(4, b.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	TDynamicVector<int> b(10);
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	TDynamicVector<int> b(4);
	b = a;
	EXPECT_TRUE(a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	EXPECT_TRUE(a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(8);
	EXPECT_NE(a, b);
}


TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(4);
	int c = 4;
	for (int i = 0; i < 4; i++) {
		a[i] = rand();
		b[i] = a[i] + c;
	}
	a = a + c;
	EXPECT_EQ(b, a);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(4);
	int c = 5;
	for (int i = 0; i < 4; i++) {
		a[i] = rand();
		b[i] = a[i] * c;
	}
	a = a * c;
	EXPECT_EQ(b, a);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(4);
	int c = 6;
	for (int i = 0; i < 4; i++) {
		a[i] = rand();
		b[i] = a[i] * c;
	}
	a = a * c;
	EXPECT_EQ(b, a);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(4);
	TDynamicVector<int> c(4);
	for (int i = 0; i < 4; i++) {
		a[i] = rand();
		b[i] = rand();
		c[i] = a[i] + b[i];
	}
	EXPECT_EQ(c, a + b);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(8);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	for (int i = 0; i < 8; i++)
		b[i] = rand();

	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(4);
	TDynamicVector<int> c(4);
	for (int i = 0; i < 4; i++) {
		a[i] = rand();
		b[i] = rand();
		c[i] = a[i] - b[i];
	}
	EXPECT_EQ(c, a - b);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(8);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	for (int i = 0; i < 8; i++)
		b[i] = rand();

	ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(4);
	int c  = 0;
	for (int i = 0; i < 4; i++) {
		a[i] = rand();
		b[i] = rand();
		c += a[i] * b[i];
	}
	EXPECT_EQ(c, a * b);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(4);
	TDynamicVector<int> b(8);
	for (int i = 0; i < 4; i++)
		a[i] = rand();
	for (int i = 0; i < 8; i++)
		b[i] = rand();

	ASSERT_ANY_THROW(a * b);
}

