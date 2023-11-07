#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	const size_t sz = 2049;
	TDynamicMatrix<double> a(sz);
	for (size_t i = 0; i < sz; i++)
			for (size_t j = 0; j < sz; j++)
					a[i][j] = double(rand()) / RAND_MAX * 1000000 - 500000;
	TDynamicMatrix<double> b(a);
	EXPECT_EQ(a, b);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	const size_t sz = 50;
	TDynamicMatrix<int> a(sz);
	TDynamicMatrix<int> b(a);
	EXPECT_TRUE(&a!=&b);
}

TEST(TDynamicMatrix, can_get_size)
{
	const size_t sz = 5;
	TDynamicMatrix<int> m1(sz);
	EXPECT_EQ(sz, m1.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz);
	a[2][7] = 3;
	EXPECT_EQ(3, a[2][7]);

}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz);
	ASSERT_ANY_THROW(a.at(-3).at(sz - 5) = 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz);
	ASSERT_ANY_THROW(a.at(3).at(sz + 5) = 3);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			c[i][j] = a[i][j] = rand();
	a = a;
	EXPECT_EQ(c, a);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			a[i][j] = rand();
	TDynamicMatrix<int> b(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			b[i][j] = rand();
	b = a;
	EXPECT_EQ(a,b);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			a[i][j] = rand();
	TDynamicMatrix<int> b(2 * sz);
	b = a;
	EXPECT_NE(2 * sz, b.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			a[i][j]= rand();
	TDynamicMatrix<int> b(2 * sz);
	for (size_t i = 0; i < 2*sz; i++)
		for (size_t j = 0; j < 2*sz; j++)
			b[i][j] = rand();
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			a[i][j] = b[i][j] = rand();
	EXPECT_TRUE(a == b);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
		{
			a[i][j] = rand();
		}
	EXPECT_TRUE(a == a);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz), b(2 * sz);
	EXPECT_FALSE(a == b);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
		{
			a[i][j] = rand();
			b[i][j] = rand();
			c[i][j] = a[i][j] + b[i][j];
		}
	EXPECT_EQ(c, a + b);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	const size_t s1 = 10, s2=15;
	TDynamicMatrix<int> a(s1), b(s2), c(s1+s2);
	ASSERT_ANY_THROW(c = a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	const size_t sz = 10;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
		{
			a[i][j] = rand();
			b[i][j] = rand();
			c[i][j] = a[i][j] - b[i][j];
		}
	EXPECT_EQ(c, a - b);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const size_t s1 = 10, s2 = 15;
	TDynamicMatrix<int> a(s1), b(s2), c(s1 + s2);
	ASSERT_ANY_THROW(c = a - b);
}

