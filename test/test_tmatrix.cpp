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
  EXPECT_NO_THROW(TDynamicMatrix<int> m1(m));


}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(m);
    EXPECT_EQ(m, m1);

}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(m);
    m[0][0] = 5;
    m1[0][0] = 4;
    EXPECT_NE(m, m1);

}

TEST(TDynamicMatrix, can_get_size_correct)
{
    TDynamicMatrix<int> m(5);
    EXPECT_EQ(m.size(), 5);

}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(5);
    m[0][0] = 5;
    EXPECT_EQ(m[0][0], 5);

}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m.at(-1,-1) = 5); 

}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m.at(6, 6) = 5); 

}
TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(5);
    ASSERT_NO_THROW(m = m);
}
TEST(TDynamicMatrix, assignment_matrix_to_itself_is_correct)
{
    TDynamicMatrix<int> m(5);
    m = m;
    EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    ASSERT_NO_THROW(m = m1);
}
TEST(TDynamicMatrix, assignment_matrices_of_equal_size_is_correct)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    m = m1;
    EXPECT_EQ(m, m1);

}
TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    m = m1;
    EXPECT_EQ(m.size(), m1.size());

}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, assignment_matrices_of_different_size_is_correct)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    m1 = m;
    EXPECT_EQ(m, m1);
}
TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i;
            m1[i][j] = i;
        }
    }
    EXPECT_EQ(m,m1);

}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i;
        }
    }
    EXPECT_EQ(m, m);

}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    EXPECT_NE(m , m1);

}
TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
            m1[i][j] = 2 * i + j;
        }
    }
    ASSERT_NO_THROW(m + m1);

}
TEST(TDynamicMatrix, addition_matrices_with_equal_size_is_correct)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> res(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i+j;
            m1[i][j] = 2*i+j;
            res[i][j] = 3 * i + 2 * j;
        }
    }
    EXPECT_EQ(m + m1, res);

}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    ASSERT_ANY_THROW(m + m1);

}
TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
            m1[i][j] = 2 * i + j;
        }
    }
    ASSERT_NO_THROW(m - m1);
}
TEST(TDynamicMatrix, subtraction_matrices_with_equal_size_is_correct)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> res(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
            m1[i][j] = 2 * i + j;
            res[i][j] =  -i;
        }
    }
    EXPECT_EQ(m - m1, res);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    ASSERT_ANY_THROW(m - m1);
}
TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(3);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
            m1[i][j] = 2 * i + j;
        }
    }
    ASSERT_NO_THROW(m *m1);
}
TEST(TDynamicMatrix, multiplication_matrices_with_equal_size_is_correct)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> res(2);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
            m1[i][j] = 2 * i + j;
        }
    }
    res[0][0] = 2;
    res[0][1] = 3;
    res[1][0] = 4;
    res[1][1] = 7;
    EXPECT_EQ(m * m1,res);
}
TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(4);
    ASSERT_ANY_THROW(m * m1);
}
TEST(TDynamicMatrix, can_multiply_matrix_with_vector_with_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicVector<int> v(3);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
            
        }
        v[i] = 2 * i;
    }
    ASSERT_NO_THROW(m * v);
}
TEST(TDynamicMatrix, multiplication_matrix_with_vector_with_equal_size_is_correct)
{
    TDynamicMatrix<int> m(2);
    TDynamicVector<int> v(2),res(2);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
            
        }
        v[i] = 2 * i ;
    }
    res[0] = 2;
    res[1] = 4;
    EXPECT_EQ(res, m * v);
}
TEST(TDynamicMatrix, cant_multiply_matrix_with_vector_with_equal_size)
{
    TDynamicMatrix<int> m(3);
    TDynamicVector<int> v(4);
    ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrix_with_scalar)
{
    TDynamicMatrix<int> m(3);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;

        }
    }
    ASSERT_NO_THROW(m * 2);
}
TEST(TDynamicMatrix, multiplication_matrix_with_scalar_is_correct)
{
    TDynamicMatrix<int> m(2),res(2);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            m[i][j] = i + j;
        }
    }
    res[0][0] = 0;
    res[0][1] = 2;
    res[1][0] = 2;
    res[1][1] = 4;
    EXPECT_EQ(m * 2,res);
}