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

/*TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> m1(m);
  ASSERT_NO_THROW(TDynamicMatrix<int> m2(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(m);
    EXPECT_NE(&m, &m1);
}
*/
TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(2);
    EXPECT_EQ(2, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(4);
    m[0][0] = 4;

    EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(4);
    ASSERT_ANY_THROW(m.at(-2,-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(4);
    ASSERT_ANY_THROW(m.at(5,7));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(1);
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(3);
    ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(5);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            c++;
        }
    }

    m1 = m;
    EXPECT_EQ(3, m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(5);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            c++;
        }
    }

    ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(3);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            m1[i][j] = c;
            c++;
        }
    }

    EXPECT_EQ(true, m==m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(3);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            c++;
        }
    }
    EXPECT_EQ(true, m==m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(5);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            m1[i][j] = c;
            c++;
        }
    }
    for (int i = m.size(); i< m1.size(); i++){
        for (int j = m.size(); j< m1.size(); j++){
            m1[i][j] = c;
            c++;
        }
    }
    EXPECT_EQ(true, m1!=m);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(3);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            m1[i][j] = c;
            c++;
        }
    }
    ASSERT_NO_THROW(m+m1);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(5);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            m1[i][j] = c;
            c++;
        }
    }
    for (int i = m.size(); i< m1.size(); i++){
        for (int j = m.size(); j< m1.size(); j++){
            m1[i][j] = c;
            c++;
        }
    }
    ASSERT_ANY_THROW(m+m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(3);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            m1[i][j] = c;
            c++;
        }
    }
    ASSERT_NO_THROW(m-m1);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(5);
    int c = 0;
    for (int i = 0; i< m.size(); i++){
        for (int j = 0; j < m.size(); j++){
            m[i][j] = c;
            m1[i][j] = c;
            c++;
        }
    }
    for (int i = m.size(); i< m1.size(); i++){
        for (int j = m.size(); j< m1.size(); j++){
            m1[i][j] = c;
            c++;
        }
    }
    ASSERT_ANY_THROW(m-m1);
}



