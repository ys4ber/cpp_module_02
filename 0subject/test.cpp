#include <iostream>

using namespace std;

class MyClass
{
     public:
        int* data;

        // Constructor
        MyClass(int value)
        {
            data = new int(value);
            cout << "Constructor called" << endl;
        }

        // Copy Constructor
        MyClass(const MyClass &other)
        {
            data = new int(*(other.data));
            cout << "Copy Constructor called" << endl;
        }

        // Copy Assignment Operator
        MyClass& operator=(const MyClass &other)
        {
            if (this != &other)
            {
                delete data;
                data = new int(*(other.data));
            }
            cout << "Copy Assignment Operator called" << endl;
            return *this;
        }

        // Destructor
        ~MyClass()
        {
            delete data;
            cout << "Destructor called" << endl;
        }
};

int main() {
    MyClass obj1(10);           // Constructor called
    MyClass obj2(obj1);         // Copy Constructor called
    MyClass obj3(20);           // Constructor called
    obj3 = obj1;                // Copy Assignment Operator called


    int* p = new int; // allocates memory for a single int
    *p = 5;
    cout << *p << endl; // Output: 5
    
    return 0;
}
