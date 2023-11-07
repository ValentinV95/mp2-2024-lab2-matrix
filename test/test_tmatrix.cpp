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
	int inp[4];
	for (size_t i = 0; i < 4; i++) {
		inp[i] = rand() % 20;
	}
	TDynamicMatrix<int> a(2);
	a[0][0] = inp[0];
	a[0][1] = inp[1];
	a[1][0] = inp[2];
	a[1][1] = inp[3];
	TDynamicMatrix<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> a(5);
	TDynamicMatrix<int> b(a);
	EXPECT_NE(&a[0], &b[0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> a(5);
	EXPECT_EQ(a.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	int a = rand() % 8;
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a;
	ASSERT_EQ(mat1[0][0], a);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> mat1(2);
	ASSERT_ANY_THROW(mat1.at(-2));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> mat1(2);
	ASSERT_ANY_THROW(mat1.at(4));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(2);
	mat2[0][0] = a[0];
	mat2[0][1] = a[1];
	mat2[1][0] = a[2];
	mat2[1][1] = a[3];
	mat1 = mat1;
	EXPECT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(2);
	mat2 = mat1;
	EXPECT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(6);
	mat2 = mat1;
	EXPECT_EQ(mat1.size(), mat2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(6);
	mat2 = mat1;
	EXPECT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(2);
	mat2[0][0] = a[0];
	mat2[0][1] = a[1];
	mat2[1][0] = a[2];
	mat2[1][1] = a[3];
	ASSERT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	EXPECT_EQ(mat1, mat1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(3);
	mat2[0][0] = a[0];
	mat2[0][1] = a[1];
	mat2[1][0] = a[2];
	mat2[1][1] = a[3];
	EXPECT_EQ(mat1 == mat2, 0);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	int b[4];
	for (size_t i = 0; i < 4; i++) {
		b[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(2);
	mat2[0][0] = b[0];
	mat2[0][1] = b[1];
	mat2[1][0] = b[2];
	mat2[1][1] = b[3];
	mat1 = mat1 + mat2;
	int c[4] = { a[0]+b[0], a[1]+b[1], a[2]+b[2], a[3]+b[3] };
	EXPECT_EQ(mat1[0][0], c[0]);
	EXPECT_EQ(mat1[0][1], c[1]);
	EXPECT_EQ(mat1[1][0], c[2]);
	EXPECT_EQ(mat1[1][1], c[3]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	int b[4];
	for (size_t i = 0; i < 4; i++) {
		b[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(3);
	mat2[0][0] = b[0];
	mat2[0][1] = b[1];
	mat2[1][0] = b[2];
	mat2[1][1] = b[3];
	ASSERT_ANY_THROW(mat1 + mat2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	int b[4];
	for (size_t i = 0; i < 4; i++) {
		b[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(2);
	mat2[0][0] = b[0];
	mat2[0][1] = b[1];
	mat2[1][0] = b[2];
	mat2[1][1] = b[3];
	mat1 = mat1 - mat2;
	int c[4] = { a[0]-b[0], a[1]-b[1], a[2]-b[2], a[3]-b[3] };
	EXPECT_EQ(mat1[0][0], c[0]);
	EXPECT_EQ(mat1[0][1], c[1]);
	EXPECT_EQ(mat1[1][0], c[2]);
	EXPECT_EQ(mat1[1][1], c[3]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	int a[4];
	for (size_t i = 0; i < 4; i++) {
		a[i] = rand() % 20;
	}
	int b[4];
	for (size_t i = 0; i < 4; i++) {
		b[i] = rand() % 20;
	}
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(3);
	mat2[0][0] = b[0];
	mat2[0][1] = b[1];
	mat2[1][0] = b[2];
	mat2[1][1] = b[3];
	ASSERT_ANY_THROW(mat1 - mat2);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	int a[4] = { 2, 4, 9, 1 };
	int b[4] = { 3, 9, 0, 1 };
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(2);
	mat2[0][0] = b[0];
	mat2[0][1] = b[1];
	mat2[1][0] = b[2];
	mat2[1][1] = b[3];
	mat1 = mat1 * mat2;
	int c[4] = { 6, 22, 27, 82 };
	EXPECT_EQ(mat1[0][0], c[0]);
	EXPECT_EQ(mat1[0][1], c[1]);
	EXPECT_EQ(mat1[1][0], c[2]);
	EXPECT_EQ(mat1[1][1], c[3]);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	int a[4] = { 2, 4, 9, 1 };
	int b[4] = { 3, 9, 0, 1 };
	TDynamicMatrix<int> mat1(2);
	mat1[0][0] = a[0];
	mat1[0][1] = a[1];
	mat1[1][0] = a[2];
	mat1[1][1] = a[3];
	TDynamicMatrix<int> mat2(3);
	mat2[0][0] = b[0];
	mat2[0][1] = b[1];
	mat2[1][0] = b[2];
	mat2[1][1] = b[3];
	ASSERT_ANY_THROW(mat1 * mat2);
}
