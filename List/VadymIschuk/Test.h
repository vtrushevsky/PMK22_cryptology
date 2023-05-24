#pragma once
#include <iostream>
#include <exception>
#include <cstring>

// Виняток для неправильного розміру масиву
class ArraySizeException : public std::exception
{
private:
    char m_msg[256];
public:
    ArraySizeException(const char* msg)
    {
        std::strncpy(m_msg, msg, 255);
        m_msg[255] = '\0';
    }

    virtual const char* what() const throw() override
    {
        return m_msg;
    }
};

// Виняток для виходу за межі масиву
class ArrayIndexException : public std::exception
{
private:
    char m_msg[256];
public:
    ArrayIndexException(const char* msg)
    {
        std::strncpy(m_msg, msg, 255);
        m_msg[255] = '\0';
    }

    virtual const char* what() const throw() override
    {
        return m_msg;
    }
};

// Виняток для невірного формату даних в файлі
class FileFormatException : public std::exception
{
private:
    char m_msg[256];
public:
    FileFormatException(const char* msg)
    {
        std::strncpy(m_msg, msg, 255);
        m_msg[255] = '\0';
    }

    virtual const char* what() const throw() override
    {
        return m_msg;
    }
};

// Виняток для відсутності файлу
class FileNotFoundException : public std::exception
{
private:
    char m_msg[256];
public:
    FileNotFoundException(const char* msg)
    {
        std::strncpy(m_msg, msg, 255);
        m_msg[255] = '\0';
    }

    virtual const char* what() const throw() override
    {
        return m_msg;
    }
};

class Array {
private:
    int* m_ptr{ nullptr };
    int m_size{ 0 };
public:
    Array() = default;

    Array(int size)
    {
        if (size <= 0)
        {
            throw ArraySizeException("Array size should be positive.");
        }

        m_ptr = new int[size];
        m_size = size;
    }

    ~Array()
    {
        delete[] m_ptr;
    }

    // Додавання елементу в масив
    void add(int value)
    {
        int* newPtr = new int[m_size + 1];
        std::memcpy(newPtr, m_ptr, m_size * sizeof(int));
        newPtr[m_size] = value;

        delete[] m_ptr;
        m_ptr = newPtr;
        ++m_size;
    }

    // Видалення елементу з масиву
    void remove(int index)
    {
        if (index < 0 || index >= m_size)
        {
            throw ArrayIndexException("Invalid index.");
        }

        int* newPtr = new int[m_size - 1];
        std::memcpy(newPtr, m_ptr, index * sizeof(int));
        std::memcpy(newPtr + index, m_ptr + index + 1, (m_size - index - 1) * sizeof(int));

        delete[] m_ptr;
        m_ptr = newPtr;
        --m_size;
    }

};


