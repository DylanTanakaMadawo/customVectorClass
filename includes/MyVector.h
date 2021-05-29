#include <iostream>

using namespace std;

// void printHello();

class MyVector
{
public:
    MyVector();
    MyVector(const MyVector &rhs);
    MyVector(int el, int value = 0);

    ~MyVector();

    void pushBack(int value);
    void popBack();

    bool Empty() const;
    int Size() const;
    int Capacity() const;

    bool operator==(const MyVector &rhs) const;
    bool operator!=(const MyVector &rhs) const;

    friend ostream &operator<<(ostream &ostr, const MyVector &rhs);

    MyVector &operator=(const MyVector &rhs);

    int &operator[](int index);
    int &At(int index);
    int &Front();
    int &Back();

    void Insert(int index, int value);
    void Erase(int index);
    void Clear();

private:
    int size;
    int capacity;
    int *array;
};