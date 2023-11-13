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
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 1; m1[0][1] = 2;
	m1[1][0] = 3; m1[1][1] = 4;

	TDynamicMatrix<int> m2(m1);
	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int>* m1 = new TDynamicMatrix<int>(2);
	TDynamicMatrix<int>* m2 = new TDynamicMatrix<int>(*m1);

	delete m1;
	ASSERT_NO_THROW(delete m2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(3);
	EXPECT_EQ(3, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 7;
	EXPECT_EQ(7, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(20);
	ASSERT_ANY_THROW(m.at(3, -10) = 4);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(20);
	ASSERT_ANY_THROW(m.at(3, m.size()) = 4);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(20);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, self_assignment_doesnt_change_matrix_values)
{
	TDynamicMatrix<int> m(20);
	m[4][3] = 42;
	m = m;
	EXPECT_EQ(42, m[4][3]);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(3);
	ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, assignment_copies_values)
{
	TDynamicMatrix<int> m1(3), m2(3);
	m1[1][1] = 42;
	m2 = m1;
	EXPECT_EQ(42, m2[1][1]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(8), m2(4);
	m2 = m1;
	EXPECT_EQ(8, m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(3), m2(4);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_returns_true)
{
	TDynamicMatrix<int> m1(3), m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m1[i][j] = i * j;
			m2[i][j] = i * j;
		}

	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_returns_true)
{
	TDynamicMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = i * j;
		}

	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(3), m2(7);
	EXPECT_FALSE(m1 == m2);
}

TEST(TDynamicMatrix, inequality_with_itself_returns_false)
{
	TDynamicMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = i * j;
		}

	EXPECT_FALSE(m != m);
}

TEST(TDynamicMatrix, inequality_with_matrices_with_different_size_returns_true)
{
	TDynamicMatrix<int> m1(3), m2(7);
	EXPECT_TRUE(m1 != m2);
}

TEST(TDynamicMatrix, inequality_with_equal_matrices_returns_false)
{
	TDynamicMatrix<int> m1(3), m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m1[i][j] = i * j;
			m2[i][j] = i * j;
		}

	EXPECT_FALSE(m1 != m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	ASSERT_NO_THROW(m1 + m2);
}

TEST(TDynamicMatrix, matrix_addition_is_correct)
{
	TDynamicMatrix<int> m1(2), m2(2), m3(2);
	m1[0][0] = 1; m1[0][1] = 2;
	m1[1][0] = 3; m1[1][1] = 4;

	m2[0][0] = 4; m2[0][1] = 3;
	m2[1][0] = 2; m2[1][1] = 1;

	m3 = m1 + m2;
	ASSERT_EQ(5, m3[0][0]);
	ASSERT_EQ(5, m3[0][1]);
	ASSERT_EQ(5, m3[1][0]);
	ASSERT_EQ(5, m3[1][1]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(5);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	ASSERT_NO_THROW(m1 - m2);
}

TEST(TDynamicMatrix, matrix_subtraction_is_correct)
{
	TDynamicMatrix<int> m1(2), m2(2), m3(2);
	m1[0][0] = 1; m1[0][1] = 2;
	m1[1][0] = 3; m1[1][1] = 4;

	m2[0][0] = 4; m2[0][1] = 3;
	m2[1][0] = 2; m2[1][1] = 1;

	m3 = m1 - m2;
	ASSERT_EQ(-3, m3[0][0]);
	ASSERT_EQ(-1, m3[0][1]);
	ASSERT_EQ(1, m3[1][0]);
	ASSERT_EQ(3, m3[1][1]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(5);
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_multiply_matrix_and_vector)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(m * v);
}

TEST(TDynamicMatrix, matrix_and_vector_multiplication_is_correct)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(2), r(2);

	m[0][0] = 1; m[0][1] = 2;
	m[1][0] = 3; m[1][1] = 4;

	v[0] = 1; v[1] = 2;

	r = m * v;
	ASSERT_EQ(5, r[0]);
	ASSERT_EQ(11, r[1]);
}

TEST(TDynamicMatrix, cant_multiply_matrix_and_vector_with_different_sizes)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(4);

	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_two_matrices)
{
	TDynamicMatrix<int> m1(2), m2(2);
	ASSERT_NO_THROW(m1 * m2);
}

TEST(TDynamicMatrix, matrix_multiplication_is_correct)
{
	TDynamicMatrix<int> m1(2), m2(2), m3(2);
	m1[0][0] = 1; m1[0][1] = 2;
	m1[1][0] = 3; m1[1][1] = 4;

	m2[0][0] = 4; m2[0][1] = 3;
	m2[1][0] = 2; m2[1][1] = 1;

	m3 = m1 * m2;
	ASSERT_EQ(8, m3[0][0]);
	ASSERT_EQ(5, m3[0][1]);
	ASSERT_EQ(20, m3[1][0]);
	ASSERT_EQ(13, m3[1][1]);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_different_sizes)
{
	TDynamicMatrix<int> m1(2), m2(3);
	ASSERT_ANY_THROW(m1 * m2);
}

TEST(TDynamicMatrix, operators_shr_and_shl_dont_change_values)
{
	TDynamicMatrix<int> m1(2), m2(2);
	stringstream ss;
	m1[0][0] = 1; m1[0][1] = 2;
	m1[1][0] = 3; m1[1][1] = 4;

	ss << m1;
	ss >> m2;
	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, operator_shr_handles_invalid_input)
{
	TDynamicMatrix<int> m(2);
	stringstream ss;
	ss << "1 2 a 3";
	ASSERT_ANY_THROW(ss >> m);
}