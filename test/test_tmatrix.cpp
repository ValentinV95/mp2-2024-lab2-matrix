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
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	TDynamicMatrix<int> m2(m1);

	EXPECT_EQ(m2, m1);
}

TEST(TDynamicMatrix, correct_copying)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	TDynamicMatrix<int> m2(m1);

	EXPECT_EQ(m2[0][0], 0);
	EXPECT_EQ(m2[0][1], 1);
	EXPECT_EQ(m2[1][0], 2);
	EXPECT_EQ(m2[1][1], 3);
}

TEST(TDynamicMatrix, correct_assigning)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	TDynamicMatrix<int> m2 = m1;

	EXPECT_EQ(m2[0][0], 0);
	EXPECT_EQ(m2[0][1], 1); 
	EXPECT_EQ(m2[1][0], 2); 
	EXPECT_EQ(m2[1][1], 3);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	TDynamicMatrix<int> m2(m1);
	m2[0][0] = 4; m2[0][1] = 5; m2[1][0] = 6; m2[1][1] = 7;

	EXPECT_EQ(m1[0][0], 0);
	EXPECT_EQ(m1[0][1], 1);
	EXPECT_EQ(m1[1][0], 2);
	EXPECT_EQ(m1[1][1], 3);

	EXPECT_EQ(m2[0][0], 4);
	EXPECT_EQ(m2[0][1], 5);
	EXPECT_EQ(m2[1][0], 6);
	EXPECT_EQ(m2[1][1], 7);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(2);
	ASSERT_NO_THROW(m.size());
}

TEST(TDynamicMatrix, correct_get_size)
{
	TDynamicMatrix<int> m(2);
	EXPECT_EQ(m.size(), 2);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(2);

	ASSERT_NO_THROW(m[0][1] = 4);
	ASSERT_NO_THROW(int a = m[0][1]);
}

TEST(TDynamicMatrix, correct_set_and_get_element)
{
	TDynamicMatrix<int> m(3);
	m[1][2] = 4;
	int a = m[1][2];

	EXPECT_EQ(m[1][2], 4, a);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(-1, 1) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(1, 2) = 2);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 0; m[0][1] = 1; m[1][0] = 2; m[1][1] = 3;

	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, correct_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 0; m[0][1] = 1; m[1][0] = 2; m[1][1] = 3;

	m = m;

	EXPECT_EQ(m[0][0], 0);
	EXPECT_EQ(m[0][1], 1);
	EXPECT_EQ(m[1][0], 2);
	EXPECT_EQ(m[1][1], 3);
}


TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;

	ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, correct_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;

	m2 = m1;

	EXPECT_EQ(m2[0][0], 0);
	EXPECT_EQ(m2[0][1], 1);
	EXPECT_EQ(m2[1][0], 2);
	EXPECT_EQ(m2[1][1], 3);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(2), m2(3);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;

	m2 = m1;
	EXPECT_EQ(m2.size(), 2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(2), m2(3);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;

	ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, correct_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(2), m2(3);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;

	m2 = m1;

	EXPECT_EQ(m2[0][0], 0);
	EXPECT_EQ(m2[0][1], 1);
	EXPECT_EQ(m2[1][0], 2);
	EXPECT_EQ(m2[1][1], 3);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(2), m2(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	m2 = m1;

	EXPECT_EQ(m2 == m1, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;

	EXPECT_EQ(m1 == m1, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(2), m2(3);

	EXPECT_EQ(m1 == m2, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	m2[0][0] = 4; m2[0][1] = 5; m2[1][0] = 6; m2[1][1] = 7;
	ASSERT_NO_THROW(m2 + m1);

}

TEST(TDynamicMatrix, correct_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2), m3(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	m2[0][0] = 4; m2[0][1] = 5; m2[1][0] = 6; m2[1][1] = 7;
	m3 = m2 + m1;

	EXPECT_EQ(m3[0][0], 4);
	EXPECT_EQ(m3[0][1], 6);
	EXPECT_EQ(m3[1][0], 8);
	EXPECT_EQ(m3[1][1], 10);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(3);
	ASSERT_ANY_THROW(m2 + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	m2[0][0] = 4; m2[0][1] = 5; m2[1][0] = 6; m2[1][1] = 7;
	ASSERT_NO_THROW(m2 - m1);
}

TEST(TDynamicMatrix, correct_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2), m3(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	m2[0][0] = 4; m2[0][1] = 5; m2[1][0] = 6; m2[1][1] = 7;
	m3 = m2 - m1;

	EXPECT_EQ(m3[0][0], 4);
	EXPECT_EQ(m3[0][1], 4);
	EXPECT_EQ(m3[1][0], 4);
	EXPECT_EQ(m3[1][1], 4);
}

TEST(TDynamicMatrix, cant_subtract_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(3);
	ASSERT_ANY_THROW(m2 - m1);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	m2[0][0] = 4; m2[0][1] = 5; m2[1][0] = 6; m2[1][1] = 7;
	ASSERT_NO_THROW(m2 * m1);
}

TEST(TDynamicMatrix, correct_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(2), m3(2);
	m1[0][0] = 0; m1[0][1] = 1; m1[1][0] = 2; m1[1][1] = 3;
	m2[0][0] = 4; m2[0][1] = 5; m2[1][0] = 6; m2[1][1] = 7;
	m3 = m2 * m1;

	EXPECT_EQ(m3[0][0], 10);
	EXPECT_EQ(m3[0][1], 19);
	EXPECT_EQ(m3[1][0], 14);
	EXPECT_EQ(m3[1][1], 27);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2), m2(3);
	ASSERT_ANY_THROW(m2 * m1);
}

TEST(TDynamicMatrix, cant_multiply_matrix_to_vector_with_not_equal_sizes)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(3);
	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrix_to_vector_with_equal_sizes)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(m * v);
}

TEST(TDynamicMatrix, correct_multiply_matrix_to_vector_with_equal_sizes)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v1(2), v2(2);
	m[0][0] = 0; m[0][1] = 1; m[1][0] = 2; m[1][1] = 3;
	v1[0] = 0; v1[1] = 1;
	v2 = m * v1;
	EXPECT_EQ(v2[0], 1);
	EXPECT_EQ(v2[1], 3);
}

TEST(TDynamicMatrix, can_multiply_matrix_to_scalar)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 0; m[0][1] = 1; m[1][0] = 2; m[1][1] = 3;
	int a = 2;
	ASSERT_NO_THROW(m * a);
}

TEST(TDynamicMatrix, correct_multiply_matrix_to_scalar)
{
	TDynamicMatrix<int> m(2), m2(2);
	m[0][0] = 0; m[0][1] = 1; m[1][0] = 2; m[1][1] = 3;
	int a = 2;
	m2 = m * a;

	EXPECT_EQ(m2[0][0], 0);
	EXPECT_EQ(m2[0][1], 2);
	EXPECT_EQ(m2[1][0], 4);
	EXPECT_EQ(m2[1][1], 6);
}