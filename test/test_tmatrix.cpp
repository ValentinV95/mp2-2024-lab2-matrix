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
	TDynamicMatrix<int> m1(5);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			m1[i][j] = i * j + j;
	TDynamicMatrix<int> m2 = m1;
	
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(5);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			m1[i][j] = i * j + j;
	TDynamicMatrix<int> m2 = m1;
	m2[3][2] = 0;

	EXPECT_NE(m1, m2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	
	ASSERT_NO_THROW(m.size());
	EXPECT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[3][2] = 4;

	EXPECT_EQ(4, m[3][2]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index_1)
{
	TDynamicMatrix<int> m(4);

	ASSERT_ANY_THROW(m.at(-1).at(0));
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index_2) // my test
{
	TDynamicMatrix<int> m(4);

	ASSERT_ANY_THROW(m.at(0).at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index_1)
{
	TDynamicMatrix<int> m(4);

	ASSERT_ANY_THROW(m.at(4).at(3));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index_2)
{
	TDynamicMatrix<int> m(4);

	ASSERT_ANY_THROW(m.at(3).at(4));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			m[i][j] = i * j + j;
	TDynamicMatrix<int> w = m;

	ASSERT_NO_THROW(m = m);
	EXPECT_EQ(m, w);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}

	ASSERT_NO_THROW(m = w);
	EXPECT_EQ(m, w);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(6);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}
	w[5][5] = -1;
	w[5][4] = -2;
	w[4][5] = -3;

	EXPECT_EQ((m=w).size(), 6);
	EXPECT_EQ(m, w);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(6);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}
	w[5][5] = -1;
	w[5][4] = -2;
	w[4][5] = -3;

	ASSERT_NO_THROW(m = w);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j + j;
		}
	}

	EXPECT_EQ(m == w, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
		}
	}

	EXPECT_EQ(m == m, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(6);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}

	EXPECT_EQ(m == w, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(5);
	TDynamicMatrix<int> res(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
			res[i][j] = 2 * i * j;
		}
	}

	ASSERT_NO_THROW(m + w);
	EXPECT_EQ(m + w, res);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(6);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}

	ASSERT_ANY_THROW(m + w);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(5);
	TDynamicMatrix<int> res(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
			res[i][j] = 2 * j;
		}
	}

	ASSERT_NO_THROW(m - w);
	EXPECT_EQ(m - w, res);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(6);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}

	ASSERT_ANY_THROW(m - w);
}

TEST(TDynamicMatrix, can_multiply_scalar_by_matrix) // my test
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> res(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			res[i][j] = m[i][j] * 2;
		}
	}

	ASSERT_NO_THROW(m * 2);
	EXPECT_EQ(m * 2, res);
}

TEST(TDynamicMatrix, can_multiply_vector_by_matrix) // my test
{
	TDynamicMatrix<int> m(5);
	TDynamicVector<int> v(5);
	TDynamicVector<int> res(5);
	for (int i = 0; i < 5; ++i) {
		v[i] = i;
		res[i] = 30 * (i + 1);
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
		}
	}

	ASSERT_NO_THROW(m * v);
	EXPECT_EQ(res, m * v);
}

TEST(TDynamicMatrix, cant_multiply_vector_by_matrix_with_not_equal_size) // my test
{
	TDynamicMatrix<int> m(5);
	TDynamicVector<int> v(6);
	for (int i = 0; i < 5; ++i) {
		v[i] = i;
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
		}
	}

	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrixex) // my test
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(5);
	TDynamicMatrix<int> res(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}
	res[0][0] = 0;  res[0][1] = 20;  res[0][2] = 40;  res[0][3] = 60;  res[0][4] = 80;
	res[1][0] = 0;  res[1][1] = 40;  res[1][2] = 80;  res[1][3] = 120; res[1][4] = 160;
	res[2][0] = 0;  res[2][1] = 60;  res[2][2] = 120; res[2][3] = 180; res[2][4] = 240;
	res[3][0] = 0;  res[3][1] = 80;  res[3][2] = 160; res[3][3] = 240; res[3][4] = 320;
	res[4][0] = 0;	res[4][1] = 100; res[4][2] = 200; res[4][3] = 300; res[4][4] = 400;

	ASSERT_NO_THROW(m * w);
	EXPECT_EQ(m * w, res);
}

TEST(TDynamicMatrix, cant_multiply_matrixex_with_not_equal_size) // my test
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> w(6);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			m[i][j] = i * j + j;
			w[i][j] = i * j - j;
		}
	}

	ASSERT_ANY_THROW(m * w);
}
