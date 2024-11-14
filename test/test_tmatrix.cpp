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
	TDynamicMatrix<int> m(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	TDynamicMatrix<int> n(m);
	EXPECT_EQ(m, n);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	TDynamicMatrix<int> n(m);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
		{
			m[i][j] *= 2;
			m[i][j] += 1;
		}
	EXPECT_NE(m, n);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m[2][4] = -6;
	EXPECT_EQ(-6, m[2][4]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_row_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(-2).at(3) = 4);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_column_index)	//	Addition to previous
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(2).at(-3) = 4);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_row_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(10).at(2) = 4);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_column_index)	//	Addition to previous
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(3).at(10) = 4);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	TDynamicMatrix<int> n(m);
	ASSERT_NO_THROW(m = m);
	EXPECT_EQ(n, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(5), n(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	ASSERT_NO_THROW(n = m);
	EXPECT_EQ(m, n);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(5), n(2);
	n = m;
	EXPECT_EQ(m.size(), n.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(5), n(2);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	ASSERT_NO_THROW(n = m);
	EXPECT_EQ(m, n);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(5), n(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	n = m;
	ASSERT_NO_THROW(m == n);
	EXPECT_EQ(true, m == n);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	ASSERT_NO_THROW(m == m);
	EXPECT_EQ(true, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(5), n(3);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	sz = n.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = j - i;
	ASSERT_NO_THROW(m == n);
	EXPECT_NE(true, m == n);
}

TEST(TDynamicMatrix, can_negate_matrix) //My test
{
	TDynamicMatrix<int> m(5), n(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = i - j;
	ASSERT_NO_THROW(-m);
	EXPECT_EQ(n, -m);
}


TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5), n(5), r(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			r[i][j] = 2 * j;
	ASSERT_NO_THROW(n + m);
	EXPECT_EQ(r, n + m);
	ASSERT_NO_THROW(n += m);
	EXPECT_EQ(r, n);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(5), n(6);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = j + i;
	ASSERT_ANY_THROW(m + n);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5), n(5), r(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			r[i][j] = 2 * i;
	ASSERT_NO_THROW(n - m);
	EXPECT_EQ(r, n - m);
	ASSERT_NO_THROW(n -= m);
	EXPECT_EQ(r, n);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(5), n(6);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = j + i;
	ASSERT_ANY_THROW(m - n);
}

//My tests
TEST(TDynamicMatrix, can_multiply_matrix_by_itself)
{
	TDynamicMatrix<int> m(5), n(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = 30 + i * 10 + j * (10 + 5 * i);
	ASSERT_NO_THROW(m * m);
	EXPECT_EQ(n, m * m);
	ASSERT_NO_THROW(m *= m);
	EXPECT_EQ(n, m);
}

TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
	TDynamicMatrix<int> m(5), n(5), r(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			r[i][j] = 30 - i * 10 + j * (10 - i * 5);
	ASSERT_NO_THROW(m * n);
	EXPECT_EQ(r, m * n);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(5), n(6);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = j + i;
	ASSERT_ANY_THROW(m * n);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_scalar)
{
	TDynamicMatrix<int> m(5), n(5);
	int a = 3;
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = 3 * (j + i);
	ASSERT_NO_THROW(m * a);
	EXPECT_EQ(n, m * a);
	ASSERT_NO_THROW(m *= a);
	EXPECT_EQ(n, m);
}

TEST(TDynamicMatrix, can_divide_matrix_by_scalar)
{
	TDynamicMatrix<int> m(5), n(5);
	int a = 2;
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = 2*(j + i);
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			n[i][j] = (j + i);
	ASSERT_NO_THROW(m / a);
	EXPECT_EQ(n, m / a);
	ASSERT_NO_THROW(m /= a);
	EXPECT_EQ(n, m);
}

TEST(TDynamicMatrix, throws_when_division_by_zero_encountered)
{
	TDynamicMatrix<int> m(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j + i;
	ASSERT_ANY_THROW(m / 0);
}


TEST(TDynamicMatrix, can_right_multiply_matrix_by_vector_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicVector<int> v(5), w(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
		v[i] = i;
	for (size_t i = 0; i < sz; i++)
		w[i] = 30 + 10 * i;
	ASSERT_NO_THROW(m * v);
	EXPECT_EQ(w, m * v);
}

TEST(TDynamicMatrix, cant__right_multiply_matrix_by_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicVector<int> v(6);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
			v[i] = i;
	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_left_multiply_matrix_by_vector_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicVector<int> v(5), w(5);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j + i;
	for (size_t i = 0; i < sz; i++)
		v[i] = i;
	for (size_t i = 0; i < sz; i++)
		w[i] = 30 + 10 * i;
	ASSERT_NO_THROW(v * m);
	EXPECT_EQ(w, v * m);
}

TEST(TDynamicMatrix, cant__left_multiply_matrix_by_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicVector<int> v(6);
	size_t sz = m.size();
	for (size_t i = 0; i < sz; i++)
		for (size_t j = 0; j < sz; j++)
			m[i][j] = j - i;
	for (size_t i = 0; i < sz; i++)
		v[i] = i;
	ASSERT_ANY_THROW(v * m);
}