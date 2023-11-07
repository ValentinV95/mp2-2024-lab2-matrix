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
	const size_t sz = 2049;
	TDynamicVector<double> a(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
	TDynamicVector<double> b(a);
	EXPECT_EQ(a, b);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	const size_t sz = 2049;
	TDynamicVector<double> a(sz), b(a);
	EXPECT_TRUE(&a != &b);
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
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at( - 3) = 5);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	const size_t sz = 10;
	TDynamicVector<int> v(sz);
	ASSERT_ANY_THROW(v.at(2*sz) = 5);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
			c[i] = a[i] = rand();
	a = a;
	EXPECT_EQ(a,c);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz), b(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
		c[i] = a[i] = rand();
	b = a;
	EXPECT_EQ(c,b);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	const size_t sz = 10;
	TDynamicVector<int> a(2*sz), b(sz);
	for (size_t i = 0; i < 2 * sz; i++)
		a[i] = rand();
	b = a;
	EXPECT_NE(sz, b.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	const size_t sz = 10;
	TDynamicVector<int> a(2*sz), b(sz);
	for (size_t i = 0; i < 2 * sz; i++)
		a[i] = rand();
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz), b(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = b[i] = rand();
	EXPECT_TRUE(a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = rand();
	EXPECT_TRUE(a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	const size_t sz = 10;
	TDynamicVector<int> a(2 * sz + 3), b(sz);
	EXPECT_TRUE(a != b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	const size_t sz = 10;
	double scalar = 3.14159265;
	TDynamicVector<double> a(sz), b(sz);
	for (size_t i = 0; i < sz; i++)
	{
		b[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		a[i] = b[i] + scalar;
	}
	EXPECT_EQ(a, b + scalar);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	const size_t sz = 10;
	double scalar = 3.14159265;
	TDynamicVector<double> a(sz), b(sz);
	for (size_t i = 0; i < sz; i++)
	{
		b[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		a[i] = b[i] - scalar;
	}
	EXPECT_EQ(a, b - scalar);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	const size_t sz = 10;
	double scalar = 3.14159265;
	TDynamicVector<double> a(sz), b(sz);
	for (size_t i = 0; i < sz; i++)
	{
		b[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		a[i] = b[i] * scalar;
	}
	EXPECT_EQ(a,b * scalar);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	const size_t sz = 10;
	TDynamicVector<double> a(sz), b(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
	{
		a[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		b[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		c[i] = a[i] + b[i];
	}
	EXPECT_EQ(c, a + b);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz),b(2*sz);
	EXPECT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	const size_t sz = 10;
	TDynamicVector<double> a(sz), b(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
	{
		a[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		b[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		c[i] = a[i] - b[i];
	}
	EXPECT_EQ(c, a - b);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz), b(2 * sz);
	EXPECT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	const size_t sz = 10;
	double res = 0;
	TDynamicVector<double> a(sz), b(sz);
	for (size_t i = 0; i < sz; i++)
	{
		a[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		b[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		res += a[i] * b[i];
	}
	EXPECT_EQ(res, a * b);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	const size_t sz = 10;
	TDynamicVector<double> a(2*sz), b(sz);
	EXPECT_ANY_THROW(a * b);
}

