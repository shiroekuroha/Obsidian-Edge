#ifndef GLOBAL_ARRAY_H
#define GLOBAL_ARRAY_H

template<typename T, typename S = unsigned int>
class Array
{
public:
    Array()
        : m_ptr(nullptr), m_size(0) {}

    Array(T* ptr, S size)
        : m_ptr(nullptr), m_size(0) {
            if (ptr != nullptr) {
                m_ptr = new T[size];
                m_size = size;

                for (S i = 0; i < size; i++)
                    m_ptr[i] = ptr;
            }
        }

    Array(Array<T, S>& other) {
        *this = other;
    }

    Array(Array<T, S>&& other) noexcept = delete;

    Array<T, S>& operator=(Array<T, S>& other) {
        if (*this == other) {
            return *this;
        }

        if (m_ptr != nullptr) {
            delete [] m_ptr;
            m_ptr = nullptr;
        }

        m_ptr = new T[other.m_size];
        m_size = other.m_size;

        for (S i = 0; i < m_size; i++)
            m_ptr[i] = other.m_ptr[i];

        return *this;
    }

    Array<T, S>& operator=(Array<T, S>&& other) noexcept = delete;

private:
    T* m_ptr = nullptr;
    S  m_size = 0;
};

#endif
