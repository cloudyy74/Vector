#pragma once

#include <iostream>
#include <cstddef>

namespace containers {
    const std::size_t init_capacity = 1;
    const std::size_t capacity_multiplier = 2;
    template<typename T>
    class my_vector {
    public:
        my_vector();
        explicit my_vector(std::size_t size);
        my_vector(const my_vector& other);
        my_vector& operator=(my_vector other);
        ~my_vector();

        std::size_t size() const;
        std::size_t capacity() const;
        bool empty() const;

        void reserve(std::size_t new_capacity);
        void resize(std::size_t new_size);

        T& operator[](std::size_t index) const;

        template<typename V>
        friend std::ostream& operator<<(std::ostream& out, const my_vector<V>& vec);

        void push_back(const T& t);
        void pop_back();
        void clear();

    private:
        std::size_t capacity_;
        std::size_t size_;
        T* array_;
    };

}

#include "my_vector_impl.hpp"

