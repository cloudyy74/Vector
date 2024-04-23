#include <cassert>
#include "my_vector.hpp"
#include "product.hpp"

template <typename T>
void test_my_vector(T a, T b) {
    containers::my_vector<T> vec;
    vec.push_back(b);
	assert(!vec.empty());
	assert(vec[0] == b);
    vec.push_back(b);
	assert(vec[1] == b);
    vec.push_back(a);
	assert(vec[2] == a);
    assert(vec.size() == 3);
    assert(!vec.empty());
    assert(vec.capacity() == 4);
    vec = vec;
    vec.pop_back();
	assert(vec.size() == 2);
    assert(vec.capacity() == 4);
    vec.pop_back();
	assert(vec.size() == 1);
    assert(vec.capacity() == 4);
    vec.pop_back();
	assert(vec.empty());
    assert(vec.capacity() == 4);
    vec.push_back(a);
	assert(vec.size() == 1);
    vec.push_back(b);
	assert(vec[1] == b);
	assert(vec.size() == 2);
    vec.push_back(a);
	assert(vec.size() == 3);
	assert(vec.capacity() == 4);
	vec.clear();
	assert(vec.empty());
	vec.reserve(17);
	assert(vec.capacity() == 32);
	vec.push_back(a);
    containers::my_vector<T> vec1 = vec;
    containers::my_vector<T> vec2(vec1);
    assert(!vec1.empty() && !vec2.empty());
    assert(vec1.capacity() == 32 && vec2.capacity() == 32);
	assert(vec[0] == a && vec2[0] == a);
}

template <typename T>
void test_my_vector_default_constructible(T a, T b) {
	containers::my_vector<T> vec_n(15);
	assert(!vec_n.empty());
	assert(vec_n.capacity() == 16);
	for (std::size_t i = 0; i < 15; ++i) {
        assert(vec_n[i] == T());
		assert(vec_n.size() == 15 - i);
		vec_n.pop_back();
	}
	assert(vec_n.capacity() == 16);
	vec_n = vec_n;
	assert(vec_n.empty());
	vec_n.resize(17);
	assert(vec_n.size() == 17);
	assert(vec_n.capacity() == 32);
	for (std::size_t i = 0; i < vec_n.size(); ++i) {
        assert(vec_n[i] == T());
		assert(vec_n.size() == 17 - i);
		vec_n.pop_back();
	}
	vec_n.reserve(1000);
	assert(vec_n.capacity() == 1024);
	vec_n.resize(2000);
	assert(vec_n.size() == 2000);
	assert(vec_n.capacity() == 2048);
	for (std::size_t i = 0; i < 2000; ++i) {
        assert(vec_n[i] == T());
		assert(vec_n.size() == 2000 - i);
		vec_n.pop_back();
	}
	assert(vec_n.empty());
}

int main() {
    test_my_vector<int>(5, 10);
    test_my_vector<int>(1, 1);
    test_my_vector<int>(0, 0);
    test_my_vector<product::Product>(product::Product("", 0, 0.0), product::Product("", 0, 0.0));
    test_my_vector<product::Product>(product::Product("qwerty", 10, 2.0), product::Product("asdfeg", -12, -6.5));
    test_my_vector<product::Product>(product::Product("asdf", 4, 12.0), product::Product("qwe", -1, 7.5));
    test_my_vector_default_constructible<int>(5, 10);
    test_my_vector_default_constructible<int>(12, 1);
    test_my_vector_default_constructible<int>(0, 0);
	return 0;
}
