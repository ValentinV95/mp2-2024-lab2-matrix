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
	TDynamicMatrix<int> A(5);
	A[1][1] = 3;
	A[2][2] = 4;
	A[4][3] = 6;
	TDynamicMatrix<int> B(A);
	EXPECT_EQ(A, B);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> A(5);
	A[1][1] = 3;
	A[2][2] = 4;
	A[4][3] = 6;
	TDynamicMatrix<int> B(A);
	B[4][4] = 10;
	A[4][4] = 11;
	EXPECT_NE(A[4][4], B[4][4]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> A(5);
	EXPECT_EQ(A.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> A(3);
	ASSERT_NO_THROW(A[2][2] = 8;);
	EXPECT_EQ(A[2][2], 8);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> A(3);
	ASSERT_ANY_THROW(A.at(-1, 2) = 8;);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> A(3);
	ASSERT_ANY_THROW(A.at(1, 4) = 8;);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> A(3);
	ASSERT_NO_THROW(A = A);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 8;
	TDynamicMatrix<int> B(3);
	B[1][1] = 11;
	B = A;
	EXPECT_EQ(A, B);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(4);
	B = A;
	EXPECT_EQ(B.size(), A.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> A(4);
	A[1][1] = 8;
	TDynamicMatrix<int> B(3);
	B = A;
	EXPECT_EQ(A, B);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 8;
	A[2][2] = 3;
	TDynamicMatrix<int> B(3);
	B[1][1] = 8;
	B[2][2] = 3;
	EXPECT_EQ(A == B, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 8;
	A[2][2] = 3;
	EXPECT_EQ(A == A, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(4);
	EXPECT_EQ(A == B, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 8;
	A[2][2] = 3;
	TDynamicMatrix<int> B(3);
	B[1][1] = 1;
	B[2][2] = 4;
	TDynamicMatrix<int> C(3);
	C[1][1] = 9;
	C[2][2] = 7;
	TDynamicMatrix<int> D(5);
	D = A + B;
	EXPECT_EQ(D, C);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 8;
	A[2][2] = 3;
	TDynamicMatrix<int> B(4);
	B[1][1] = 5;
	B[2][2] = 1;
	ASSERT_ANY_THROW(A + B);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 8;
	A[2][2] = 3;
	TDynamicMatrix<int> B(3);
	B[1][1] = 5;
	B[2][2] = 1;
	TDynamicMatrix<int> C(3);
	C[1][1] = 3;
	C[2][2] = 2;
	TDynamicMatrix<int> D(4);
	D = A - B;
	EXPECT_EQ(D, C);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 8;
	A[2][2] = 3;
	TDynamicMatrix<int> B(4);
	B[1][1] = 4;
	B[2][2] = 2;
	ASSERT_ANY_THROW(A - B);
}

TEST(TDynamicMatrix, can_multiply_matrix_and_vector)
{
	TDynamicMatrix<int> A(3);
	A[0][0] = 8;
	A[0][1] = 3;
	A[0][2] = 1;
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;

	ASSERT_NO_THROW(v2 = A * v1);
	EXPECT_EQ(17, v2[0]);
}

TEST(TDynamicMatrix, cant_multiply_matrix_and_vector_with_different_sizes)
{
	TDynamicMatrix<int> A(3);
	TDynamicVector<int> v(4);

	ASSERT_ANY_THROW(A*v);
}

TEST(TDynamicMatrix, can_multiply_two_matrices)
{
	TDynamicMatrix<int> A(3), B(3), C(3);

	A[0][0] = 8;
	A[0][1] = 3;
	A[0][2] = 1;

	B[0][0] = 1;
	B[1][0] = 2;
	B[2][0] = 3;

	ASSERT_NO_THROW(C = A * B);
	EXPECT_EQ(17, C[0][0]);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_different_sizes)
{
	TDynamicMatrix<int> A(3), B(4);
	ASSERT_ANY_THROW(A * B);
}

