// C++ program to illustrate
// Constructor overloading
#include <iostream>
using namespace std;

class construct {

public:
    float area;

    // Constructor with no parameters
    construct()
    {
        area = 0;
    }

    // Constructor with two parameters
    construct(int a, int b)
    {
        // bij o2 is dit 10 * 20;
        area = a * b;
    }

    // disp staat voor display
    void disp()
    {
        cout<< area<< endl;
    }
};

int main() {
    // Constructor Overloading
    // with two different constructors
    // of class name
    construct o;
    construct o2( 10, 20);

    // display
    o.disp();
    o2.disp();
    return 1;
}

// Source: https://www.geeksforgeeks.org/cpp/constructor-overloading-c/
