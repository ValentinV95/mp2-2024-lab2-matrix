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
	const size_t sz = 50;
	TDynamicVector<double> a(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
	TDynamicVector<double> b(a);
	EXPECT_EQ(a, b);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	const size_t sz = 50;
	TDynamicVector<double> a(sz), b(a);
	EXPECT_TRUE(&a != &b);
}

TEST(TDynamicVector, can_get_size)
{
	size_t sz = 4;
	TDynamicVector<int> v(sz);
	ASSERT_NO_THROW(v.size());
}

TEST(TDynamicVector, can_correctly_get_size)
{
	size_t sz = 4;
  TDynamicVector<int> v(sz);
  EXPECT_EQ(sz, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	int elem = 4;
	TDynamicVector<int> v(elem);
	ASSERT_NO_THROW(v[0] = 4);
	ASSERT_NO_THROW(v[0]);
}

TEST(TDynamicVector, can_correctly_set_and_get_element)
{
  int elem = 4;
  TDynamicVector<int> v(elem);
  v[0] = 4;
  EXPECT_EQ(elem, v[0]);
}

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
	TDynamicVector<int> a(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = rand();
	ASSERT_NO_THROW(a = a);
}

TEST(TDynamicVector, can_correctly_assign_vector_to_itself)
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
	TDynamicVector<int> a(sz), b(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = rand();
	
	ASSERT_NO_THROW(b = a);
}

TEST(TDynamicVector, can_correctly_assign_vectors_of_equal_size)
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
	TDynamicVector<int> a(2 * sz), b(sz);
	for (size_t i = 0; i < 2 * sz; i++)
		a[i] = rand();
	ASSERT_NO_THROW(b = a);
}

TEST(TDynamicVector, can_correctly_assign_vectors_of_different_size)
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
	EXPECT_FALSE(a == b);
}

TEST(TDynamicVector, NE_compare_equal_vectors_return_false)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz), b(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = b[i] = rand();
	EXPECT_FALSE(a != b);
}

TEST(TDynamicVector, NE_compare_vector_with_itself_return_true)
{
	const size_t sz = 10;
	TDynamicVector<int> a(sz);
	for (size_t i = 0; i < sz; i++)
		a[i] = rand();
	EXPECT_FALSE(a != a);
}

TEST(TDynamicVector, NE_vectors_with_different_size_are_not_equal)
{
	const size_t sz = 10;
	TDynamicVector<int> a(2 * sz + 3), b(sz);
	EXPECT_TRUE(a != b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	const size_t sz = 10;
	double scalar = 3.14159265;
	TDynamicVector<double>  b(sz);
	ASSERT_NO_THROW(b + scalar);
}

TEST(TDynamicVector, can_correctly_add_scalar_to_vector)
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
	TDynamicVector<double>  b(sz);
	ASSERT_NO_THROW(b - scalar);
}

TEST(TDynamicVector, can_correctly_subtract_scalar_from_vector)
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
	ASSERT_NO_THROW(a, b * scalar);
}

TEST(TDynamicVector, can_correctly_multiply_scalar_by_vector)
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
	TDynamicVector<double> a(sz), b(sz);
	ASSERT_NO_THROW(a + b);
}

TEST(TDynamicVector, can_correctly_add_vectors_with_equal_size)
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
	TDynamicVector<int> a(sz), b(2 * sz);
	EXPECT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	const size_t sz = 10;
	TDynamicVector<double> a(sz), b(sz);
	ASSERT_NO_THROW(a - b);
}

TEST(TDynamicVector, can_correctly_subtract_vectors_with_equal_size)
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
	TDynamicVector<double> a(sz), b(sz);
	ASSERT_NO_THROW(a * b);
}

TEST(TDynamicVector, can_correctly_multiply_vectors_with_equal_size)
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

TEST(TDynamicVector, can_transform_array_to_vector)
{
	const size_t sz = 10;
	double res = 0,* arr;
	TDynamicVector<double> b(sz);
	arr = new double[sz];
	for (size_t i = 0; i < sz; i++)
		b[i] = arr[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
	TDynamicVector<double> a(arr, sz);
	EXPECT_EQ(b, a);
}

TEST(TDynamicVector, throws_when_impossible_transform_array_to_vector)
{
	size_t sz = 10, zero_sz=0, large_sz = MAX_VECTOR_SIZE+1;
	double * arr = nullptr, *arr1;
	arr1 = new double[sz];
	//EXPECT_ANY_THROW(TDynamicVector<double> a(arr, sz));
	EXPECT_ANY_THROW(TDynamicVector<double> a(arr1, zero_sz));
	EXPECT_ANY_THROW(TDynamicVector<double> a(arr1, large_sz));
}

TEST(TDynamicVector, can_swap_vectors)
{
	const size_t sz = 10;
	TDynamicVector<double> a(sz), b(sz);
	ASSERT_NO_THROW(swap(a, b));
}

TEST(TDynamicVector, can_correctly_swap_vectors)
{
	const size_t sz = 10;
	TDynamicVector<double> a(sz), b(sz), c(sz), d(sz);
	for (size_t i = 0; i < sz; i++)
	{
		a[i]= b[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
		c[i] = d[i] = double(rand()) / RAND_MAX * 1000000 - 500000;
	}
	swap(b, d);
	EXPECT_EQ(a, d);
	EXPECT_EQ(c, b);
}