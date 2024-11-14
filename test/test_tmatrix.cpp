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
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);

	int* pMem_0 = new int [3] { 0, 0, 0};
	int* pMem_1 = new int [3] { 0, 0, 0};
	int* pMem_2 = new int [3] {0, 0, 0};

	int* pMem_new = new int [3] {1, 2, 3};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_new(pMem_new, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	delete[] pMem_new;

	matrix[0] = v_0;
	matrix[1] = v_new;
	matrix[2] = v_2;



	EXPECT_EQ(matrix[1], v_new);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int>* matrix_ptr = &matrix;
	TDynamicMatrix<int> matrix_new(matrix);
	TDynamicMatrix<int>* matrix_new_ptr = &matrix_new;

	EXPECT_NE(matrix_new_ptr, matrix_ptr);
}

TEST(TDynamicMatrix, can_get_size)
{
  //ADD_FAILURE();

	int size = 3;

	TDynamicMatrix<int> matrix(size);

	EXPECT_EQ(matrix.size(), size);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);

	int* pMem_0 = new int [3] { 0, 0, 0};
	int* pMem_1 = new int [3] { 0, 0, 0};
	int* pMem_2 = new int [3] {0, 0, 0};

	int* pMem_new = new int [3] {1, 2, 3};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_new(pMem_new, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	delete[] pMem_new;

	matrix[0] = v_0;
	matrix[1] = v_new;
	matrix[2] = v_2;



	EXPECT_EQ(matrix[1], v_new);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	ASSERT_ANY_THROW(matrix.at(-2) = 0);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
  //ADD_FAILURE();
	TDynamicMatrix<int> matrix(3);

	ASSERT_ANY_THROW(matrix.at(6) = 0);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int[3] {7, 1, 8};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	ASSERT_NO_THROW(matrix = matrix);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_copy(3);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int [3] {7, 1, 8};

	int* pMem_copy_0 = new int [3] { 0, 0, 0};
	int* pMem_copy_1 = new int [3] { 0, 0, 0};
	int* pMem_copy_2 = new int [3] { 0, 0, 0};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_copy_0(pMem_copy_0, 3);
	TDynamicVector<int> v_copy_1(pMem_copy_1, 3);
	TDynamicVector<int> v_copy_2(pMem_copy_2, 3);


	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	delete[] pMem_copy_0;
	delete[] pMem_copy_1;
	delete[] pMem_copy_2;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	matrix_copy[0] = v_copy_0;
	matrix_copy[1] = v_copy_1;
	matrix_copy[2] = v_copy_2;

	matrix_copy = matrix;

	EXPECT_EQ(matrix_copy, matrix);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_new(2);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int [3] { 7, 1, 8};

	int* pMem_new_0 = new int [2] { 5, 1};
	int* pMem_new_1 = new int [2] { 5, 1};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_new_0(pMem_new_0, 2);
	TDynamicVector<int> v_new_1(pMem_new_1, 2);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	delete[] pMem_new_0;
	delete[] pMem_new_1;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	matrix_new[0] = v_new_0;
	matrix_new[1] = v_new_1;

	matrix = matrix_new;

	EXPECT_EQ(matrix.size(), 2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_new(2);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int [3] {7, 1, 8};

	int* pMem_new_0 = new int [2] { 5, 1};
	int* pMem_new_1 = new int [2] { 5, 1};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_new_0(pMem_new_0, 2);
	TDynamicVector<int> v_new_1(pMem_new_1, 2);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	delete[] pMem_new_0;
	delete[] pMem_new_1;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	matrix_new[0] = v_new_0;
	matrix_new[1] = v_new_1;

	matrix = matrix_new;

	EXPECT_EQ(matrix, matrix_new);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  //ADD_FAILURE();
	
	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_new(3);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int[3] {7, 1, 8};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_new_0(pMem_0, 3);
	TDynamicVector<int> v_new_1(pMem_1, 3);
	TDynamicVector<int> v_new_2(pMem_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	matrix_new[0] = v_0;
	matrix_new[1] = v_1;
	matrix_new[2] = v_2;

	EXPECT_EQ(matrix == matrix_new, 1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int[3] {7, 1, 8};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	EXPECT_EQ(matrix == matrix, 1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  //ADD_FAILURE();----

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_new(2);

	EXPECT_EQ(matrix != matrix_new, 1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_add(3);
	TDynamicMatrix<int> matrix_result(3);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int [3] {7, 1, 8};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_add_0(pMem_0, 3);
	TDynamicVector<int> v_add_1(pMem_1, 3);
	TDynamicVector<int> v_add_2(pMem_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	matrix_add[0] = v_add_0;
	matrix_add[1] = v_add_1;
	matrix_add[2] = v_add_2;

	pMem_0 = new int [3] { 10, 2, 10};
	pMem_1 = new int [3] { 12, 2, 18};
	pMem_2 = new int [3] { 14, 2, 16};

	TDynamicVector<int> v_result_0(pMem_0, 3);
	TDynamicVector<int> v_result_1(pMem_1, 3);
	TDynamicVector<int> v_result_2(pMem_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	matrix_result[0] = v_result_0;
	matrix_result[1] = v_result_1;
	matrix_result[2] = v_result_2;

	EXPECT_EQ(matrix + matrix_add, matrix_result);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_add(5);

	ASSERT_ANY_THROW(matrix + matrix_add);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_subtract(3);
	TDynamicMatrix<int> matrix_result(3);

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int [3] {7, 1, 8};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_add_0(pMem_0, 3);
	TDynamicVector<int> v_add_1(pMem_1, 3);
	TDynamicVector<int> v_add_2(pMem_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	matrix_subtract[0] = v_add_0;
	matrix_subtract[1] = v_add_1;
	matrix_subtract[2] = v_add_2;

	pMem_0 = new int [3] { 0, 0, 0};
	pMem_1 = new int [3] { 0, 0, 0};
	pMem_2 = new int [3] { 0, 0, 0};

	TDynamicVector<int> v_result_0(pMem_0, 3);
	TDynamicVector<int> v_result_1(pMem_1, 3);
	TDynamicVector<int> v_result_2(pMem_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	matrix_result[0] = v_result_0;
	matrix_result[1] = v_result_1;
	matrix_result[2] = v_result_2;

	EXPECT_EQ(matrix - matrix_subtract, matrix_result);

}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  //ADD_FAILURE();

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_subtract(5);

	ASSERT_ANY_THROW(matrix - matrix_subtract);
}

TEST(TDynamicMatrix, can_multiplying_matrix_by_scalar) {

	TDynamicMatrix<int> matrix(3);
	TDynamicMatrix<int> matrix_result(3);
	int val = 2;

	int* pMem_0 = new int [3] { 5, 1, 5};
	int* pMem_1 = new int [3] { 6, 1, 9};
	int* pMem_2 = new int [3] {7, 1, 8};

	int* pMem_new_0 = new int [3] { 10, 2, 10};
	int* pMem_new_1 = new int [3] { 12, 2, 18};
	int* pMem_new_2 = new int [3] { 14, 2, 16};

	TDynamicVector<int> v_0(pMem_0, 3);
	TDynamicVector<int> v_1(pMem_1, 3);
	TDynamicVector<int> v_2(pMem_2, 3);

	TDynamicVector<int> v_new_0(pMem_new_0, 3);
	TDynamicVector<int> v_new_1(pMem_new_1, 3);
	TDynamicVector<int> v_new_2(pMem_new_2, 3);

	delete[] pMem_0;
	delete[] pMem_1;
	delete[] pMem_2;

	delete[] pMem_new_0;
	delete[] pMem_new_1;
	delete[] pMem_new_2;

	matrix[0] = v_0;
	matrix[1] = v_1;
	matrix[2] = v_2;

	matrix_result[0] = v_new_0;
	matrix_result[1] = v_new_1;
	matrix_result[2] = v_new_2;

	EXPECT_EQ(matrix * val, matrix_result);
}

