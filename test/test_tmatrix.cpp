#include "utmatrix.h"

#include "gtest.h"

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	m1[0][0] = 5; m1[0][1] = 7; m1[0][2] = 8; m1[0][3] = 3; m1[0][4] = 4;
	m1[1][1] = 5; m1[1][2] = 7; m1[1][3] = 8; m1[1][4] = 3;
	m1[2][2] = 5; m1[2][3] = 7; m1[2][4] = 8;
	m1[3][3] = 5; m1[3][4] = 7;
	m1[4][4] = 5;
	TMatrix<int> m2(m1);
	ASSERT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	ASSERT_NE(&m1, &m2);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	ASSERT_EQ(m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m[3][3] = 7);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-5][-5]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[6][6]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(3), m2(3);
	m1[0][0] = 10; m1[0][1] = 10; m1[0][2] = 10;
	m1[1][1] = 10; m1[1][2] = 10; m1[2][2] = 10;
	m2[0][0] = 1; m2[0][1] = 1; m2[0][2] = 1;
	m2[1][1] = 1; m2[1][2] = 1; m2[2][2] = 1;
	ASSERT_NO_THROW(m1 = m2);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(5), m2(6);
	m1 = m2;
	ASSERT_EQ(m1.GetSize(), 6);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(3), m2(4);
	m1[0][0] = 10; m1[0][1] = 10; m1[0][2] = 10;
	m1[1][1] = 10; m1[1][2] = 10; m1[2][2] = 10;
	m2[0][0] = 1; m2[0][1] = 1; m2[0][2] = 1;
	m2[1][1] = 1; m2[1][2] = 1; m2[2][2] = 1;
	ASSERT_NO_THROW(m1 = m2);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(5), m2(5);
	ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	ASSERT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5), m2(6);
	ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(3), m2(3), m3(3);
	m1[0][0] = 10; m1[0][1] = 10; m1[0][2] = 10;
	m1[1][1] = 10; m1[1][2] = 10; m1[2][2] = 10;
	m2[0][0] = 1; m2[0][1] = 1; m2[0][2] = 1;
	m2[1][1] = 1; m2[1][2] = 1; m2[2][2] = 1;
	m3[0][0] = 9; m3[0][1] = 9; m3[0][2] = 9;
	m3[1][1] = 9; m3[1][2] = 9; m3[2][2] = 9;
	ASSERT_NO_THROW(m1 + m2);
	EXPECT_EQ(m2 + m3, m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(4), m2(4), m3(3);
	m1[0][0] = 10; m1[0][1] = 10; m1[0][2] = 10;
	m1[1][1] = 10; m1[1][2] = 10; m1[2][2] = 10;
	m2[0][0] = 1; m2[0][1] = 1; m2[0][2] = 1;
	m2[1][1] = 1; m2[1][2] = 1; m2[2][2] = 1;
	m3[0][0] = 9; m3[0][1] = 9; m3[0][2] = 9;
	m3[1][1] = 9; m3[1][2] = 9; m3[2][2] = 9;
	ASSERT_NO_THROW(m1 + m2);

}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(3), m2(3), m3(3);
	m1[0][0] = 10; m1[0][1] = 10; m1[0][2] = 10;
	m1[1][1] = 10; m1[1][2] = 10; m1[2][2] = 10;
	m2[0][0] = 1; m2[0][1] = 1; m2[0][2] = 1;
	m2[1][1] = 1; m2[1][2] = 1; m2[2][2] = 1;
	m3[0][0] = 9; m3[0][1] = 9; m3[0][2] = 9;
	m3[1][1] = 9; m3[1][2] = 9; m3[2][2] = 9;
	ASSERT_NO_THROW(m1 - m2);
	EXPECT_EQ(m1 - m2, m3);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(5), m2(6);
	ASSERT_ANY_THROW(m1 - m2);
}

 