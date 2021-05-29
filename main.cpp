#include <iostream>

#include "includes/MyVector.h"

using namespace std;

int main()
{
    //CREARING VECTOR
    MyVector v1;

    //PUSHING/INSERTING ELEMENTS INTO VECTOR
    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack('a');

    //COPYING ONE VECTOR INTO ANOTHER

    MyVector v2;

    // v2 = v1;

    cout << v1 << endl;

    //GET ELEMENT AT SPECIFIC INDEX
    // cout << v1.At(2);

    // cout << v1.Front();

    return 0;
}