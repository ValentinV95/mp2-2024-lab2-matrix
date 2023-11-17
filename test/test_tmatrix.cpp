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
	TDynamicMatrix<int> A(3);
	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][2] = 9;
	TDynamicMatrix<int> B(A);
	EXPECT_EQ(A, B);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	
	TDynamicMatrix<int> A(3);
	A[0][0] = 2;
	A[0][1] = 1;
	A[0][2] = 7;
	A[1][0] = 89;
	A[1][1] = 189;
	A[1][2] = 15;
	A[2][0] = 89;
	A[2][1] = 8;
	A[2][2] = 7952;
	TDynamicMatrix<int> B(A);
	EXPECT_NE(2, A[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> A(3);
	EXPECT_EQ(3, A.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> A(3);
	A[2][0] = 1528;
	EXPECT_EQ(A[2][0], 1528);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	
	TDynamicMatrix<int> A(3);
	ASSERT_ANY_THROW(A.at(-2, 0) = -87);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> A(2);
	ASSERT_ANY_THROW(A.at(3, 3) = 7);

}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	
	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	A = A;
	EXPECT_EQ(A, A);

}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	
	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	TDynamicMatrix<int> B(3);
	B = A;
	EXPECT_EQ(A, B);

}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{

	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	TDynamicMatrix<int> B(8);
	B = A;
	int c = B.size();
	EXPECT_EQ(c, 3);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	
	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	TDynamicMatrix<int> B(8);
	B = A;
	EXPECT_EQ(A, B);
}


TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	

	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	TDynamicMatrix<int> B(3);
	B = A;
	EXPECT_TRUE(A == B);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	

	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	EXPECT_TRUE(A == A);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{

	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(8);

	EXPECT_NE(A, B);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	
	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	TDynamicMatrix<int> B(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			B[i][j] = rand();
	TDynamicMatrix<int> C(3);
	C = A + B;

	EXPECT_EQ(C, A + B);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{

	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(8);
	ASSERT_ANY_THROW(A + B);

}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{

	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	TDynamicMatrix<int> B(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			B[i][j] = rand();
	TDynamicMatrix<int> C(3);
	C = A - B;
	EXPECT_EQ(C, A - B);
	 
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{

	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(8);
	ASSERT_ANY_THROW(A - B);
}
TEST(TDynamicMatrix, can_mul_matrices_with_equal_size)
{

	TDynamicMatrix<int> A(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A[i][j] = rand();
	TDynamicMatrix<int> B(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			B[i][j] = rand();
	TDynamicMatrix<int> C(3);
	C = A * B;
	EXPECT_EQ(C, A * B);

}

TEST(TDynamicMatrix, cant_mul_matrixes_with_not_equal_size)
{

	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(8);
	ASSERT_ANY_THROW(A* B);
}
