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
	TDynamicMatrix<int> m(2);
	m[1][1] = 5;
	TDynamicMatrix<int> m1(m);
	EXPECT_EQ(m[0][0], m1[0][0]);
	EXPECT_EQ(m[0][1], m1[0][1]);
	EXPECT_EQ(m[1][0], m1[1][0]);
	EXPECT_EQ(m[1][1], m1[1][1]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(2);
	m[1][1] = 5;
	TDynamicMatrix<int> m1(m);
	m[1][1] = 3;
	EXPECT_EQ(5, m1[1][1]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(2);
	EXPECT_EQ(m.size(), 2);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(2);
	ASSERT_NO_THROW(m[0][0] = 1);
	ASSERT_NO_THROW(m.at(1, 1) = 2);
	m[1][0] = 5;
	EXPECT_EQ(m[1][0], 5);
	m.at(0, 1) = 7;
	EXPECT_EQ(m.at(0, 1), 7);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(-5, 0) = 9);
	ASSERT_ANY_THROW(m.at(0, -5) = 9);

}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(3, 0) = 9);
	ASSERT_ANY_THROW(m.at(0, 2) = 9);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(2);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(2);
	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, correct_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(2);
	m[1][1] = 5;
	m1[0][1] = 3;
	m = m1;
	EXPECT_EQ(m[0][0], m1[0][0]);
	EXPECT_EQ(m[0][1], m1[0][1]);
	EXPECT_EQ(m[1][0], m1[1][0]);
	EXPECT_EQ(m[1][1], m1[1][1]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(3);
	m = m1;
	EXPECT_EQ(m.size(), 3);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{

	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(3);
	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, correct_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(2);
	m[1][1] = 5;
	m1[0][1] = 3;
	m = m1;
	EXPECT_EQ(m[0][0], m1[0][0]);
	EXPECT_EQ(m[0][1], m1[0][1]);
	EXPECT_EQ(m[1][0], m1[1][0]);
	EXPECT_EQ(m[1][1], m1[1][1]);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(2);
	m[1][1] = 5;
	m1[1][1] = 5;
	m = m1;
	EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(2);
	EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(3);
	EXPECT_NE(m, m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	ASSERT_NO_THROW(m1 + m2);
}

TEST(TDynamicMatrix, correct_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2),m2(2),res(2),res_correct(2);
	m1[0][0] = 2;
	m1[1][1] = 2;
	m2[1][0] = 2;
	m2[0][1] = 2;
	res = m1 + m2;
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			res_correct[i][j] = 2;
	EXPECT_EQ(res_correct[0][0], res[0][0]);
	EXPECT_EQ(res_correct[0][1], res[0][1]);
	EXPECT_EQ(res_correct[1][0], res[1][0]);
	EXPECT_EQ(res_correct[1][1], res[1][1]);

}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(3);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{

	TDynamicMatrix<int> m1(2), m2(2);
	ASSERT_NO_THROW(m1 - m2);
}

TEST(TDynamicMatrix, correct_substract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2), res(2),res_correct(2);
	m1[0][0] = 2;
	m1[1][1] = 2;
	m2[1][0] = -2;
	m2[0][1] = -2;
	res = m1 - m2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			res_correct[i][j] = 2;
	EXPECT_EQ(res_correct[0][0], res[0][0]);
	EXPECT_EQ(res_correct[0][1], res[0][1]);
	EXPECT_EQ(res_correct[1][0], res[1][0]);
	EXPECT_EQ(res_correct[1][1], res[1][1]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(3);
	ASSERT_ANY_THROW(m - m1);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{

	TDynamicMatrix<int> m1(2), m2(2);
	ASSERT_NO_THROW(m1 * m2);
}

TEST(TDynamicMatrix, correct_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2), res(2), res_correct(2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			res_correct[i][j] = 2;
			m1[i][j] = 1;
			m2[i][j] = 1;
		}
	res = m1 * m2;
	EXPECT_EQ(res_correct[0][0], res[0][0]);
	EXPECT_EQ(res_correct[0][1], res[0][1]);
	EXPECT_EQ(res_correct[1][0], res[1][0]);
	EXPECT_EQ(res_correct[1][1], res[1][1]);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(3);
	ASSERT_ANY_THROW(m * m1);
}

TEST(TDynamicMatrix, can_multiply_matric_and_scalar)
{

	TDynamicMatrix<int> m1(2);
	int scalar;
	ASSERT_NO_THROW(m1 * scalar);
}

TEST(TDynamicMatrix, correct_multiply_matric_and_scalar)
{
	TDynamicMatrix<int> m1(2), res(2), res_correct(2);
	int scalar = 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			res_correct[i][j] = 2;
			m1[i][j] = 1;
		}
	res = m1 * scalar;
	EXPECT_EQ(res_correct[0][0], res[0][0]);
	EXPECT_EQ(res_correct[0][1], res[0][1]);
	EXPECT_EQ(res_correct[1][0], res[1][0]);
	EXPECT_EQ(res_correct[1][1], res[1][1]);
}

TEST(TDynamicMatrix, can_multiply_matric_and_vector_with_equal_size)
{

	TDynamicMatrix<int> m1(2);
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(m1 * v);
}

TEST(TDynamicMatrix, correct_multiply_matrice_and_vector_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicVector<int> v(2), res(2), res_correct(2);

	for (int i = 0; i < 2; i++)
	{
		v[i] = 1;
		res_correct[i] = 2;
		for (int j = 0; j < 2; j++)
			m1[i][j] = 1;
	}
	res = m1 * v;
	EXPECT_EQ(res_correct[0], res[0]);
	EXPECT_EQ(res_correct[1], res[1]);
}

TEST(TDynamicMatrix, cant_multiply_matrice_and_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(3);
	ASSERT_ANY_THROW(m * v);
}
