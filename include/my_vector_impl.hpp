#pragma once 

#include "my_vector.hpp"

namespace containers {
	template <typename T>
	my_vector<T>::my_vector() {
		capacity_ = init_capacity;
		size_ = 0;
	    array_ = (T*)new char[capacity_ * sizeof(T)];
	}

	template<typename T>
	my_vector<T>::my_vector(std::size_t size) {
		capacity_ = init_capacity;
		while (capacity_ < size) {
			capacity_ *= capacity_multiplier;
		}
		size_ = size;
		array_ = (T*)new char[capacity_ * sizeof(T)];
		for (std::size_t i = 0; i < size_; ++i) {
        	new (array_ + i) T();				
		}
	}

	template<typename T>
	my_vector<T>::my_vector(const my_vector& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		array_ = (T*)new char[capacity_ * sizeof(T)];
		for (std::size_t i = 0; i < size_; ++i) {
			new (array_ + i) T(other.array_[i]);
		}
	}

	template<typename T>
	my_vector<T>& my_vector<T>::operator=(my_vector other) {
		std::swap(size_, other.size_);
		std::swap(capacity_, other.capacity_);
		std::swap(array_, other.array_);
		return *this;
	}

	template<typename T>
	my_vector<T>::~my_vector() {
		clear();
		delete [] (char*)array_;
	}

	template<typename T>
	std::size_t my_vector<T>::size() const {
		return size_;
	}

	template<typename T>
	std::size_t my_vector<T>::capacity() const {
		return capacity_;
	}

	template<typename T>
	bool my_vector<T>::empty() const {
		return size_ == 0;
	}

	template<typename T>
    void my_vector<T>::reserve(std::size_t new_capacity) {
		if (new_capacity <= capacity_) {
			return;
		}
		while (capacity_ < new_capacity) {
			capacity_ *= capacity_multiplier;
		}
		T* new_array = (T*)new char[capacity_ * sizeof(T)];
		for (std::size_t i = 0; i < size_; ++i) {
			new (new_array + i) T(array_[i]);
			array_[i].~T();
		}
		delete [] (char*)array_;
		array_ = new_array;
    }

    template<typename T>
    void my_vector<T>::resize(std::size_t new_size) {
		if (new_size <= size_)
        {
            for (std::size_t i = new_size; i < size_; ++i) {
				array_[i].~T();
			}
            size_ = new_size;
            return;
        }
		if (new_size > capacity_) {
			reserve(new_size);
		}
		for (std::size_t i = size_; i < new_size; ++i) {
			new (array_ + i) T();
		}
		size_ = new_size;
    }

	template<typename T>
    T& my_vector<T>::operator[](std::size_t index) const {
    	return array_[index];
    }

	template<typename V>
    std::ostream& operator<<(std::ostream& out, const my_vector<V>& vec) {
		for (std::size_t i = 0; i < vec.size_; ++i) {
			if (i != vec.size_ - 1) {
				out << vec.array_[i] << " ";
			}
			else {
				out << vec.array_[i];
			}
		}
		return out;
    }

    template<typename T>
    void my_vector<T>::push_back(const T& t) {
		if (size_ >= capacity_) {
			reserve(capacity_ * capacity_multiplier);
		}
		new (array_ + size_++) T(t);
    }

    template<typename T>
    void my_vector<T>::pop_back() {
		array_[--size_].~T();
    }

    template<typename T>
    void my_vector<T>::clear() {
		while (size_ != 0) {
			pop_back();
		}
    }
}
