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
	ASSERT_NO_THROW(TDynamicMatrix<int> m1 = m);
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2 = m;
	EXPECT_EQ(m, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2 = m;
	m2[0][0] = 100;
	EXPECT_NE(m[0][0], m2[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);
	m.size();
	EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(5));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5), m2 = m;
	m = m;
	EXPECT_EQ(m2, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(5), m2(5);
	ASSERT_NO_THROW(m = m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(4), m2(5);
	m = m2;
	EXPECT_EQ(m.size(), m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(5), m2(10);
	ASSERT_NO_THROW(m = m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2 = m;
	EXPECT_EQ(1, m == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[i][j] = i + j;
		}
	}
	EXPECT_EQ(1, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2(10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m2[i][j] = i + j;
		}
	}
	EXPECT_EQ(0, m == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2 = m;
	m2 = m2 + m;
	TDynamicMatrix<int> m3(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m3[i][j] = 2 * (i + j);
		}
	}
	EXPECT_EQ(m3, m2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(5), m2(10);
	ASSERT_ANY_THROW(m2 + m);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2 = m;
	m2 = m2 - m;
	TDynamicMatrix<int> m3(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m3[i][j] = 0;
		}
	}
	EXPECT_EQ(m3, m2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(5), m2(10);
	ASSERT_ANY_THROW(m2 - m);
}

TEST(TDynamicMatrix, can_multiplication_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3), m2(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = i + j;
			m2[i][j] = i + j;
		}
	}
	m = m2 * m;
	TDynamicMatrix<int> res(3);
	res[0][0] = 5; res[0][1] = 8; res[0][2] = 11;
	res[1][0] = 8; res[1][1] = 14; res[1][2] = 20;
	res[2][0] = 11; res[2][1] = 20; res[2][2] = 29;
	EXPECT_EQ(res, m);
}

TEST(TDynamicMatrix, cant_multiplication_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3), m2(5);
	ASSERT_ANY_THROW(m * m2);
}