#include "utmatrix.h"

#include "gtest.h"

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v1(10);
	TVector<int> v2(v1);

	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(10);
	TVector<int> v2(v1);
	v2[5] = 7;
	ASSERT_NE(v2[5], v1[5]);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);

	EXPECT_NO_THROW(v[0] = 4);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-4] = 6);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[4] = 6);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5);

	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(5), v2(5);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;
	v2[1] = 5; v2[3] = 8;

	ASSERT_NO_THROW(v1 = v2);
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(5), v2(7);
	v2 = v1;
	ASSERT_EQ(5, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(5), v2(7);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;
	v2[1] = 5; v2[3] = 8;
	v1 = v2;
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(5);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;
	TVector<int> v2(v1);

	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v1(5);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;

	ASSERT_TRUE(v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(5), v2(7);

	ASSERT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(5), v2(5);
	v1[0] = 10; v1[1] = 9; v1[2] = 8; v1[3] = 7; v1[4] = 6;
	v2[0] = 15; v2[1] = 14; v2[2] = 13; v2[3] = 12; v2[4] = 11;

	ASSERT_NO_THROW(v1 + 5);
	EXPECT_EQ(v1 + 5, v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(5), v2(5);
	v1[0] = 10; v1[1] = 9; v1[2] = 8; v1[3] = 7; v1[4] = 6;
	v2[0] = 5; v2[1] = 4; v2[2] = 3; v2[3] = 2; v2[4] = 1;

	ASSERT_NO_THROW(v1 - 5);
	EXPECT_EQ(v1 - 5, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(5), v2(5), v3(5);
	v1[0] = 10; v1[1] = 9; v1[2] = 8; v1[3] = 7; v1[4] = 6;
	v2[0] = 5; v2[1] = 4; v2[2] = 3; v2[3] = 2; v2[4] = 1;
	v3[0] = 15; v3[1] = 13; v3[2] = 11; v3[3] = 9; v3[4] = 7;
	ASSERT_NO_THROW(v1 - v2);
	EXPECT_EQ(v1 + v2, v3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;
	v2[1] = 5; v2[3] = 8;

	ASSERT_NO_THROW(v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(7);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;
	v2[1] = 5; v2[3] = 8;

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), v3(5);
	v1[0] = 10; v1[1] = 9; v1[2] = 8; v1[3] = 7; v1[4] = 6;
	v2[0] = 5; v2[1] = 4; v2[2] = 3; v2[3] = 2; v2[4] = 1;
	v3[0] = 5; v3[1] = 5; v3[2] = 5; v3[3] = 5; v3[4] = 5;
	ASSERT_NO_THROW(v1 - v2);
	EXPECT_EQ(v1 - v2, v3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{

	TVector<int> v1(5), v2(7);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;
	v2[1] = 5; v2[3] = 8;

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5);

	for (int i = 0; i < 5; i++)
	{
		v1[i] = v2[i] = i;
	}
	ASSERT_NO_THROW(v1 * v2);
	EXPECT_EQ(v1 * v2, 30);
	
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(7);
	v1[0] = 7; v1[2] = 6; v1[4] = 5;
	v2[1] = 5; v2[3] = 8;
	ASSERT_ANY_THROW(v1 * v2);
}

