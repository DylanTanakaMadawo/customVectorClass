#include <iostream>
#include "MyVector.h"

using namespace std;

// void printHello()
// {
//     cout << "Hello World" << endl;
// }

MyVector::MyVector()
    : size(0),
      capacity(5),
      array(new int[capacity])
{
    //nothing here
}

MyVector::MyVector(const MyVector &rhs)
    : size(rhs.size),
      capacity(rhs.capacity),
      array(new int[capacity])
{
    for (int i = 0; i < rhs.Size(); ++i)
    {
        array[i] = rhs.array[i];
    }
}

MyVector::MyVector(int el, int value)
    : size(el),
      capacity(el + 5),
      array(new int[capacity])
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = value;
    }
}

MyVector::~MyVector()
{
    delete[] array;
}

void MyVector::pushBack(int value)

{
    if (size < capacity)
    {
        array[size] = value;
        ++size;
    }
    else
    {
        capacity *= 2;
        int *newarray = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            newarray[i] = array[i];
        }
        newarray[size] = value;
        ++size;
        delete[] array;
        array = newarray;
    }
}

void MyVector::popBack()
{
    if (size == 0)
    {
        throw exception();
    }
    --size;
}

bool MyVector::Empty() const
{
    return size == 0;
}

int MyVector::Size() const
{
    return size;
}

int MyVector::Capacity() const
{
    return capacity;
}

bool MyVector::operator==(const MyVector &rhs) const
{
    if (Size() != rhs.Size())
    {
        return false;
    }

    for (int i = 0; i < Size(); ++i)
    {
        if (array[i] != rhs.array[i])
        {
            return false;
        }
    }
    return true;
}

bool MyVector::operator!=(const MyVector &rhs) const
{
    return !(*this == rhs);
}

ostream &operator<<(ostream &ostr, const MyVector &rhs)
{
    for (int i = 0; i < rhs.size; ++i)
    {
        ostr << rhs.array[i] << " ";
    }

    // ostr << " || ";

    // for (int i = rhs.size; i < rhs.capacity; ++i)
    // {
    //     ostr << rhs.array[i] << " ";
    // }

    ostr << endl;

    return ostr;
}
MyVector &MyVector::operator=(const MyVector &rhs)
{
    if (rhs.size > size)
    {
        delete[] array;
        capacity = rhs.size + 5;
        array = new int[capacity];
    }
    for (int i = 0; i < rhs.Size(); ++i)
    {
        array[i] = rhs.array[i];
    }
    size = rhs.size;

    return *this;
}
int &MyVector::operator[](int index)
{
    return array[index];
}
int &MyVector::At(int index)
{
    if ((index < 0) || (index >= size))
    {
        // throw exception("index out of range!");
    }
    return array[index];
}
int &MyVector::Front()
{
    return array[0];
}
int &MyVector::Back()
{
    return array[size - 1];
}

void MyVector::Insert(int index, int value)
{
    if ((index < 0) || (index >= size))
    {
        // throw exception("Index out of range");
    }
    if (size != capacity)
    {
        for (int i = size - 1; i >= index; i++)
        {
            array[i + 1] = array[i];
        }
        array[index] = value;
        ++size;
    }
    else
    {
        capacity *= 2;
        int *newarray = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            newarray[i] = array[i];
        }

        delete[] array;
        array = newarray;
        Insert(index, value);
    }
}
void MyVector::Erase(int index)
{
    if ((index < 0) || (index >= size))
    {
        // throw exception7("Index out of range.");
    }
    for (int i = index; i < size - 1; ++i)
    {
        array[i] = array[i + 1];
    }
    --size;
}
void MyVector::Clear()
{
    size = 0;
}