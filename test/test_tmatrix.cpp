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
	TDynamicMatrix<int> mat1(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> mat2 = mat1;
	EXPECT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> mat1(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> mat2 = mat1;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat2[i][j] = (i + j) * 2;
		}
	}
	EXPECT_NE(mat1, mat2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> mat1(1000);
	EXPECT_NO_THROW(mat1.size());
	EXPECT_EQ(mat1.size(), 1000);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> mat1(1000);
	mat1[111][222] = 1000;
	EXPECT_EQ(1000, mat1[111][222]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index_one)
{
	TDynamicMatrix<int> mat1(1000);
	ASSERT_ANY_THROW(mat1.at(-500).at(500));
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_two)//my
{
	TDynamicMatrix<int> mat1(1000);
	ASSERT_ANY_THROW(mat1.at(500).at(-500));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index_one)
{
	TDynamicMatrix<int> mat1(1000);
	ASSERT_ANY_THROW(mat1.at(1000).at(500));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index_two)//my
{
	TDynamicMatrix<int> mat1(1000);
	ASSERT_ANY_THROW(mat1.at(500).at(1000));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> mat1(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> mat2 = mat1;
	ASSERT_NO_THROW(mat1 = mat1);
	EXPECT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> mat1(1000), mat2(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat2[i][j] = (i + j) * 2;
		}
	}
	ASSERT_NO_THROW(mat1 = mat2);
	EXPECT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> mat1(1000), mat2(2000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) {
			mat2[i][j] = (i + j) * 2;
		}
	}
	ASSERT_NO_THROW(mat1 = mat2);
	EXPECT_EQ(mat1.size(), mat2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> mat1(1000), mat2(2000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) {
			mat2[i][j] = (i + j) * 2;
		}
	}
	ASSERT_NO_THROW(mat1 = mat2);
	EXPECT_EQ(mat1, mat2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> mat1(1000), mat2(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;	
			mat2[i][j] = i + j;
		}
	}
	ASSERT_NO_THROW(mat1 == mat2);
	EXPECT_EQ(mat1 == mat2, true);
}

TEST(TDynamicMatrix, compare_not_equal_matrices_return_false)//my
{
	TDynamicMatrix<int> mat1(1000), mat2(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
			mat2[i][j] = (i + j) * 2;
		}
	}
	ASSERT_NO_THROW(mat1 == mat2);
	EXPECT_EQ(mat1 == mat2, false);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> mat1(1000), mat2(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	ASSERT_NO_THROW(mat1 == mat1);
	EXPECT_EQ(mat1 == mat1, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> mat1(1000), mat2(2000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) {
			mat2[i][j] = i + j;
		}
	}
	ASSERT_NO_THROW(mat1 == mat2);
	EXPECT_EQ(mat1 == mat2, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> mat1(1000), mat2(1000), mat3(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
			mat2[i][j] = i + j;
			mat3[i][j] = 2 * (i + j);
		}
	}
	ASSERT_NO_THROW(mat1 + mat2);
	EXPECT_EQ(mat1 + mat2, mat3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> mat1(1000), mat2(2000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) {
			mat2[i][j] = i + j;
		}
	}
	ASSERT_ANY_THROW(mat1 + mat2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> mat1(1000), mat2(1000), mat3(1000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = 2 * (i + j);
			mat2[i][j] = i + j;
			mat3[i][j] = i + j;
		}
	}
	ASSERT_NO_THROW(mat1 - mat2);
	EXPECT_EQ(mat1 - mat2, mat3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> mat1(1000), mat2(2000);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mat1[i][j] = i + j;
		}
	}
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) {
			mat2[i][j] = i + j;
		}
	}
	ASSERT_ANY_THROW(mat1 - mat2);
}

