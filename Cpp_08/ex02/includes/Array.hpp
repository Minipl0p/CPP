
#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T> class Array {

    private:
        T *array;
        size_t _size;

    public:
        Array(void) : array(NULL), _size(0) {};
        Array(size_t n) : array(new T[n]), _size(n) { fill(0); };
        ~Array(void) { delete[] this->array; };

        Array(const Array &src) : array(new T[src._size]), _size(src._size) {
            for (size_t i = 0; i < src._size; i++)
                array[i] = src.array[i];
        };

        Array &operator=(const Array &cpy) {
            if (this == &cpy)
				return *this;
			delete this->array;
			this->array = new T[cpy._size];
			this->_size = cpy._size;
			for (size_t i = 0; i < this->_size; i++)
				array[i] = cpy.array[i];
            return *this;
        };

        T &operator[](size_t i) {
            if (i >= this->_size)
                throw std::runtime_error("Index out of bounds !");
            return array[i];
        };

        size_t size(void) const { return this->_size; };
        void fill(int number) { for(size_t i = 0; i < this->size(); i++) array[i] = number; }

};
