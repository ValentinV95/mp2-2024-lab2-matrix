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
	m1[0][0] = 0;
	m1[0][1] = 1;
	m1[1][0] = 2;
	m1[1][1] = 3;
	TDynamicMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(m1);
	m1[0][0] = 1;
	m2[0][0] = 2;
	EXPECT_NE(m1, m2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	EXPECT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m[3][3] = 3;
	EXPECT_EQ(m[3][3], 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(-1, -1) = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(7 ,7) = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself_is_correct)
{
	TDynamicMatrix<int> m(5);
	m = m;
	EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size_is_correct)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	m2[1][1] = 3;
	m1 = m2;
	EXPECT_EQ(m1, m2);

}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(7);
	m1 = m2;
	EXPECT_EQ(m1.size(), 7);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(7);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size_is_correct)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(7);
	m2[3][3] = 3;
	m1 = m2;
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			m1[i][j] = i + j;
			m2[i][j] = i + j;
		}
	}
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			m[i][j] = i + j;
		}
	}
	EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(7);
	EXPECT_NE(m1, m2);
}

TEST(TDynamicMatrix, can_multiply_matrix_with_scalar)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 2;
	ASSERT_NO_THROW(m * 3);
}

TEST(TDynamicMatrix, can_multiply_matrix_with_scalar_is_correct)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m1[i][j] = i + j;
			m2[i][j] = (i + j) * 3;
		}
	}
	EXPECT_EQ(m1 * 3, m2);
}

TEST(TDynamicMatrix, can_multiply_matrix_with_vector_with_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(2);
	m[0][0] = 1;
	v[0] = 2;
	ASSERT_NO_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrix_with_vector_with_equal_size_is_correct)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m[i][j] = j;
		}
		v1[i] = i;
	}
	v2[0] = 1;
	v2[1] = 1;
	EXPECT_EQ(m * v1, v2);
}

TEST(TDynamicMatrix, cant_multiply_matrix_with_vector_with_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(3);
	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	m1[0][0] = 1;
	ASSERT_NO_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size_is_correct)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	TDynamicMatrix<int> m3(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m1[i][j] = i;
			m2[i][j] = i + j;
			m3[i][j] = 2 * i + j;
		}
	}
	EXPECT_EQ(m1 + m2, m3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(7);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	m1[0][0] = 1;
	ASSERT_NO_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size_is_correct)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	TDynamicMatrix<int> m3(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m1[i][j] = i;
			m2[i][j] = i + j;
			m3[i][j] = -j;
		}
	}
	EXPECT_EQ(m1 - m2, m3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(7);
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	m1[0][0] = 1;
	m2[0][0] = 2;
	ASSERT_NO_THROW(m1 * m2);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size_is_correct)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	TDynamicMatrix<int> m3(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m1[i][j] = i;
			m2[i][j] = j;
		}
	}
	m3[0][0] = 0;
	m3[0][1] = 0;
	m3[1][0] = 0;
	m3[1][1] = 2;
	EXPECT_EQ(m1 * m2, m3);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(7);
	ASSERT_ANY_THROW(m1 * m2);
}