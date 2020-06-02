#pragma once
#include<iostream>

template <class Type>
class Vector
{
    size_t size;
    size_t capacity;
    Type* data;

    bool needMemory();

public:
    Vector() : size(0), capacity(1), data(new Type[1]) {}
    Vector(size_t);
    ~Vector() { delete[]data; }
    Vector(const Vector<Type>&);
    Vector <Type>& operator=(const Vector<Type>&);
    typedef Type* Iterator;
    Iterator Begin() { return data; }
    Iterator End() { return data + size; }
    typedef Type* Riterator;
    Riterator Rbegin() { return data + size - 1; }
    Riterator Rend() { return data - 1; }
    Type& operator[](size_t);
    const Type& operator[](size_t) const;
    void push_back(const Type&);
    Type pop_back();
    void insert(Type, size_t);
    void erase(size_t);
    void erase(Iterator, Iterator);
    Iterator find(Iterator, Type);
    void printVector();
    size_t getSize() { return size; }
    size_t getCapacity() { return capacity; }
};
template <class Type>
void Vector<Type>::erase(size_t index)
{
    if (index >=size||index<0)
    {
        std::cout << "Wrong index.\n";
        return;
    }
   

    memcpy(Begin()+index, Begin() + index+1, sizeof(Type) * (size-index));
  --size;
}

template <class Type>
Type& Vector<Type>:: operator[](size_t index)
{
    
    if (index > size)
    {
        std::cout << "Error index";
        return;

    }
    return *(data+index);
}
template<class Type>
const Type& Vector<Type>:: operator[](size_t index)const
{
    Type temp;
    if (index > size)
    {
        std::cout << "Error index";
        return temp;

    }
    return *(data + index);
}
template <class Type>
bool Vector<Type>::needMemory()
{
    if (size + 1 <= capacity)
    {
        return false;
    }

    return true;
}

template <class Type>
void Vector<Type>::push_back(const Type& element)
{
    if (needMemory())
    {
        capacity *= 2;
        Type* temp = new Type[capacity];

        for (size_t i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }

        delete[]data;
        data = temp;
    }

    data[size++] = element;
}

template <class Type>
void Vector<Type>::printVector()
{
    for (Iterator it = Begin(); it < End(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}

template <class Type>
Type Vector<Type>::pop_back()
{
    if (size == 0)
    {
        std::cout << "Vector empty\n";
        exit(0); //return Type()
    }

    size--;
    return data[size];
}

template <class Type>
void Vector<Type>::insert(Type element, size_t index)
{
    if (index > size)
    {
        std::cout << "Error index\n";
        return;
    }

    if (index == size)
    {
        push_back(element);
    }

    if (needMemory())
    {
        capacity *= 2;


        Type* temp = new Type[capacity];

        for (size_t i = 0; i < index; i++)
        {
            temp[i] = data[i];
        }

        temp[index] = element;

        for (size_t i = index; i < size; i++)
        {
            temp[i + 1] = data[i];
        }

        delete[]data;
        data = temp;
        size++;
        return;
    }

    memcpy(Begin() + index + 1, Begin() + index, sizeof(Type) * (size - index));
    data[index] = element;
    size++;
}

template <class Type>
void Vector<Type>::erase(Iterator start, Iterator end)
{
    if (start >= End())
    {
        std::cout << "Wrong iterator.\n";
        return;
    }
    if (end > End())
        end = End() - 1;

    memcpy(start, end + 1, sizeof(Type) * (end - start));
    size -= end - start ;
}

//for (Vector<int>::Riterator i = v.Rbegin(); i > v.Rend(); i--)
//{
// std::cout << *i << " ";
//}