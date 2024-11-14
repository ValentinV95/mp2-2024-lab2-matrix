#include "tmatrix.h"

#include <gtest.h>
#include <ctime>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);
  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(10);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	TDynamicVector<int> w(v);
	EXPECT_EQ(v, w);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(10);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	TDynamicVector<int> w(v);
	for (size_t i = 0; i < sz; i++)
	{
		v[i] *= 2;
		v[i] += 1;
	}
	EXPECT_NE(v, w);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);
  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(-3) = 15);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(2 * v.size()) = 6);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(10);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	TDynamicVector<int> w(v);
	ASSERT_NO_THROW(v = v);
	EXPECT_EQ(w, v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	ASSERT_NO_THROW(w = v);
	EXPECT_EQ(v, w);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(5);
	w = v;
	EXPECT_EQ(v.size(), w.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(5);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	ASSERT_NO_THROW(w = v);
	EXPECT_EQ(v, w);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	w = v;
	ASSERT_NO_THROW(v == w);
	EXPECT_EQ(true, v == w);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(10);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	ASSERT_NO_THROW(v == v);
	EXPECT_EQ(true, v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> w(11);
	size_t sz = v.size();
	int offset = 0, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	sz = w.size();
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_NO_THROW(v == w);
	EXPECT_NE(true, v == w);
}

TEST(TDynamicVector, can_negate_vector)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 1, a = 5;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	scale = -1;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_NO_THROW(-v);
	EXPECT_EQ(w, -v);
}
TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 1, a=5;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = a;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_NO_THROW(v + a);
	EXPECT_EQ(w, v + a);
	ASSERT_NO_THROW(v += a);
	EXPECT_EQ(w, v);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 1, a = 7;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = -a;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_NO_THROW(v - a);
	EXPECT_EQ(w, v - a);
	ASSERT_NO_THROW(v -= a);
	EXPECT_EQ(w, v);
}

TEST(TDynamicVector, can_multiply_vector_by_scalar)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 1, a = 3;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	scale = a;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_NO_THROW(v * a);
	EXPECT_EQ(w, v * a);
	ASSERT_NO_THROW(v *= a);
	EXPECT_EQ(w, v);
}

TEST(TDynamicVector, can_devide_vector_by_scalar)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 3, a = 3;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	scale = 1;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_NO_THROW(v / a);
	EXPECT_EQ(w, v / a);
	ASSERT_NO_THROW(v /= a);
	EXPECT_EQ(w, v);
}

TEST(TDynamicVector, throws_when_division_by_zero_encountered)
{
	TDynamicVector<int> v(10);
	size_t sz = v.size();
	int offset = 0, scale = 1, a = 3;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	ASSERT_ANY_THROW(v / 0);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v(10), w(10), s(10);
	size_t sz = v.size();
	int offset = 1, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = -2, scale = 4;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	offset = -1, scale = 5;
	for (size_t i = 0; i < sz; i++)
		s[i] = (offset + i * scale);
	ASSERT_NO_THROW(v + w);
	EXPECT_EQ(s, v + w);
	ASSERT_NO_THROW(v += w);
	EXPECT_EQ(s, v);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(10), w(12);
	size_t sz = v.size();
	int offset = 1, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = -2, scale = 4;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_ANY_THROW(v + w);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v(10), w(10), s(10);
	size_t sz = v.size();
	int offset = 1, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = -2, scale = 4;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	offset = 3, scale = -3;
	for (size_t i = 0; i < sz; i++)
		s[i] = (offset + i * scale);
	ASSERT_NO_THROW(v - w);
	EXPECT_EQ(s, v - w);
	ASSERT_NO_THROW(v -= w);
	EXPECT_EQ(s, v);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(10), w(12);
	size_t sz = v.size();
	int offset = 1, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = -2, scale = 4;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_ANY_THROW(v - w);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v(10), w(10);
	size_t sz = v.size();
	int offset = 0, scale = 1, res=0;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = -2, scale = 2;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	for (size_t i = 0; i < sz; i++)
		res += (i * (i * 2 - 2));
	ASSERT_NO_THROW(v * w);
	EXPECT_EQ(res, v * w);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(10), w(12);
	size_t sz = v.size();
	int offset = 1, scale = 1;
	for (size_t i = 0; i < sz; i++)
		v[i] = (offset + i * scale);
	offset = -2, scale = 4;
	for (size_t i = 0; i < sz; i++)
		w[i] = (offset + i * scale);
	ASSERT_ANY_THROW(v * w);
}